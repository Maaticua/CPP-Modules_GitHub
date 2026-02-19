/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:27:23 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/19 10:57:24 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

		// ? Ford Johnson version <vector>
		void sortVector();
		std::vector<int> fordJohnsonVector(std::vector<int>& lst);

		// ! Ford Johnson version <deque>
		void sortDeque();
		std::deque<int> fordJohnsonDeque(std::deque<int>& lst);

		std::vector<size_t> generateJacobsthal(size_t n);
		bool isPositiveInt(const std::string &s);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void run(int ac, char **av);
};

#endif