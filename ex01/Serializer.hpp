/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:51:09 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/06 01:53:46 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint>

class Serializer {
public:
    // Méthode statique pour sérialiser un pointeur Data en uintptr_t
    static uintptr_t serialize(Data* ptr);

    // Méthode statique pour désérialiser un uintptr_t en pointeur Data
    static Data* deserialize(uintptr_t raw);

private:
    // Constructeur privé pour rendre la classe non instanciable
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
};

#endif
