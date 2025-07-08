/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:33:01 by tsomchan          #+#    #+#             */
/*   Updated: 2025/07/08 18:50:49y tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed()
{
	std::cout << GRN "Default constructor called" NCL << std::endl;
	_fpNum = 0;
}

Fixed::Fixed(const int number)
{
	std::cout << PUR"Int " GRN"constructor called" NCL << std::endl;
	_fpNum = number << _fractBits;
}

Fixed::Fixed(const float number)
{
	std::cout << CYN"Float " GRN"constructor called" NCL << std::endl;
	_fpNum = roundf(number * (1 << _fractBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << YLW "Copy constructor called" NCL << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << RED "Destructor called" NCL << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << PUR "Copy assignment operator called" NCL << std::endl;
	_fpNum = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	// why is the example don't want to show getRawbits() somehow?
	//std::cout << CYN "getRawBits member function called" NCL << std::endl;
	return (_fpNum);
}

void Fixed::setRawBits(int const raw)
{
	_fpNum = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_fpNum / (float)(1 << _fractBits));
}

int Fixed::toInt( void ) const
{
	return (_fpNum >> _fractBits);
}

std::ostream &operator<<(std::ostream &outStream, Fixed const &fixed)
{
	outStream << fixed.toFloat();
	return (outStream);
}