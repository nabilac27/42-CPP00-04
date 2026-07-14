/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:48:40 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/08 14:49:41 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed       	a;
	Fixed const 	b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a 	 << std::endl;
	std::cout << ++a << std::endl;

	std::cout << a	 << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a 	 << std::endl;

	std::cout << b 	 << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	return (0);
}

// int main()
// {
//     Fixed a(5);
//     Fixed b(3);
//     Fixed c(5);

// 	std::cout << "\n----------------------------\n";
//     std::cout << "	Comparison Tests 			\n";
// 	std::cout << "----------------------------\n";

//     std::cout << "a > b  = " << (a > b) << std::endl;
//     std::cout << "a < b  = " << (a < b) << std::endl;
//     std::cout << "a >= c = " << (a >= c) << std::endl;
//     std::cout << "a <= c = " << (a <= c) << std::endl;
//     std::cout << "a == c = " << (a == c) << std::endl;
//     std::cout << "a != b = " << (a != b) << std::endl;

// 	std::cout << "\n---------------------------\n";
//     std::cout << "	Arithmetic Tests 	   	   \n";
//     std::cout << "---------------------------\n";

//     std::cout << "a + b = " << (a + b) << std::endl;
//     std::cout << "a - b = " << (a - b) << std::endl;
//     std::cout << "a * b = " << (a * b) << std::endl;
//     std::cout << "a / b = " << (a / b) << std::endl;

// 	std::cout << "\n---------------------------\n";
// 	std::cout << "Increment-Decrement Tests	  \n";
// 	std::cout << "---------------------------\n\n";
// 	// ++ means increases by 1/256 ≈ 0.00390625
// 	// -- means decreases by 1/256 ≈ 0.00390625

// 	Fixed d(5);
// 	std::cout << "d       = " << d 		<< std::endl;
// 	std::cout << "++d     = " << ++d 	<< std::endl;

// 	std::cout << "\n-----------------\n" << std::endl;

// 	Fixed e(5);
// 	std::cout << "e++     = " << e++ 	<< std::endl;
// 	std::cout << "e after = " << e 		<< std::endl;

// 	std::cout << "\n-----------------\n" << std::endl;

// 	Fixed f(5);
// 	std::cout << "f       = " << f 		<< std::endl;
// 	std::cout << "f++     = " << f++ 	<< std::endl;
// 	std::cout << "f after = " << f 		<< std::endl;
// 	std::cout << "--f     = " << --f 	<< std::endl;
// 	std::cout << "f--     = " << f-- 	<< std::endl;
// 	std::cout << "f after = " << f 		<< std::endl;

// 	std::cout << "\n-----------------\n" << std::endl;

// 	std::cout << "\n----------------------------\n";
// 	std::cout << "        Min / Max Tests     \n";
// 	std::cout << "----------------------------\n";

// 	Fixed g(10);
// 	Fixed h(20);

// 	std::cout << "g = " << g << std::endl;
// 	std::cout << "h = " << h << std::endl;
// 	std::cout << "\n-----------------\n\n";
// 	std::cout << "min(g, h) = " << Fixed::min(g, h) << std::endl;
// 	std::cout << "max(g, h) = " << Fixed::max(g, h) << std::endl;

// 	std::cout << "\n-----------------\n\n";
// 	std::cout << " const parameter  ";
// 	std::cout << "\n-----------------\n\n";
// 	const Fixed i(42.42f);
// 	const Fixed j(21.21f);

// 	std::cout << "i = " << i << std::endl;
// 	std::cout << "j = " << j << std::endl;
// 	std::cout << "\n-----------------\n\n";
// 	std::cout << "min(i, j) = " << Fixed::min(i, j) << std::endl;
// 	std::cout << "max(i, j) = " << Fixed::max(i, j) << std::endl;
		
//     return (0);
// }
