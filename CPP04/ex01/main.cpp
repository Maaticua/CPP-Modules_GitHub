/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 10:24:08 by macaruan          #+#    #+#             */
/*   Updated: 2025/12/29 10:19:10 by macaruan         ###   ########.fr       */
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

	// Moitié Dog, moitié Cat
	for (int i = 0; i < N/2; i++)
		animals[i] = new Dog();
	for (int i = N/2; i < N; i++)
		animals[i] = new Cat();

	// Utilisation
	for (int i = 0; i < N; i++)
		animals[i]->makeSound();

	// Destruction
	for (int i = 0; i < N; i++)
		delete animals[i];

	std::cout << "\n=== Test deep copy ===" << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	}

	return 0;
}
