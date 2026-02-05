/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:04 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/05 14:29:16 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0)
{}

Span::Span(const unsigned int n) : _n(n)
{}

Span::Span(const Span& other) : _n(other._n), _vec(other._vec)
{}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_n = other._n;
		_vec = other._vec;
	}
	return *this;
}

Span::~Span()
{}

void Span::addNumber(int n)
{
	if (_vec.size() >= _n)
		throw SpanFullException();
	_vec.push_back(n);
}

unsigned int Span::shortestSpan() const
{
	if (_vec.size() < 2)
		throw NotEnoughElementsException();
	std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = static_cast<unsigned int>(sorted[1] - sorted[0]);
	for (size_t i = 1; i < sorted.size() - 1; i++)
	{
		unsigned int currentSpan = static_cast<unsigned int>(sorted[i + 1] - sorted[i]);
		if (currentSpan < minSpan)
			minSpan = currentSpan;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (_vec.size() < 2)
		throw NotEnoughElementsException();

	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());
	return static_cast<unsigned int> (max -min);
}