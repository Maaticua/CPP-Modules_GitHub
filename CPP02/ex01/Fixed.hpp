/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:06:21 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/25 15:30:07 by macaruan         ###   ########.fr       */
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
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator=(const Fixed& other);

		float toFloat(void) const;
		int toInt(void) const;

		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif
