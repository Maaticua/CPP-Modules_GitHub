/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 10:24:08 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/07 14:31:43 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << " --- Test avec animal de base --- " << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\n --- Types --- " << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;

	std::cout << "\n --- Sons ---" << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();

	std::cout << "\n --- Destruction --- " << std::endl;
	delete meta;
	delete dog;
	delete cat;

	std::cout << "\n --- test WrongAnimal ---" << std::endl;
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << "\nCat type : " << wrongCat->getType() << std::endl;

	std::cout << "\n --- test MakeSound with Wrong ---" << std::endl;
	wrongMeta->makeSound();
	wrongCat->makeSound();

	std::cout << "\n --- Destruction Wrong ---" << std::endl;
	delete wrongCat;
	delete wrongMeta;

	std::cout << "\n --- Test contructeur de copie ---" << std::endl;
	Dog originalDog;
	Dog copieDog(originalDog);

	std::cout << "\n --- test operateur d'affectation ---" << std::endl;
	Cat cat1;
	Cat cat2;
	cat2 = cat1;

	std::cout << "\n --- Destructor ---";
	std::cout << std::endl;

	return 0;
}
