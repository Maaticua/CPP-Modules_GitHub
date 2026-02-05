/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:06 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/05 12:36:39 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
	private:
		unsigned int 		_n;
		std::vector<int>	_vec;

	public:
		Span();
		Span(const unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int n);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		template <typename T>
		void addRange(T begin, T end)
		{
			if (_vec.size() + std::distance(begin, end) > _n)
				throw SpanFullExeption();
			_vec.insert(_vec.end(), beign, end);
		}

		class SpanFullException : public std::exception
		{
			public: virtual const char * what() const throw()
			{
				return "Span already full";
			}
		};

		class NotEnoughElementsException : public std::exception
		{
			public: virtual const char * what() const throw()
			{
				return "Not enough items";
			}
		};

};

#endif