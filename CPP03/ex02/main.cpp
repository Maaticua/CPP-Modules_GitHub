/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:02:27 by macaruan          #+#    #+#             */
/*   Updated: 2025/12/15 16:28:06 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "=== Test FragTrap ===" << std::endl;

	std::cout << "\n--- Creation ---" << std::endl;
	FragTrap frag1("Warrior");

	std::cout << "\n--- Attaque FragTrap ---" << std::endl;
	frag1.attack("Target");

	std::cout << "\n--- High Five ---" << std::endl;
	frag1.highFivesGuys();

	std::cout << "\n--- Test degats ---" << std::endl;
	frag1.takeDamage(40);
	frag1.beRepaired(15);

	std::cout << "\n--- Test epuisement energie ---" << std::endl;
	for (int i = 0; i < 100; i++)
		frag1.attack("Enemy");
	frag1.attack("Enemy");

	std::cout << "\n--- Constructeur de copie ---" << std::endl;
	FragTrap frag2(frag1);

	std::cout << "\n--- Destructeurs ---" << std::endl;
	return (0);
}
