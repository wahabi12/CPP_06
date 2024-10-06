/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:50:41 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/06 01:54:30 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    // Création d'un objet Data
    Data originalData;
    originalData.name = "John Doe";
    originalData.age = 30;
    originalData.height = 1.75f;

    // Affichage des données de l'objet original
    std::cout << "Original Data:" << std::endl;
    std::cout << "Name: " << originalData.name << std::endl;
    std::cout << "Age: " << originalData.age << std::endl;
    std::cout << "Height: " << originalData.height << std::endl;

    // Sérialisation du pointeur vers originalData
    uintptr_t raw = Serializer::serialize(&originalData);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    // Désérialisation du uintptr_t en pointeur Data
    Data* deserializedData = Serializer::deserialize(raw);

    // Vérification que le pointeur après désérialisation correspond à l'original
    if (deserializedData == &originalData) {
        std::cout << "Deserialization successful: Pointers match!" << std::endl;
    } else {
        std::cout << "Deserialization failed: Pointers do not match!" << std::endl;
    }

    // Affichage des données après désérialisation pour vérifier l'intégrité
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Name: " << deserializedData->name << std::endl;
    std::cout << "Age: " << deserializedData->age << std::endl;
    std::cout << "Height: " << deserializedData->height << std::endl;

    return 0;
}
