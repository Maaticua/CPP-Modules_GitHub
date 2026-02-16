/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:03:34 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/16 14:55:06 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &src) {*this = src;}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
		this->_stack = src._stack;
	return *this;
}

RPN::~RPN() {}

void RPN::calculate(const std::string &expression)
{
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (token.length() == 1 && isdigit(token[0]))
			_stack.push(std::atoi(token.c_str()));
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			long long rhs = _stack.top(); _stack.pop();
			long long lhs = _stack.top(); _stack.pop();
			long long res = 0;

			if (token == "+")
				res = lhs + rhs;
			else if (token == "-")
				res = lhs - rhs;
			else if (token == "*")
				res = lhs * rhs;
			else if (token == "/")
			{
				if (rhs == 0)
				{
					std::cerr << "Error: Division by zero" << std::endl;
					return;
				}
				res = lhs / rhs;
			}

			if (res > 2147483647 || res < -2147483648)
			{
				std::cerr << "Error: result out of bounds" << std::endl;
				return;
			}
			_stack.push(static_cast<int>(res));
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return;
		}
	}
	if (_stack.size() != 1)
		std::cerr << "Error" << std::endl;
	else
		std::cout << _stack.top() << std::endl;
}
