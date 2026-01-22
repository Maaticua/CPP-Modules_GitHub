/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:49 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/22 13:45:43 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test 1: Creation de bureaucrates valide ===" << std::endl;
	try
	{
		Bureaucrat B1("B1", 1);
		std::cout << B1 << std::endl;

		Bureaucrat B2("B2", 75);
		std::cout << B2 << std::endl;

		Bureaucrat B3("B3", 150);
		std::cout << B3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception" << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 2: Creation de bureaucrates TooBig ===" << std::endl;
	try
	{
		Bureaucrat IB1("TooHighBureaucrat", 0);
		std::cout << IB1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 3: Creation de bureaucrates TooLow ===" << std::endl;
	try
	{
		Bureaucrat IB2("TooLowBureaucrat", 151);
		std::cout << IB2 << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 4: Incrementation du grade jusqu'a l'echec ===" << std::endl;
	try
	{
		Bureaucrat B4("B4", 3);
		std::cout << "Avant: " << B4 << std::endl;
		B4.incrementGrade();
		std::cout << "Apres incrementation: " << B4 << std::endl;
		B4.incrementGrade();
		std::cout << "Apres incrementation: " << B4 << std::endl;
		B4.incrementGrade();
		std::cout << "Apres incrementation: " << B4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}


	std::cout << std::endl;
	std::cout << "=== Test 5: Decrementation du grade jusqu'a l'echec ===" << std::endl;
	try
	{
		Bureaucrat B5("B5", 148);
		std::cout << "Avant: " << B5 << std::endl;
		B5.decrementGrade();
		std::cout << "Apres decrementation: " << B5 << std::endl;
		B5.decrementGrade();
		std::cout << "Apres decrementation: " << B5 << std::endl;
		B5.decrementGrade();
		std::cout << "Apres decrementation: " << B5 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "=== Test 6: Constructeur de copie ===" << std::endl;
	try
	{
		Bureaucrat Original("Original", 42);
		Bureaucrat Copy(Original);
		std::cout << "Original: " << Original  << std::endl;
		std::cout << "Copy: " << Copy << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << std::endl;
	std::cout << "=== Test 7: Operateur d'affectation ===" << std::endl;
	try
	{
		Bureaucrat First("First", 10);
		Bureaucrat Second("Second", 100);
		std::cout << "Avant affectation First = " << First << std::endl;
		std::cout << "Avant affectation Second = " << Second << std::endl;
		Second = First;
		std::cout << std::endl;
		std::cout << "Apres affectation Second = " << Second << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}