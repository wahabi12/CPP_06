/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:55:51 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/17 04:46:46 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "functions.hpp"
#include <iostream>

int main() {
	Base* base = generate();

	std::cout << "Identification by pointer:" << std::endl;
	identify(base);
	std::cout << "Identification by reference:" << std::endl;
	identify(*base);
	delete base;
	return 0;
}
