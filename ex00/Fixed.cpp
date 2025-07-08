/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:48:50 by tsomchan          #+#    #+#             */
/*   Updated: 2025/07/08 18:39:10 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed()
{
	std::cout << GRN "Default constructor called" NCL << std::endl;
	_fpNum = 0;
}

Fixed::Fixed(Fixed &fixed)
{
	std::cout << YLW "Copy constructor called" NCL << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed& fixed)
{
	std::cout << PUR "Copy assignment operator called" NCL << std::endl;
	_fpNum = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << RED "Destructor called" NCL << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << CYN "getRawBits member function called" NCL << std::endl;
	return (_fpNum);
}

void Fixed::setRawBits(int const raw)
{
	_fpNum = raw;
}