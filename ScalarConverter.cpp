/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:34:40 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/06 01:36:49 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


// Détection des pseudo-littéraux pour float et double
bool isPseudoLiteral(const std::string& literal) {
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "-inf" ||
            literal == "+inff" || literal == "-inff");
}

// Conversion et affichage en char
void printChar(double value) {
    if (value < CHAR_MIN || value > CHAR_MAX || std::isnan(value)) {
        std::cout << "char: impossible" << std::endl;
    } else {
        char c = static_cast<char>(value);
        if (std::isprint(c)) {
            std::cout << "char: '" << c << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
    }
}

// Conversion et affichage en int
void printInt(double value) {
    if (value < INT_MIN || value > INT_MAX || std::isnan(value)) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

// Conversion et affichage en float
void printFloat(double value) {
    if (isPseudoLiteral(std::to_string(value))) {
        std::cout << "float: " << value << "f" << std::endl;
    } else {
        float f = static_cast<float>(value);
        std::cout << "float: " << f << "f" << std::endl;
    }
}

// Conversion et affichage en double
void printDouble(double value) {
    if (isPseudoLiteral(std::to_string(value))) {
        std::cout << "double: " << value << std::endl;
    } else {
        std::cout << "double: " << value << std::endl;
    }
}

// Convertit le littéral en différents types scalaires
void ScalarConverter::convert(const std::string& literal) {
    char* endptr = nullptr;

    // Gestion des pseudo-littéraux
    if (isPseudoLiteral(literal)) {
        double pseudoValue = std::strtod(literal.c_str(), nullptr);
        printChar(pseudoValue);
        printInt(pseudoValue);
        printFloat(pseudoValue);
        printDouble(pseudoValue);
        return;
    }

    // Conversion en double
    errno = 0;
    double value = std::strtod(literal.c_str(), &endptr);

    // Vérification si la conversion a échoué
    if (errno != 0 || *endptr != '\0') {
        std::cout << "Error: invalid literal" << std::endl;
        return;
    }

    // Affichage des conversions
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
