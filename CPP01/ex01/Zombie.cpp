/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:42:52 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/20 17:03:26 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "";
	std::cout << "Zombie créé" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << name << " créé" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << name << " detruit" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
