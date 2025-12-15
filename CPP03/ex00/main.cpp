/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:02:27 by macaruan          #+#    #+#             */
/*   Updated: 2025/12/15 11:49:17 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "=== Creation des ClapTraps ===" << std::endl;
	ClapTrap clap1(" Robot1");
	ClapTrap clap2(" Robot2");

	std::cout << "\n=== Test des attaques ===" << std::endl;
	clap1.attack("Robot2");
	clap2.takeDamage(0);

	std::cout << "\n=== Test de reparation ===" << std::endl;
	clap1.beRepaired(5);

	std::cout << "\n=== Test epuisement energie ===" << std::endl;
	for (int i = 0; i < 9; i++)
		clap1.attack("target");
	clap1.attack("target");

	std::cout << "\n=== Test degats mortels ===" << std::endl;
	clap2.takeDamage(15);
	clap2.attack("Robot1");
	clap2.beRepaired(5);

	std::cout << "\n=== Test constructeur de copie ===" << std::endl;
	ClapTrap clap3(clap1);

	std::cout << "\n=== Test operateur d'affectation ===" << std::endl;
	ClapTrap clap4(" Robot4");
	clap4 = clap2;

	std::cout << "\n=== Fin du programme (destructeurs) ===" << std::endl;
	return (0);
}
