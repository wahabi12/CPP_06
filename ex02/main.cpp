/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:55:51 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/06 01:58:48 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "functions.hpp"
#include <iostream>

int main() {
    // Génération d'un objet aléatoire
    Base* base = generate();

    // Identification avec un pointeur
    std::cout << "Identification by pointer:" << std::endl;
    identify(base);

    // Identification avec une référence
    std::cout << "Identification by reference:" << std::endl;
    identify(*base);

    // Nettoyage de la mémoire
    delete base;

    return 0;
}
