/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:56:46 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/21 11:30:43 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon sword = Weapon("Musashi Miyamoto's katana");
	HumanA rick("Rick", sword);
	rick.attack();
	sword.setType("Musashi Miyamoto's katana");
	rick.attack();
	std::cout << std::endl;

	Weapon lucille = Weapon("bat Lucille");
	HumanB negan("Negan");
	negan.setWeapon(lucille);
	negan.attack();
	lucille.setType("same old Lucille");
	negan.attack();
	std::cout << std::endl;

	HumanB steve("Steve");
	steve.attack();

	return 0;
}
