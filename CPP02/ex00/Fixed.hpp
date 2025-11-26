/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:31:30 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/25 15:47:12 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _value;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator=(const Fixed& other);

		int getRawBits() const;
		void setRawBits(int const raw);

};

#endif
