/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:33:20 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/09 14:37:57 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const &arg)
{
	double val;
	char *end;

	if (arg.length() == 1 && !std::isdigit(arg[0]))
		val = static_cast<double>(arg[0]);
	else
	{
		val = std::strtod(arg.c_str(), &end);
		if (*end != '\0' && std::string(end) != "f")
		{
			if (arg.length() > 1)
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return;
			}
		}
	}

	std::cout << "char: ";
	if (val < 0 || val > 255 || val != val)
		std::cout << ": impossible";
	else if (!std::isprint(static_cast<int>(val)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(val) << "'";
	std::cout << std::endl;


	std::cout << "int: ";
	if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max() || val != val)
		std::cout << "Impossible";
	else
		std::cout << static_cast<int>(val);
	std::cout << std::endl;


	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
	std::cout << "double " << val << std::endl;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &)
{
	return *this;
}