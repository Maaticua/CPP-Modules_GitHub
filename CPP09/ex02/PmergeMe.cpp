/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:27:09 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/17 13:50:01 by macaruan         ###   ########.fr       */
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
std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int>& lst)
{
	if (lst.size() <= 1)
		return lst;

	int odd = -1;
	if (lst.size() % 2 != 0)
	{
		odd = lst.back();
		lst.pop_back();
	}
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < lst.size(); i+= 2)
	{
		if (lst[i] < lst[i + 1])
			std::swap(lst[i], lst[i + 1]);
		pairs.push_back(std::make_pair(lst[i], lst[i + 1]));
	}

	std::vector<int> higher;
	for (size_t i = 0; i < pairs.size(); i++)
		higher.push_back(pairs[i].first);
	higher = fordJohnsonVector(higher);

	std::vector<int> main_chain = higher;
	std::vector<int>pend;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++i)
		{
			if (pairs[j].first == main_chain[i])
			{
				pend.push_back(pairs[j].second);
				break;
			}
		}
	}
	
}