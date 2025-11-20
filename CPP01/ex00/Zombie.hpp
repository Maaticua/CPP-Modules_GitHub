/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:11:34 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/20 15:30:48 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#  define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{

private:
	std::string name;

public:
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
