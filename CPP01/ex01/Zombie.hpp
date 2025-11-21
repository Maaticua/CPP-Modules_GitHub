/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:42:44 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/20 16:49:30 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP


#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name;

public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);
	void setName(std::string name);
};

Zombie* zombieHorde(int n, std::string name);

#endif
