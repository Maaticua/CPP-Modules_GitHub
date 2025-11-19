/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:11:31 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/18 14:11:50 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;
	while (1)
	{
		std::cout << "Entrez une commande (ADD, SEARCH, EXIT): ";
		std::cin >> command;

		if (std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}
		
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			continue;
		}

		if (command == "ADD")
			phonebook.AddContact();
		else if (command == "SEARCH")
			phonebook.SearchContact();
		else if (command == "EXIT")
			break;
	}
	return (0);
}
