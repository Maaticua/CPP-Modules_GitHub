/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:22:34 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/21 14:16:30 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "=== Test DEBUG ===" << std::endl;
	harl.complain("DEBUG");

	std::cout << "\n=== Test INFO ===" << std::endl;
	harl.complain("INFO");

	std::cout << "\n=== Test WARNING ===" << std::endl;
	harl.complain("WARNING");

	std::cout << "\n Test ERROR ===" << std::endl;
	harl.complain("ERROR");

	std::cout << "\n=== Test INVALID ===" << std::endl;
	harl.complain("INVALID");

	return 0;
}
