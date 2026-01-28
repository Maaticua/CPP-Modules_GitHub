/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:08:07 by macaruan          #+#    #+#             */
/*   Updated: 2026/01/28 16:10:22 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t length, F func)
{
	if (!array || !func)
		return;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif