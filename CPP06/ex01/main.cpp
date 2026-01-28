/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:24:22 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/28 14:11:07 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data myData;
	myData.id = 42;
	myData.content = "Student";

	std::cout << "Adresse d'origine : " << &myData << std::endl;

	uintptr_t raw = Serializer::serialize(&myData);
	std::cout << "Valeur serialisee : " << raw << std::endl;

	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Adresse apres deserialisation : " << ptr << std::endl;

	if (ptr == &myData)
	{
		std::cout << "Succes : Adresse identique !" << std::endl;
		std::cout << "Data : ID= " << ptr->id << ", name= " << ptr->content << std::endl;
	}
	else
		std::cout << "Erreur :: L'adresse a changer." << std::endl;

	return 0;

}