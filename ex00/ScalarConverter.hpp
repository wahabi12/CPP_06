/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:34:01 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/17 04:41:22 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cmath>

// class ScalarConverter {
// public:
//     // Méthode statique pour la conversion
//     static void convert(const std::string& literal);

// private:
//     // Constructeur privé pour rendre la classe non instanciable
//     ScalarConverter();
//     ScalarConverter(const ScalarConverter& other);
//     ScalarConverter& operator=(const ScalarConverter& other);
//     ~ScalarConverter();
// };


#include <string>

class ScalarConverter {
public:
	// Méthode statique de conversion
	static void convert(const std::string& literal);

private:
	// Constructeur privé pour rendre la classe non instanciable
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
};
#endif
