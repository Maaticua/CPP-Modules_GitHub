/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:01 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/05 15:11:32 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include "Colors.hpp"

int main()
{
	std::cout << GREEN << "=== Test 1 : Subject test ===" << RESET << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << YELLOW << "Shortest : " << RESET << sp.shortestSpan() << std::endl;
		std::cout << YELLOW << "Longest : " << RESET << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << GREEN << "=== Test 2 : Additional test ===" << RESET << std::endl;
	try
	{
		Span sp = Span(17);
		sp.addNumber(43);
		sp.addNumber(5);
		sp.addNumber(20);
		sp.addNumber(1);
		sp.addNumber(116);
		std::cout << YELLOW << "Shortest : " << RESET << sp.shortestSpan() << std::endl;
		std::cout << YELLOW << "Longest : " << RESET << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << GREEN << "=== Test 3 : BIG test ===" << RESET << std::endl;
	try
	{
		Span bigsp(10000);
		std::vector<int> v;
		for (int i = 0; i < 10000; i++)
			v.push_back(i*2);
		bigsp.addRange(v.begin(), v.end());
		std::cout << YELLOW << "Shortest : " << RESET << bigsp.shortestSpan() << std::endl;
		std::cout << YELLOW << "Longest : " << RESET << bigsp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;

}