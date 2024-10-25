/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:50:41 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/25 20:52:54 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
	Data originalData;
	originalData.name = "John Doe";
	originalData.age = 30;
	originalData.height = 1.75f;

	std::cout << "Original Data:" << std::endl;
	std::cout << "Name: " << originalData.name << std::endl;
	std::cout << "Age: " << originalData.age << std::endl;
	std::cout << "Height: " << originalData.height << std::endl;
	
	uintptr_t raw = Serializer::serialize(&originalData);
	std::cout << "Serialized uintptr_t: " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);

	if (deserializedData == &originalData) {
		std::cout << "Deserialization successful: Pointers match!" << std::endl;
	} else {
		std::cout << "Deserialization failed: Pointers do not match!" << std::endl;
	}

	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "Name: " << deserializedData->name << std::endl;
	std::cout << "Age: " << deserializedData->age << std::endl;
	std::cout << "Height: " << deserializedData->height << std::endl;

	return 0;
}
