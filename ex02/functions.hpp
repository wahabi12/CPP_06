/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 02:05:28 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/06 02:05:34 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Base.hpp"

// Fonction qui génère aléatoirement un objet de type A, B ou C et retourne un pointeur vers Base
Base* generate(void);

// Identifie le type réel de l'objet pointé par le pointeur p
void identify(Base* p);

// Identifie le type réel de l'objet référencé par p
void identify(Base& p);

#endif
