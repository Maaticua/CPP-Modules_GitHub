/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:16:42 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/29 15:24:22 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::cout << "===== Test 1 std::vector =====" << std::endl;
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	try
	{
		std::vector<int>::iterator it = ::easyfind(v, 30);
		std::cout << "Found him ! : " << *it << " adress " << &(*it) << std::endl;

		std::cout << "Recherche d'un nombre inexistant (50)" << std::endl;
		::easyfind(v, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "===== Test 1 std::vector =====" << std::endl;

	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	try
	{
		std::list<int>::iterator it = ::easyfind(l, 2);
		std::cout << "Found him ! : " << *it << std::endl;

		std::cout << "Recherche d'un nombre inexistant (50)" << std::endl;
		::easyfind(v, 50);

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << '\n';
	}

	return 0;
}