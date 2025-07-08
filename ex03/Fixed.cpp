/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:28:58 by tsomchan          #+#    #+#             */
/*   Updated: 2025/07/09 00:28:59 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed()
{
	if (DEBUG_MODE == 1) std::cout << GRN "Default constructor called" NCL << std::endl;
	_fpNum = 0;
}

Fixed::Fixed(const int number)
{
	if (DEBUG_MODE == 1) std::cout << PUR"Int " GRN"constructor called" NCL << std::endl;
	_fpNum = number << _fractBits;
}

Fixed::Fixed(const float number)
{
	if (DEBUG_MODE == 1) std::cout << CYN"Float " GRN"constructor called" NCL << std::endl;
	_fpNum = roundf(number * (1 << _fractBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	if (DEBUG_MODE == 1) std::cout << YLW "Copy constructor called" NCL << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	if (DEBUG_MODE == 1) std::cout << RED "Destructor called" NCL << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (DEBUG_MODE == 1) std::cout << PUR "Copy assignment operator called" NCL << std::endl;
	_fpNum = fixed.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed fixed) const
{
	return (toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
	return (toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (toFloat() != fixed.toFloat());
}

float	Fixed::operator+(Fixed fixed) const
{
	return (toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
	return (toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
	return (toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
	return (toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++()
{
	_fpNum++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	_fpNum--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->_fpNum;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->_fpNum;
	return (tmp);
}


float Fixed::toFloat(void) const
{
	return ((float)_fpNum / (float)(1 << _fractBits));
}

int Fixed::toInt( void ) const
{
	return (_fpNum >> _fractBits);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return ((a.toFloat() <= b.toFloat()) ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a.toFloat() <= b.toFloat()) ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return ((a.toFloat() >= b.toFloat()) ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a.toFloat() >= b.toFloat()) ? a : b);
}

std::ostream &operator<<(std::ostream &outStream, Fixed const &fixed)
{
	outStream << fixed.toFloat();
	return (outStream);
}

int Fixed::getRawBits(void) const
{
	if (DEBUG_MODE == 1) std::cout << CYN "getRawBits member function called" NCL << std::endl;
	return (_fpNum);
}

void Fixed::setRawBits(int const raw)
{
	_fpNum = raw;
}
