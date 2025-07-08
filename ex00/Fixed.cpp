/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:48:50 by tsomchan          #+#    #+#             */
/*   Updated: 2025/07/08 16:42:23 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << GRN "Default constructor called" NCL << std::endl;
	_fpNum = 0;
}

Fixed::~Fixed()
{
	std::cout << RED "Destructor called" NCL << std::endl;
}

Fixed::Fixed(Fixed &fixed)
{
	std::cout << YLW "Copy constructor called" NCL << std::endl;
	_fpNum = fixed._fpNum;
}
	//std::cout << YLW "Copy assignment operator called" NCL << std::endl;

int Fixed::getRawBits(void) const
{
	std::cout << CYN "getRawBits member function called" NCL << std::endl;
	return (_fpNum);
}

void Fixed::setRawBits(int const raw)
{
	_fpNum = raw;
}