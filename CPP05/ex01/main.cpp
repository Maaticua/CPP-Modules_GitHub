/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:49 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/22 16:17:45 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test 1: Creation de formulaires valides ===" << std::endl;
	try
	{
		Form f1("Tax Form", 50, 25);
		std::cout << f1 << std::endl;

		Form f2("Medical Form", 100, 75);
		std::cout << f2 << std::endl;

		Form f3("Top Secret", 1, 1);
		std::cout << f3 << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 2: Creation de formulaire trop haut lvl ===" << std::endl;
	try
	{
		Form fi1("Too high", 0, 50);
		std::cout << fi1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught " << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 3: Creation de formulaire trop bas lvl ===" << std::endl;
	try
	{
		Form fi2("Too low", 50, 151);
		std::cout << fi2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught " << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 4: Bureaucrate good grade sign Form ===" << std::endl;
	try
	{
		Bureaucrat B1("B1", 30);
		Form form("request form", 50, 25);

		std::cout << "Avant signature: " << form << std::endl;
		B1.signForm(form);
		std::cout << "Apres signature: " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 5: Bureaucrate bad grade sign Form ===" << std::endl;
	try
	{
		Bureaucrat B2("B2", 100);
		Form form("Important Document", 50, 25);

		std::cout << "Avant signature: " << form << std::endl;
		B2.signForm(form);
		std::cout << "Apres signature: " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 6: Bureaucrate limit grade sign Form ===" << std::endl;
	try
	{
		Bureaucrat B3("B3", 50);
		Form form("Bulletin ", 50, 25);

		std::cout << "Avant signature: " << form << std::endl;
		B3.signForm(form);
		std::cout << "Apres signature: " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << std::endl;
	std::cout << "=== Test 7: Formulaire deja signer ===" << std::endl;
	try
	{
		Bureaucrat Boss("Boss", 1);
		Form form("Bulletin ", 10, 5);

		Boss.signForm(form);
		std::cout << "Tentative de signature a nouveau " << form << std::endl;
		Boss.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 8: plusieurs bureaucrates, un forulaire ===" << std::endl;
	try
	{
		Bureaucrat B4("B4", 120);
		Bureaucrat B5("B5", 20);
		Form form("Complex from ", 50, 30);

		std::cout << form << std::endl;
		B4.signForm(form);
		B5.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}