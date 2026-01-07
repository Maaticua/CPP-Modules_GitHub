/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:12:42 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/07 12:24:32 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string name)
{
	this->type = "WrongCat";
	std::cout << "WrongCat : " << name << " constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat assignment opperator called" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow ! Miaou !" << std::endl;
}
