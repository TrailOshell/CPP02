/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:43:55 by tsomchan          #+#    #+#             */
/*   Updated: 2025/09/27 20:27:49 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool check_overlap_edges( Point const a, Point const b, Point const c, Point const point)
{
	Fixed ax = a.getX();
	Fixed ay = a.getY();
	Fixed bx = b.getX();
	Fixed by = b.getY();
	Fixed cx = c.getX();
	Fixed cy = c.getY();
	Fixed px = point.getX();
	Fixed py = point.getY();

	if ( (px == ax && py == ay) || (px == bx && py == by) || (px == cx && py == cy) )
		return (true);
	else
		return (false);
}

Fixed area(Point const p1, Point const p2, Point const p3)
{
	Fixed x1 = p1.getX();
	Fixed y1 = p1.getY();
	Fixed x2 = p2.getX();
	Fixed y2 = p2.getY();
	Fixed x3 = p3.getX();
	Fixed y3 = p3.getY();

	return (Fixed((const float) ((x1 * (y2 - y3) + x2 *(y3 - y1)+ x3 * (y1 - y2)) / 2.0)));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (check_overlap_edges(a, b, c, point) == true)
		return (false);

	Fixed A = area(a, b, c);
	Fixed A1 = area(a, b, point);
	Fixed A2 = area(a, c, point);
	Fixed A3 = area(b, c, point);

	return (A.toFloat() == A1.toFloat() + A2.toFloat() + A3.toFloat());
}