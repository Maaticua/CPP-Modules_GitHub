/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:24:03 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/06 13:14:20 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
	private:

	public :
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		MutantStack() : std::stack<T>() {};
		MutantStack(const MutantStack& other) : std::stack<T>(other) {};
		MutantStack& operator=(const MutantStack& other) {if (this != &other) std::stack<T>::operator=(other); return *this;};
		~MutantStack() {};

		iterator begin() { return this->c.begin(); };
		iterator end() { return this->c.end(); };
		const_iterator begin() const { return this->c.begin(); };
		const_iterator end() const { return this->c.end(); };
		iterator rbegin() { return this->c.rbegin(); };
		iterator rend() { return this->c.rend(); };

};

#endif