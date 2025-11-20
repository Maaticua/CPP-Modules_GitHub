/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:11:16 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/20 16:33:50 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{
	Zombie* heapZombie = newZombie("heapZombie");
	heapZombie->announce();
	delete heapZombie;

	randomChump("StackZombie");

	return (0);
}
