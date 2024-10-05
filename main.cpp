/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:35:16 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/06 01:36:56 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main() {
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
