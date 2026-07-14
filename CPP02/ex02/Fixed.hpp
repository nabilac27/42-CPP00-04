/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:51:07 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/08 13:45:51 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed
{
    private:
        int                 fixedPointNumber;
        static const int    fractionalBitsNumber = 8;

    public:
        Fixed();
        Fixed(const int intNumber);   
	    Fixed(const float floatNumber); 
        Fixed(const Fixed& other);

        Fixed&  operator=(const Fixed &other); 

	    ~Fixed();

        int     getRawBits(void) const;
	    void    setRawBits(int const raw);

        float   toFloat(void) const;
	    int     toInt(void) const;  

        /* -----------------      Comparison Operator      ----------------- */
        bool    operator>(const Fixed &other) const;
	    bool    operator<(const Fixed &other) const;
	    bool    operator>=(const Fixed &other) const;
	    bool    operator<=(const Fixed &other) const;
	    bool    operator==(const Fixed &other) const;
	    bool    operator!=(const Fixed &other) const;

        /* -----------------     Arithmetic Operator        ----------------- */
        Fixed   operator+(const Fixed& other) const;
        Fixed   operator-(const Fixed& other) const;
        Fixed   operator*(const Fixed& other) const;
        Fixed   operator/(const Fixed& other) const;

        /* -----------------  Increment-Decrement Operator   ----------------- */
        Fixed&  operator++();
        Fixed   operator++(int);
        Fixed&  operator--();
        Fixed   operator--(int);

        /* ----------------- Public Overload Min, Max Function ----------------*/
        static Fixed&       min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed&       max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream&   operator<<(std::ostream &out, const Fixed &fixed);

#endif