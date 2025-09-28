/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:29:12 by tsomchan          #+#    #+#             */
/*   Updated: 2025/09/28 16:10:30 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

void print_bsp_result(bool ret)
{
	if (ret == true)
		std::cout << GRN "point is inside triangle" << std::endl;
	else
		std::cout << RED "point is outside triangle" << std::endl;
}

void debug_text(std::string text)
{
	if (DEBUG_MODE == 0)
		return ;
	std::cout << std::endl << PUR "/// " << text << " \\\\\\" NCL << std::endl;

}

int main()
{
	Point a = Point(0, 0);
	Point b = Point(Fixed(5.0f), Fixed(0.0f));
	Point c = Point(Fixed(3.0f), Fixed(5.0f));
	Point p = Point(Fixed(3.0f), Fixed(3.0f));

	print_bsp_result(bsp(a, b, c, p));

	debug_text("DEBUG");
	if (DEBUG_MODE == 1)
	{
		debug_text(RED"(FALSE) " PUR"Point to check is on one of the triangle's edge");
		print_bsp_result(bsp(
			Point(0, 0),
			Point(5, 0),
			Point(3, 5),
			Point(0, 0)));
		
		debug_text(GRN"(TRUE) " PUR"Directly put value in the function then put it in functions");
		print_bsp_result(bsp(Point(0, 0), Point(5, 0), Point(3, 5), Point(3, 3)));
		
		debug_text(GRN"(TRUE) " PUR"Point is inside");
		print_bsp_result(bsp(
			Point(0, 0),
			Point(5, 0),
			Point(3, 5),
			Point(1, 1)));
		
		debug_text(RED"(FALSE) " PUR"Point is outside");
		print_bsp_result(bsp(
			Point(1, 1),
			Point(5, 0),
			Point(3, 5),
			Point(0, 0)));
		
		debug_text(GRN"(TRUE) " PUR"Point is inside: points are float");
		print_bsp_result(bsp(
			Point(0.11f, 0.11f),
			Point(5.55f, 0.11f),
			Point(3.33f, 5.55f),
			Point(0.5f, 0.5f)));
		
		debug_text(GRN"(TRUE) " PUR"Point is inside: points are float and int");
		print_bsp_result(bsp(
			Point(0, 0),
			Point(5.55f, 0),
			Point(3, 5.55f),
			Point(1.5f, 1.5f)));
	}		
	return (0);
}