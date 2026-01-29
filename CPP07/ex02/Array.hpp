/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:42:22 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/29 12:12:46 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		T* elements;
		unsigned int _size;

	public:
		Array() : elements(NULL), _size(0) {}
		Array(unsigned int j) : _size(j)
		{
			elements = new T[_size]();
		}
		Array(Array const & src) : elements(NULL), _size(0)
		{
			*this = src;
		}
		Array &operator=(Array const &rhs)
		{
			if (this != &rhs)
			{
				if (elements)
					delete[] elements;
				_size = rhs._size;
				elements = new T[_size];
				for (unsigned int x = 0; x < _size; x++)
					elements[x] = rhs.elements[x];
			}
			return *this;
		}
		~Array()
		{
			if (elements)
				delete[] elements;
		}

		T &operator[](unsigned int index)
		{
			if (index >= _size || !elements)
				throw std::out_of_range("Index out of bounds");
			return elements[index];
		}

		const T &operator[](unsigned int index) const
		{
			if (index >= _size || !elements)
				throw std::out_of_range("Index out of bounds");
			return elements[index];
		}

		unsigned int size() const
		{
			return _size;
		}
};

#endif