/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:02:27 by macaruan          #+#    #+#             */
/*   Updated: 2025/12/16 16:22:44 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "=== Test DiamondTrap ===" << std::endl;

	std::cout << "\n--- Creation ---" << std::endl;
	DiamondTrap diamond1("Ruby");

	std::cout << "\n--- Attaque DiamondTrap ---" << std::endl;
	diamond1.attack("Target");

	std::cout << "\n--- Test degats ---" << std::endl;
	diamond1.takeDamage(40);
	diamond1.beRepaired(15);

	std::cout << "\n--- Test epuisement energie ---" << std::endl;
	for (int i = 0; i < 100; i++)
		diamond1.attack("Enemy");
	diamond1.attack("Enemy");

	std::cout << "\n--- Constructeur de copie ---" << std::endl;
	DiamondTrap frag2(diamond1);

	std::cout << "\n--- Test WhoAmI ---" << std::endl;
	diamond1.whoAmI();

	std::cout << "\n--- Destructeurs ---" << std::endl;
	return (0);
}
