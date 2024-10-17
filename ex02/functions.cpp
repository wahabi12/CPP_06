/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:59:15 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/17 04:46:11 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void) {
	std::srand(std::time(0));
	int random = std::rand() % 3;

	switch (random) {
		case 0:
			std::cout << "Generated: A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated: B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated: C" << std::endl;
			return new C();
	}
	return nullptr;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
		return;
	} catch (std::bad_cast& e) { }

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Type: B" << std::endl;
		return;
	} catch (std::bad_cast& e) { }

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Type: C" << std::endl;
		return;
	} catch (std::bad_cast& e) {
		std::cout << "Unknown type" << std::endl;
	}
}
