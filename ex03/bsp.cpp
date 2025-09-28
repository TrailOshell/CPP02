/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:43:55 by tsomchan          #+#    #+#             */
/*   Updated: 2025/09/28 13:06:34 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool check_overlap_edges(Point const a, Point const b, Point const c, Point const point)
{
	if ((point.getX() == a.getX() && point.getY() == a.getY()) ||
		(point.getX() == b.getX() && point.getY() == b.getY()) ||
		(point.getX() == c.getX() && point.getY() == c.getY()))
	{
		if (DEBUG_MODE != 0) std::cout << YLW "point is overlap with edges" << std::endl;
		return (true);
	}
	else
		return (false);
}

float subarea(Point x, Point y1, Point y2)
{
	return (x.getX().toFloat() * (y1.getY().toFloat() - y2.getY().toFloat()));
}

float area(Point const p1, Point const p2, Point const p3)
{
	// basically formula of --> area = ( x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2) ) / 2;
	float area = ( subarea(p1, p2, p3) + subarea(p2, p3, p1) + subarea(p3, p1, p2) ) / 2;

	if (area < 0)
		area *= -1;

	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (DEBUG_MODE != 0) db_bsp(a, b, c, point);

	if (check_overlap_edges(a, b, c, point) == true)
		return (false);

	float A = area(a, b, c);
	float A1 = area(a, b, point);
	float A2 = area(a, c, point);
	float A3 = area(b, c, point);
	if (DEBUG_MODE != 0) db_bsp_areas(A, A1, A2, A3);

	return (A == A1 + A2 + A3);
}

void db_point(std::string name, std::string color, Point const point)
{
	if (DEBUG_MODE == 0)
		return ;

	std::cout
	<< color << name << "(" NCL
	<< point.getX()
	<< color << ", " NCL
	<< point.getY()
	<< color << ") " NCL;
}

void db_bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (DEBUG_MODE == 0)
		return ;

	std::cout << GRN "bsp Points: " NCL;
	db_point("a", RED, a);
	db_point("b", BLU, b);
	db_point("c", YLW, c);
	db_point("p", PUR, point);
	std::cout << std::endl;
}

void db_bsp_areas(float A, float A1, float A2, float A3)
{
	if (DEBUG_MODE == 0)
		return ;

	std::cout
	<< PUR "All(a b c) = " NCL << A << CYN " | " NCL 
	<< CYN"A1" CYN"(" RED"a " BLU"b " PUR"p" CYN") = " NCL << A1 << CYN " | " NCL
	<< CYN"A2" CYN"(" RED"a " YLW"c " PUR"p" CYN") = " NCL << A2 << CYN " | " NCL
	<< CYN"A3" CYN"(" BLU"b " YLW"c " PUR"p" CYN") = " NCL << A3 << CYN " | " NCL
	<< std::endl;
}