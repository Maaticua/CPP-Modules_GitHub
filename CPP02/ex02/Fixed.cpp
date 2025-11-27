/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:04:10 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/27 16:51:49 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	_value = n * (1 << _fractionalBits);
}

Fixed::Fixed(const float f)
{
	_value = roundf(f * (1 << _fractionalBits));
}

float Fixed::toFloat() const
{
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
	return _value >> _fractionalBits;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

Fixed Fixed::operator+(const Fixed& nbr) const
{
	Fixed result;
	result._value = this->_value + nbr._value;
	return result;
}

Fixed Fixed::operator-(const Fixed& nbr) const
{
	Fixed result;
	result._value = this->_value - nbr._value;
	return result;
}

Fixed Fixed::operator*(const Fixed& nbr) const
{
	Fixed result;
	result._value = (this->_value * nbr._value) >> _fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed& nbr) const
{
	Fixed result;
	result._value = (this->_value << _fractionalBits) / nbr._value;
	return result;
}

bool Fixed::operator>(const Fixed& nbr) const
{
	return this->_value > nbr._value;
}

bool Fixed::operator<(const Fixed& nbr) const
{
	return this->_value < nbr._value;
}

bool Fixed::operator>=(const Fixed& nbr) const
{
	return this->_value >= nbr._value;
}

bool Fixed::operator<=(const Fixed& nbr) const
{
	return this->_value <= nbr._value;
}

bool Fixed::operator==(const Fixed& nbr) const
{
	return this->_value == nbr._value;
}

bool Fixed::operator!=(const Fixed& nbr) const
{
	return this->_value != nbr._value;
}

Fixed& Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed& Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a._value > b._value) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a._value > b._value) ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a._value < b._value) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a._value < b._value) ? a : b;
}
