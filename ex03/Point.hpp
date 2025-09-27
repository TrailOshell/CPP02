/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:29:02 by tsomchan          #+#    #+#             */
/*   Updated: 2025/09/27 17:56:10 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point &point);
		~Point();

		Point &operator=(const Point &point);
	
		const Fixed &getX(void)const;
		const Fixed &getY(void)const;
};

std::ostream &operator<<(std::ostream &o, Point const &point);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif