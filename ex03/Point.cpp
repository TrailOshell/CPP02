/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:29:04 by tsomchan          #+#    #+#             */
/*   Updated: 2025/09/27 18:27:30 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) 
{
	if (DEBUG_MODE == 1) std::cout << GRN "Default constructor called" NCL << std::endl;
	//_x;
	//_y;
}

Point::Point(const Fixed x, const Fixed y): _x(x), _y(y)
{
	if (DEBUG_MODE == 1) std::cout << PUR"Int " GRN"constructor called" NCL << std::endl;
	// x y
}

Point::Point(const Point &point)
{
	if (DEBUG_MODE == 1) std::cout << YLW "Copy constructor called" NCL << std::endl;
	*this = point;
}

Point::~Point()
{
	if (DEBUG_MODE == 1) std::cout << RED "Destructor called" NCL << std::endl;
}

Point &Point::operator=(const Point &point)
{
	if (DEBUG_MODE == 1) std::cout << PUR "Copy assignment operator called" NCL << std::endl;
	(void) point;
	return (*this);
}

const Fixed &Point::getX(void)const{
	return _x;
}
const Fixed &Point::getY(void)const{
	return _y;
}