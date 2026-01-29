/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:17:11 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/29 12:08:35 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{

	try
	{
		std::cout << "===== Test 1 : Create & access =====" << std::endl;
		Array<int> numbers(5);
		std::cout << "size: " << numbers.size() << std::endl;

		for (unsigned int i = 0; i < numbers.size(); i++)
			numbers[i] = i * 10;

		std::cout << "Element 2 : " << numbers[2] << std::endl;


		std::cout << std::endl;
		std::cout << "===== Test 2 : Deep copy =====" << std::endl;
		Array<int> copy = numbers;
		copy[2] = 2;
		std::cout << "Original index 2 (doit rester 20) : " << numbers[2] << std::endl;
		std::cout << "Copie index 2 (doit etre 42) : " << copy[2] << std::endl;

		std::cout << std::endl;
		std::cout << "===== Test 3 : Hors limit =====" << std::endl;
		std::cout << numbers[10] << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}