/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:16:42 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/05 11:12:36 by macaruan         ###   ########.fr       */
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
		std::cout << "Found him ! : " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "===== Test 2 std::list =====" << std::endl;

	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	try
	{
		std::list<int>::iterator it = ::easyfind(l, 2);
		std::cout << "Found him ! : " << *it << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << '\n';
	}


		std::cout << std::endl;
	std::cout << "===== Test 3 std::list : not found =====" << std::endl;

	std::list<int> k;
	k.push_back(1);
	k.push_back(2);
	k.push_back(3);

	try
	{
		std::list<int>::iterator it = ::easyfind(k, 10);
		std::cout << "Found him ! : " << *it << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << '\n';
	}
	return 0;
}