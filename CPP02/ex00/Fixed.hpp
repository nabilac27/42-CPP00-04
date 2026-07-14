/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:51:07 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/08 12:40:49 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 fixedPointNumber;
        static const int    fractionalBitsNumber = 8;

    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed&  operator=(const Fixed &other); 
	    ~Fixed();

        int     getRawBits(void) const;
	    void    setRawBits(int const raw);
};

#endif
