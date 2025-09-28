/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:29:04 by tsomchan          #+#    #+#             */
/*   Updated: 2025/09/28 12:42:26 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) 
{ if (DEBUG_MODE == 2) std::cout << GRN "Default constructor called" NCL << std::endl; }

Point::Point(const Fixed x, const Fixed y): _x(x), _y(y)
{ if (DEBUG_MODE == 2) std::cout << PUR "Int " GRN "constructor called" NCL << std::endl; }

Point::Point(const Point &point): _x(point.getX()), _y(point.getY())
{
	if (DEBUG_MODE == 2) std::cout << YLW "Copy constructor called" NCL << std::endl;
	*this = point;
}

Point::~Point()
{ if (DEBUG_MODE == 2) std::cout << RED "Destructor called" NCL << std::endl; }

Point &Point::operator=(const Point &point)
{
	if (DEBUG_MODE == 2) std::cout << PUR "Copy assignment operator called" NCL << std::endl;
	(void) point;
	return (*this);
}

const Fixed &Point::getX(void)const
{
	return _x;
}
const Fixed &Point::getY(void)const
{
	return _y;
}

std::ostream &operator<<(std::ostream &outStream, Point const point)
{
	outStream << "_x = " << point.getX() << ", _y = " << point.getY() << std::endl;
	return (outStream);
}