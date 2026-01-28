/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:52:54 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/28 15:59:08 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T & a, T & b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T & min(const T & a, const T & b)
{
	return (a < b) ? a : b;
}

template <typename T>
const T & max(const T & a, const T & b)
{
	return (a > b) ? a : b;
}

#endif