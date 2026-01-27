/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1016/01/13 10:33:09 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/26 16:07:06 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1016/01/13 10:33:09 by macaruan          #+#    #+#             */
/*   Updated: 1016/01/13 16:13:00 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	std::cout << "=== Test 1: Intern cree un ShrubberyCreationForm ===" << std::endl;
	try
	{
		Intern I1;
		AForm* F1;

		F1 = I1.makeForm("shrubbery creation", "home");
		if (F1)
		{
			std::cout << *F1 << std::endl;

			Bureaucrat B1("B1", 137);
			B1.signForm(*F1);
			B1.executeForm(*F1);

			delete F1;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 2: Intern cree un RobotomyRequestForm ===" << std::endl;
	try
	{
		Intern I2;
		AForm* F2;

		F2 = I2.makeForm("robotomy request", "Bender");
		if (F2)
		{
			std::cout << *F2 << std::endl;

			Bureaucrat B2("B2", 45);
			B2.signForm(*F2);
			B2.executeForm(*F2);

			delete F2;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 3: Intern cree un PresidentialPardonForm ===" << std::endl;
	try
	{
		Intern I3;
		AForm* F3;

		F3 = I3.makeForm("presidential pardon", "Macron");
		if (F3)
		{
			std::cout << *F3 << std::endl;

			Bureaucrat B3("B3", 5);
			B3.signForm(*F3);
			B3.executeForm(*F3);

			delete F3;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 4: Intern cree un form inexsistant ===" << std::endl;
	try
	{
		Intern I4;
		AForm* F4;

		F4 = I4.makeForm("Tea", "Kitchen");
		if (F4)
		{
			std::cout << *F4 << std::endl;
			delete F4;
		}
		else
		{
			std::cout << "Form creation failed, return NULL" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 5: Intern cree avec nom incorrect ===" << std::endl;
	try
	{
		Intern I5;
		AForm* F5;

		F5 = I5.makeForm("shrubbery", "garden");
		if (F5)
		{
			std::cout << *F5 << std::endl;
			delete F5;
		}
		else
		{
			std::cout << "Form creation failed, returned NULL" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 6: Plusieurs formulaires meme intern ===" << std::endl;
	try
	{
		Intern I6;
		AForm* F6;
		AForm* F7;
		AForm* F8;

		F6 = I6.makeForm("shrubbery creation", "office");
		F7 = I6.makeForm("robotomy request", "Employee");
		F8 = I6.makeForm("presidential pardon", "Intern");

		Bureaucrat Boss("Boss", 1);
		if (F6)
		{
			Boss.signForm(*F6);
			Boss.executeForm(*F6);
			delete F6;
		}
		std::cout << std::endl;
		if (F7)
		{
			Boss.signForm(*F7);
			Boss.executeForm(*F7);
			delete F7;
		}
		std::cout << std::endl;
		if (F8)
		{
			Boss.signForm(*F8);
			Boss.executeForm(*F8);
			delete F8;
		}
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 7: Test constructeur copie et op d'affectation ===" << std::endl;
	try
	{
		Intern I7;
		Intern I8(I7);
		Intern I9;

		I9 = I8;
		AForm* F9 = I9.makeForm("robotomy request", "C3PO");
		if (F9)
		{
			std::cout << *F9 << std::endl;
			delete F9;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== Test 8: Exemple du sujet ===" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			std::cout << *rrf << std::endl;

			Bureaucrat b("Bureaucrat", 1);
			b.signForm(*rrf);
			b.executeForm(*rrf);

			delete rrf;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}