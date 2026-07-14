/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 01:54:15 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/08 14:52:44 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */
Fixed::Fixed() : fixedPointNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNumber)
{
	std::cout << "Int constructor called" << std::endl;

	fixedPointNumber = intNumber << fractionalBitsNumber;
}

Fixed::Fixed(const float floatNumber)
{
	std::cout << "Float constructor called" << std::endl;
	
	float scaledValue = floatNumber * (1 << fractionalBitsNumber);
	fixedPointNumber  = roundf(scaledValue);
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;

    *this = other;
}

/* ************************************************************************** */
/*                              ASSIGNMENT OPERATOR                           */
/* ************************************************************************** */
Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		fixedPointNumber = other.getRawBits();

	return (*this);
}

/* ************************************************************************** */
/*                                 DESTRUCTOR                                 */
/* ************************************************************************** */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* ************************************************************************** */
/*                                RAW ACCESSORS                               */
/* ************************************************************************** */
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPointNumber);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	fixedPointNumber = raw;
}

/* ************************************************************************** */
/*                                CONVERSIONS                                 */
/* ************************************************************************** */
float   Fixed::toFloat(void) const
{
	return (float)fixedPointNumber / (1 << fractionalBitsNumber);
}

int     Fixed::toInt(void) const
{
	return (fixedPointNumber >> fractionalBitsNumber);
}

/* ************************************************************************** */
/*                             OPERATOR OVERLOADS                             */
/* ************************************************************************** */
std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}