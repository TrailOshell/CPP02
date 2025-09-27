/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:33:10 by tsomchan          #+#    #+#             */
/*   Updated: 2025/07/09 15:24:32y tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	if (DEBUG_MODE >= 1)
	{
		std::cout << YLW "- -- Test operators -- -" NCL << std::endl;
	
		Fixed	fix_a = 25.5f;
		Fixed	fix_b = 1.5f;

		std::cout << PUR "fix_a\t= " NCL << fix_a << std::endl;
		std::cout << PUR "fix_b\t= " NCL << fix_b << std::endl;

		std::cout << YLW "GRT: " << fix_a << " >  " << fix_b << PUR" = " << CYN << (fix_a >  fix_b) << NCL << std::endl;
		std::cout << YLW "LSS: " << fix_a << " <  " << fix_b << PUR" = " << CYN << (fix_a <  fix_b) << NCL << std::endl;
		std::cout << YLW "GRE: " << fix_a << " >= " << fix_b << PUR" = " << CYN << (fix_a >= fix_b) << NCL << std::endl;
		std::cout << YLW "LSE: " << fix_a << " <= " << fix_b << PUR" = " << CYN << (fix_a <= fix_b) << NCL << std::endl;
		std::cout << YLW "EQL: " << fix_a << " == " << fix_b << PUR" = " << CYN << (fix_a == fix_b) << NCL << std::endl;
		std::cout << YLW "NEQ: " << fix_a << " != " << fix_b << PUR" = " << CYN << (fix_a != fix_b) << NCL << std::endl;

		std::cout << NCL "ADD: " YLW << fix_a << " + " << fix_b << PUR" = " CYN << fix_a + fix_b << NCL << std::endl;
		std::cout << NCL "SUB: " YLW << fix_a << " - " << fix_b << PUR" = " CYN << fix_a - fix_b << NCL << std::endl;
		std::cout << NCL "MUL: " YLW << fix_a << " * " << fix_b << PUR" = " CYN << fix_a * fix_b << NCL << std::endl;
		std::cout << NCL "DIV: " YLW << fix_a << " / " << fix_b << PUR" = " CYN << fix_a / fix_b << NCL << std::endl;

		std::cout << YLW "min( fix_a, fix_b ) " PUR"= " CYN << Fixed::min( fix_a, fix_b ) << NCL << std::endl;
		std::cout << YLW "max( fix_a, fix_b ) " PUR"= " CYN << Fixed::max( fix_a, fix_b ) << NCL << std::endl;
	}

	return (0);
}