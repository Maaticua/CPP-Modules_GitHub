/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:27:09 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/18 10:23:40 by macaruan         ###   ########.fr       */
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
	for (size_t i = 0; i < pend.size(); ++i)
	{
		std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pend[i]);
		main_chain.insert(it, pend[i]);
	}
	if (odd != -1)
	{
		std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), odd);
		main_chain.insert(it, odd);
	}
	return main_chain;
}

void PmergeMe::run(int ac, char **av)
{
	for (int i = 1; i < ac; ++i)
	{
		int val = std::atoi(av[i]);
		if (val < 0)
		{
			std::cerr << "Error" << std::endl;
			return;
		}
		_vec.push_back(val);
		_deq.push_back(val);
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size() && i < 10; ++i)
		std::cout << _vec[i] << " ";
	if (_vec.size() > 10)
		std::cout << "[...]" << std::endl;

	//? Time pour vector
	struct timeval start, end;
	gettimeofday(&start, NULL);
	_vec = fordJohnsonVector(_vec);
	gettimeofday(&end, NULL);
	long long vec_time = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);

	//! Time pour deque
	gettimeofday(&start, NULL);
	_deq = fordJohnsonDeque(_deq);
	gettimeofday(&end, NULL);
	long long vec_time = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
	
}