/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:42:49 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/20 16:57:09 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int n = 5;
	Zombie* horde = zombieHorde(n, "HordeZombie");

	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}
