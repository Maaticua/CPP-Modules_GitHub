/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:33:09 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/26 11:29:09 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:33:09 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/23 16:13:00 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
	try
	{
		Bureaucrat B1("B1", 137);
		ShrubberyCreationForm S1("House");
		std::cout << S1 << std::endl;
		B1.signForm(S1);
		B1.executeForm(S1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 2: ShrubberyCreationForm GradeLow ===" << std::endl;
	try
	{
		Bureaucrat B2("B2", 140);
		ShrubberyCreationForm S2("Garden");
		B2.signForm(S2);
		B2.executeForm(S2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 3: ShrubberyCreationForm try exec but form not signed ===" << std::endl;
	try
	{
		Bureaucrat B3("B3", 1);
		ShrubberyCreationForm S3("Park");

		B3.executeForm(S3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 4: RobotomyRequestForm ===" << std::endl;
	try
	{
		Bureaucrat B4("B4", 45);
		RobotomyRequestForm R1("Bender");

		std::cout << R1 << std::endl;
		B4.signForm(R1);
		B4.executeForm(R1);
		std::cout << std::endl;
		B4.executeForm(R1);
		std::cout << std::endl;
		B4.executeForm(R1);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 5: RobotomyRequestForm GradeLow ===" << std::endl;
	try
	{
		Bureaucrat B5("B5", 50);
		RobotomyRequestForm R2("R2D2");

		B5.signForm(R2);
		B5.executeForm(R2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 6: PresidentialPardonForm ===" << std::endl;
	try
	{
		Bureaucrat B6("Macron", 5);
		PresidentialPardonForm pardon("For sure");

		std::cout << pardon << std::endl;
		B6.signForm(pardon);
		B6.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 7: PresidentialPardonForm GradeLow ===" << std::endl;
	try
	{
		Bureaucrat B7("Trump", 25);
		PresidentialPardonForm pardon("July 6th");

		B7.signForm(pardon);
		B7.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 8: All Form avec un SuperBureaucrate ===" << std::endl;
	try
	{
		Bureaucrat B8("BigBoss", 1);
		ShrubberyCreationForm S("office");
		RobotomyRequestForm R("employee");
		PresidentialPardonForm P("Stagiaire");

		B8.signForm(S);
		B8.executeForm(S);

		std::cout << std::endl;
		B8.signForm(R);
		B8.executeForm(R);

		std::cout << std::endl;
		B8.signForm(P);
		B8.executeForm(P);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}