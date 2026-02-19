/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe2.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:52:04 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/19 14:08:24 by macaruan         ###   ########.fr       */
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

bool PmergeMe::isPositiveInt(const std::string &s)
{
	if (s.empty())
		return false;
	for (size_t i = 0; i < s.length(); ++i)
	{
			if (!isdigit(s[i]))
			return false;
	}
	return true;
}
//* ==== Suite de Jacobsthal ====
std::vector<size_t> PmergeMe::generateJacobsthal(size_t n)
{
	std::vector<size_t> j;
	if (n == 0)
		return j;
	j.push_back(1);
	if (n == 1)
		return j;
	j.push_back(3);
	while (j.back() < n)
		j.push_back(j[j.size() - 1] + 2 * j[j.size() - 2]);
	return j;
}

//? ==== FordJhonson Vector ====
std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> &lst)
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
	for (size_t i = 0; i < lst.size(); i += 2)
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
	std::vector<int> pend;

	for (size_t i = 0; i < main_chain.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == main_chain[i])
			{
				pend.push_back(pairs[j].second);
				break;
			}
		}
	}
	//* insertion grace a jacobstahl
	std::vector<size_t> jacob = generateJacobsthal(pend.size());
	size_t last_pos = 0;
	for (size_t i = 0; i < jacob.size(); i++)
	{
		size_t curr_pos = std::min(jacob[i], pend.size());
		for (size_t k = curr_pos; k > last_pos; --k)
		{
			int val = pend[k - 1];
			main_chain.insert(std::lower_bound(main_chain.begin(), main_chain.end(), val), val);
		}
		last_pos = curr_pos;
	}

	if (odd != -1)
		main_chain.insert(std::lower_bound(main_chain.begin(), main_chain.end(), odd), odd);

	return main_chain;

}
//! ==== FordJhonson Deque ====
std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int> &lst)
{
	if (lst.size() <= 1)
		return lst;
	int odd = -1;
	if (lst.size() % 2 != 0)
	{
		odd = lst.back();
		lst.pop_back();
	}

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < lst.size(); i += 2)
	{
		if (lst[i] < lst[i + 1])
			std::swap(lst[i], lst[i + 1]);
		pairs.push_back(std::make_pair(lst[i], lst[i + 1]));
	}

	std::deque<int> higher;
	for (size_t i = 0; i < pairs.size(); i++)
		higher.push_back(pairs[i].first);
	higher = fordJohnsonDeque(higher);

	std::deque<int> main_chain = higher;
	std::deque<int> pend;

	for (size_t i = 0; i < main_chain.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == main_chain[i])
			{
				pend.push_back(pairs[j].second);
				break;
			}
		}
	}
	//* insertion grace a jacobstahl
	std::vector<size_t> jacob = generateJacobsthal(pend.size());
	size_t last_pos = 0;
	for (size_t i = 0; i < jacob.size(); i++)
	{
		size_t curr_pos = std::min(jacob[i], pend.size());
		for (size_t k = curr_pos; k > last_pos; --k)
		{
			int val = pend[k - 1];
			main_chain.insert(std::lower_bound(main_chain.begin(), main_chain.end(), val), val);
		}
		last_pos = curr_pos;
	}

	if (odd != -1)
		main_chain.insert(std::lower_bound(main_chain.begin(), main_chain.end(), odd), odd);

	return main_chain;
}
void PmergeMe::run(int ac, char **av)
{
	//* Parsing
	for (int i = 1; i < ac; ++i)
	{
		if (!isPositiveInt(av[i]))
		{
			std::cerr << "Error" << std::endl;
			return;
		}
		_vec.push_back(std::atoi(av[i]));
		_deq.push_back(std::atoi(av[i]));
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		std::cout << _vec[i] << " ";
		if (i == 9 && _vec.size() > 10)
		{
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;

	//* Temps de Deque et Vector
	struct timeval start, end;

	//? Mesure de Vector
	gettimeofday(&start, NULL);
	_vec = fordJohnsonVector(_vec);
	gettimeofday(&end, NULL);
	long long vec_time = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);

	//! Mesure de Deque
	gettimeofday(&start, NULL);
	_deq = fordJohnsonDeque(_deq);
	gettimeofday(&end, NULL);
	long long deq_time = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);

	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		std::cout << _vec[i] << " ";
		if (i == 9 && _vec.size() > 10)
		{
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << vec_time << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << deq_time << " us" << std::endl;
}