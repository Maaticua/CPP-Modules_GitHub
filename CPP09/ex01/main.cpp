/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:02:44 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/16 14:42:41 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Usage: ./RPN \"expression\"" << std::endl;
		return 1;
	}

	RPN calculator;
	calculator.calculate(av[1]);
	return 0;
}