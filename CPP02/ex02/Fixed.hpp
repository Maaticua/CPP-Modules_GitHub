/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:04:12 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/27 16:51:15 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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
		Fixed operator+(const Fixed& nbr) const;
		Fixed operator-(const Fixed& nbr) const;
		Fixed operator*(const Fixed& nbr) const;
		Fixed operator/(const Fixed& nbr) const;

		bool operator>(const Fixed& nbr) const;
		bool operator<(const Fixed& nbr) const;
		bool operator>=(const Fixed& nbr) const;
		bool operator<=(const Fixed& nbr) const;
		bool operator==(const Fixed& nbr) const;
		bool operator!=(const Fixed& nbr) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		int getRawBits() const;
		void setRawBits(int const raw);

		float toFloat() const;
		int toInt() const;

		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
};

std::ostream& operator <<(std::ostream& os, const Fixed& fixed);

#endif
