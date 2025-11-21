/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:20:58 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/21 14:33:42 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Use: ./harlFilter <level>" << std::endl;
		return 1;
	}

	std::string level = av[1];
	Harl harl;

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int levelIndex = -1;

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			levelIndex = i;
			break;
		}
	}

	switch (levelIndex)
	{
		case 0:
			harl.complain("DEBUG");
			std::cout << std::endl;
		case 1:
			harl.complain("INFO");
			std::cout << std::endl;
		case 2:
			harl.complain("WARNING");
			std::cout << std::endl;
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}
