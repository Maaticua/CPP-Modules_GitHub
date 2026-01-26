/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:39:12 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/26 12:29:11 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"


Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

static AForm* createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}
AForm* Intern::makeForm(std::string forName, std::string target)
{
	std::string formType[3] = {"ShrubberyCreation" , "RobotomyRequest", "PresidentialPardon"}; // * Tab des noms des forms
	AForm* (*formCreators[3])(std::string) = {&createShrubbery, &createRobotomy, &createPresidential}; // * Tab de * sur fonction

	for (int i = 0; i < 3; i++)
	{
		if (forName == formType[i])
		{
			std::cout << "Intern creates " << forName << std::endl;
			return formCreators[i](target);
		}
	}

	std::cerr << "Error: Form type \"" << forName << "\" does not exist !" << std::endl;
	return NULL;
}