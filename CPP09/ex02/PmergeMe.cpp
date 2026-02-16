/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:27:09 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/16 16:00:25 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		_vec = src._vec;
		_deq = src._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

//? --- Ford Johnson vector logique ---
