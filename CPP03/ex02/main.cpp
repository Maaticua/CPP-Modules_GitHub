/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:02:27 by macaruan          #+#    #+#             */
/*   Updated: 2025/12/15 15:53:47 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "=== Test ScavTrap ===" << std::endl;
	std::cout << "\n--- Creation ---" << std::endl;
	ScavTrap scav1("Guardian");

	std::cout << "\n--- Attaque ScavTrap ---" << std::endl;
	scav1.attack("Enemy");

	std::cout << "\n--- Mode Gate keeper ---" << std::endl;
	scav1.guardGate();

	std::cout << "\n--- Test degats ---" << std::endl;
	scav1.takeDamage(50);
	scav1.beRepaired(20);

	std::cout << "\n--- Constructeur de copie ---" << std::endl;
	ScavTrap scav2(scav1);

	std::cout << "\n--- Destructeurs ---" << std::endl;

	return (0);
}
