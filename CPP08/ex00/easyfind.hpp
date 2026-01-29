/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:16:39 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/29 15:33:00 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Element not Found in container";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int toFind)
{
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw NotFoundException();

	return it;
};

#endif