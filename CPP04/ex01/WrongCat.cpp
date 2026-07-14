/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 23:17:11 by nchairun          #+#    #+#             */
/*   Updated: 2026/04/02 22:30:16 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ************************************************************************** */
/*                            CONSTRUCTORS                                    */
/* ************************************************************************** */
WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "[WrongCat]    Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "[WrongCat]    Copy constructor called" << std::endl;
}

/* ************************************************************************** */
/*                        ASSIGNMENT OPERATOR                                 */
/* ************************************************************************** */
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cout << "[WrongCat]    Assignment operator called" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                              DESTRUCTOR                                    */
/* ************************************************************************** */
WrongCat::~WrongCat()
{
	std::cout <<"[WrongCat]    Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "[WrongCat]    meow meow meow" << std::endl;
}