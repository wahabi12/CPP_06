/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:35:16 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/17 04:40:13 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

/* int main() {
	ScalarConverter::convert("42");
	std::cout << "----" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "----" << std::endl;
	ScalarConverter::convert("42.42f");
	std::cout << "----" << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << "----" << std::endl;
	ScalarConverter::convert("a");
	std::cout << "----" << std::endl;
	ScalarConverter::convert("invalid");
	return 0;
}
 */

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);
	return 0;
}
