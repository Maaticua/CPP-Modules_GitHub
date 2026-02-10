/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:52:52 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/10 10:43:17 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{


	char a = '2';
	char b = '3';

	std::cout << "Before Swap Char: " << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "After Swap char : " << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min = " << ::min( a, b ) << std::endl;
	std::cout << "max = " << ::max( a, b ) << std::endl << std::endl;


	std::cout << "Before Swap String: " << std::endl;
	std::string c = "Bonjour";
	std::string d = "Aurevoir";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "After Swap String: " << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}