/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:43:55 by tsomchan          #+#    #+#             */
/*   Updated: 2025/09/27 22:31:43 by tsomchan         ###   ########.fr       */
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

	if (DEBUG_MODE == 1)
	{
		std::cout << YLW "area()" NCL << std::endl;
		std::cout << YLW "x1 = " NCL << x1 << YLW " y1 = " NCL << y1 << std::endl;
		std::cout << YLW "x2 = " NCL << x2 << YLW " y2 = " NCL << y2 << std::endl;
		std::cout << YLW "x3 = " NCL << x3 << YLW " y3 = " NCL << y3 << std::endl;
	}

	return (Fixed((const float) ((x1 * (y2 - y3) + x2 *(y3 - y1)+ x3 * (y1 - y2)) / 2.0)));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	//if (check_overlap_edges(a, b, c, point) == true)
	//{
	//	if (DEBUG_MODE == 1) std::cout << YLW "point is overlap with edges" << std::endl;
	//	return (false);
	//}

	Fixed ax = a.getX();
	Fixed ay = a.getY();
	Fixed bx = b.getX();
	Fixed by = b.getY();
	Fixed cx = c.getX();
	Fixed cy = c.getY();
	Fixed px = point.getX();
	Fixed py = point.getY();

	std::cout << "a " << ax << " " << ay << std::endl;
	std::cout << "b " << bx << " " << by << std::endl;
	std::cout << "c " << cx << " " << cy << std::endl;
	std::cout << "p " << px << " " << py << std::endl;


	//std::cout << c.getX() << std::endl;
	//std::cout << c.getY() << std::endl;

	Fixed A = area(a, b, c);
	Fixed A1 = area(a, b, point);
	Fixed A2 = area(a, c, point);
	Fixed A3 = area(b, c, point);
	
	//Fixed A = Fixed((const float) ((ax * (by - cy) + bx *(cy - ay)+ cx * (ay - by)) / 2.0));
	//Fixed A1 = area(a, b, point);
	//Fixed A2 = area(a, c, point);
	//Fixed A3 = area(b, c, point);

	if (DEBUG_MODE == 1)
	{
		std::cout << PUR "All (a b c) = " NCL << A.toFloat() << std::endl;
		std::cout << RED "A1  (a b p) = " NCL << A1.toFloat() << std::endl;
		std::cout << BLU "A2  (a c p) = " NCL << A2.toFloat() << std::endl;
		std::cout << GRN "A3  (b c p) = " NCL << A3.toFloat() << std::endl;
	}

	return (A.toFloat() == A1.toFloat() + A2.toFloat() + A3.toFloat());
}