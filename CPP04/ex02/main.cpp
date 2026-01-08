/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 10:24:08 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/08 11:22:01 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "=== Test tableau d'animaux ===" << std::endl;
	const int N = 4;
	Animal* animals[N];

	// 1er moitié Dog, 2eme moitié Cat
	for (int i = 0; i < N/2; i++)
		animals[i] = new Dog();
	for (int i = N/2; i < N; i++)
		animals[i] = new Cat();

	std::cout << "\n=== Test Makesound ===" << std::endl;
	for (int i = 0; i < N; i++)
		animals[i]->makeSound();

	std::cout << "\n=== Destructor ===" << std::endl;
	for (int i = 0; i < N; i++)
		delete animals[i];

	std::cout << "\n=== Test deep copy ===" << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	}

	return 0;
}
