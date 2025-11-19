/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:24:26 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/17 18:02:17 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	count = 0;
	oldindex = 0;
}

std::string truncate(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}
void PhoneBook::AddContact()
{
	Contact newContact;
	std::string input;

	std::cout << "Firstname : ";
	std::cin >> input;
	newContact.setfirstname(input);
	std::cout << "Lastname : ";
	std::cin >> input;
	newContact.setlastname(input);
	std::cout << "Nickname : ";
	std::cin >> input;
	newContact.setnickname(input);
	std::cout << "Phonenumber : ";
	std::cin >> input;
	newContact.setphonenumber(input);
	std::cout << "Darkest secret : ";
	std::cin >> input;
	newContact.setdarkestsecret(input);

	if (count < 8)
	{
		contacts[count] = newContact;
		count++;
	}
	else
	{
		contacts[oldindex] = newContact;
		oldindex = (oldindex + 1) % 8;
	}
}

void PhoneBook::SearchContact()
{
	if (count == 0)
	{
		std::cout << "Aucun contact enrengistré." << std::endl;
		return;
	}

	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << truncate(contacts[i].getfirstname()) << "|";
		std::cout << std::setw(10) << std::right << truncate(contacts[i].getlastname()) << "|";
		std::cout << std::setw(10) << std::right << truncate(contacts[i].getnickname()) << std::endl;
	}

	int index;
	std::cout << "Entrez un index: ";
	std::cin >> index;

	if (std::cin.fail())
	{
		std::cout << "Erreur: index invalide!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	
	if (index >= 0 && index < count)
	{
		std::cout << "Firstname: " << contacts[index].getfirstname() << std::endl;
		std::cout << "Lastname: " << contacts[index].getlastname() << std::endl;
		std::cout << "Nickname: " << contacts[index].getnickname() << std::endl;
		std::cout << "Phonenumber: " << contacts[index].getphonenumber() << std::endl;
		std::cout << "Darkest secret: " << contacts[index].getdarkestsecret() << std::endl;
	}
	else
		std::cout << "Index invalide!" << std::endl;
}
