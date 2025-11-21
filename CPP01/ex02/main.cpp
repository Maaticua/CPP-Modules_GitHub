/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:40:13 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/21 10:49:49 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Adresse de la string en memoire : " << &str << std::endl;
	std::cout << "Adresse stockee dans stringPTR  : " << stringPTR << std::endl;
	std::cout << "Adresse stockee dans stringREF  : " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Valeur de la string    : " << str << std::endl;
	std::cout << "Valeur pointee par PTR : " << *stringPTR << std::endl;
	std::cout << "Valeur pointee par REF : " << stringREF << std::endl;

	return 0;
}
