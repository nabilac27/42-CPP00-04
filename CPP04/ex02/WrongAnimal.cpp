/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 23:17:03 by nchairun          #+#    #+#             */
/*   Updated: 2026/04/02 22:29:05 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ************************************************************************** */
/*                            CONSTRUCTORS                                    */
/* ************************************************************************** */
WrongAnimal::WrongAnimal() : type("Default")
{
	std::cout << "[WrongAnimal] Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "[WrongAnimal] Copy constructor called" << std::endl;
}

/* ************************************************************************** */
/*                        ASSIGNMENT OPERATOR                                 */
/* ************************************************************************** */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		type = other.type;
		std::cout << "[WrongAnimal] Assignment operator called" << std::endl;
	}
	return (*this);
}

/* ************************************************************************** */
/*                              DESTRUCTOR                                    */
/* ************************************************************************** */
WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (type);
}

/* ************************************************************************** */
/*                              METHODS	                                      */
/* ************************************************************************** */
void WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal] WrongAnimal makes sound" << std::endl;
}