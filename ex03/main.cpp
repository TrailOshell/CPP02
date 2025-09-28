/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:29:12 by tsomchan          #+#    #+#             */
/*   Updated: 2025/09/28 12:29:46 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	if (DEBUG_MODE != 0) std::cout << "DEBUG" << std::endl;

	// check inside or outside
	if (bsp(Point(0, 0), Point(5, 0), Point(3, 5), Point(3, 3)) == true)
		std::cout << GRN "point is inside triangle" << std::endl;
	else
		std::cout << RED "point is outside triangle" << std::endl;

	if (DEBUG_MODE == 2)
	{
		Point checkpoint(Fixed(3.0f), Fixed(3.0f));
		
		Point p1(0, 0);
		Point p2(Fixed(1.0f), Fixed(5.0f));
		Point p3(Fixed(3.0f), Fixed(5.0f));

		std::cout << p3.getX() << std::endl;
		std::cout << p3.getY() << std::endl;
		if (bsp(p1, p2, p3, checkpoint) == true)
			std::cout << GRN "point is inside triangle" << std::endl;
		else
			std::cout << RED "point is outside triangle" << std::endl;
	}		

	return (0);
}