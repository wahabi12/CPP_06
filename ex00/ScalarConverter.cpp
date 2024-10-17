/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:34:40 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/17 04:41:12 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isPseudoLiteral(const std::string& literal) {
	return (literal == "nan" || literal == "nanf" ||
			literal == "+inf" || literal == "-inf" ||
			literal == "+inff" || literal == "-inff");
}

// Vérifie si la chaîne représente un int
bool isInt(const std::string& literal) {
	char* endptr;
	errno = 0;
	long value = std::strtol(literal.c_str(), &endptr, 10);
	if (*endptr != '\0' || errno == ERANGE || value < INT_MIN || value > INT_MAX) {
		return false;
	}
	return true;
}

// Conversion en char
void printChar(double value) {
	if (std::isnan(value) || value < CHAR_MIN || value > CHAR_MAX) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(static_cast<char>(value))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
}

// Conversion en int
void printInt(double value) {
	if (std::isnan(value) || value < INT_MIN || value > INT_MAX) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

// Conversion en float
void printFloat(double value) {
	float f = static_cast<float>(value);
	if (std::isnan(f) || std::isinf(f)) {
		std::cout << "float: " << f << "f" << std::endl;
	} else {
		std::cout << std::fixed;   // Affichage fixe (sans scientifique)
		std::cout.precision(1);    // Limitation à une décimale
		std::cout << "float: " << f << "f" << std::endl;
	}
}

// Conversion en double
void printDouble(double value) {
	if (std::isnan(value) || std::isinf(value)) {
		std::cout << "double: " << value << std::endl;
	} else {
		std::cout << std::fixed;   // Affichage fixe
		std::cout.precision(1);    // Limitation à une décimale
		std::cout << "double: " << value << std::endl;
	}
}

// Convertit le littéral en différents types scalaires
void ScalarConverter::convert(const std::string& literal) {
	double value;

	if (isPseudoLiteral(literal)) {
		if (literal == "nan" || literal == "nanf") {
			value = std::numeric_limits<double>::quiet_NaN();
		} else if (literal == "+inf" || literal == "+inff") {
			value = std::numeric_limits<double>::infinity();
		} else {
			value = -std::numeric_limits<double>::infinity();
		}

		printChar(value);
		printInt(value);
		printFloat(value);
		printDouble(value);
		return;
	}

	char* endptr;
	errno = 0;
	value = std::strtod(literal.c_str(), &endptr);

	// Si la conversion a échoué
	if (*endptr != '\0' || errno == ERANGE) {
		std::cout << "Error: invalid literal" << std::endl;
		return;
	}

	// Affichage des conversions
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}