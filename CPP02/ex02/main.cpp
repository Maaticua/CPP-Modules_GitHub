/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:04:14 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/26 18:35:18 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;

	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return (0);
}


//main de test

// int	main(void)
// {
// 	Fixed	a;
// 	Fixed	g;

// 	std::cout << "=== Test constructeurs ===" << std::endl;
// 	Fixed b(10);
// 	Fixed c(42.42f);
// 	Fixed d(b);
// 	std::cout << "\n=== Test affichage ===" << std::endl;
// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "b: " << b << std::endl;
// 	std::cout << "c: " << c << std::endl;
// 	std::cout << "d: " << d << std::endl;
// 	std::cout << "\n=== Test opérateurs arithmétiques ===" << std::endl;
// 	std::cout << "b + c = " << b + c << std::endl;
// 	std::cout << "c - b = " << c - b << std::endl;
// 	std::cout << "b * c = " << b * c << std::endl;
// 	std::cout << "c / b = " << c / b << std::endl;
// 	std::cout << "\n=== Test opérateurs de comparaison ===" << std::endl;
// 	std::cout << "b > c: " << (b > c) << std::endl;
// 	std::cout << "b < c: " << (b < c) << std::endl;
// 	std::cout << "b >= d: " << (b >= d) << std::endl;
// 	std::cout << "b <= d: " << (b <= d) << std::endl;
// 	std::cout << "b == d: " << (b == d) << std::endl;
// 	std::cout << "b != c: " << (b != c) << std::endl;
// 	std::cout << "\n=== Test incrémentation/décrémentation ===" << std::endl;
// 	std::cout << "a avant: " << a << std::endl;
// 	std::cout << "++a: " << ++a << std::endl;
// 	std::cout << "a après ++: " << a << std::endl;
// 	std::cout << "a++: " << a++ << std::endl;
// 	std::cout << "a après a++: " << a << std::endl;
// 	std::cout << "\n=== Test min et max ===" << std::endl;
// 	std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
// 	std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;
// 	Fixed const e(20.5f);
// 	Fixed const f(10.25f);
// 	std::cout << "min(e, f) const: " << Fixed::min(e, f) << std::endl;
// 	std::cout << "max(e, f) const: " << Fixed::max(e, f) << std::endl;
// 	std::cout << "\n=== Test conversions ===" << std::endl;
// 	std::cout << "c as int: " << c.toInt() << std::endl;
// 	std::cout << "c as float: " << c.toFloat() << std::endl;
// 	std::cout << "\n=== Test du sujet ===" << std::endl;
// 	Fixed const h(Fixed(5.05f) * Fixed(2));
// 	std::cout << g << std::endl;
// 	std::cout << ++g << std::endl;
// 	std::cout << g << std::endl;
// 	std::cout << g++ << std::endl;
// 	std::cout << g << std::endl;
// 	std::cout << h << std::endl;
// 	std::cout << Fixed::max(g, h) << std::endl;
// 	return (0);
// }
