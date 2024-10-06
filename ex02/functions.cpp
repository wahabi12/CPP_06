/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:59:15 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/06 01:59:47 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>  // Pour rand() et srand()
#include <ctime>    // Pour time()
#include <iostream>

// Génère aléatoirement un objet de type A, B ou C et retourne un pointeur de type Base*
Base* generate(void) {
    std::srand(std::time(0));  // Initialise le générateur de nombres aléatoires
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

// Identifie le type de l'objet pointé par le pointeur p
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

// Identifie le type de l'objet référencé par la référence p
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);  // Si ça réussit, c'est un A
        std::cout << "Type: A" << std::endl;
        return;
    } catch (std::bad_cast& e) { }

    try {
        (void)dynamic_cast<B&>(p);  // Si ça réussit, c'est un B
        std::cout << "Type: B" << std::endl;
        return;
    } catch (std::bad_cast& e) { }

    try {
        (void)dynamic_cast<C&>(p);  // Si ça réussit, c'est un C
        std::cout << "Type: C" << std::endl;
        return;
    } catch (std::bad_cast& e) {
        std::cout << "Unknown type" << std::endl;
    }
}
