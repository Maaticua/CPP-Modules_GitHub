/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:34 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/28 16:18:24 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(T const & x)
{
	std::cout << x << " ";
}

void increment(int & n)
{
	n++;
}

int main()
{
	int tab[] = {0, 1, 2, 3, 4};
	std::cout << "Tableau initial : ";
	::iter(tab, 5, printElement<int>);
	std::cout << std::endl;

	::iter(tab, 5, increment);
	std::cout << "Apres ++ : ";
	::iter(tab, 5, printElement<int>);
	std::cout << std::endl;

	std::string strings[] = {"Hello", "42", "World"};
	std::cout << "Strings : ";
	::iter(strings, 3, printElement<std::string>);

	return 0;
}