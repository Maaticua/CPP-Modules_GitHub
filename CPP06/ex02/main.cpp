/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:31:09 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/28 15:45:46 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
int main()
{
	Base* ptr = generate();

	std::cout << "Identification par * : ";
	identify(ptr);

	std::cout << "Identification par & : ";
	identify(*ptr);

	delete ptr;
	return 0;
}