/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:10:40 by nchairun          #+#    #+#             */
/*   Updated: 2026/04/02 22:10:40 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/*                            CONSTRUCTORS                                    */
/* ************************************************************************** */
Animal::Animal() : type("Animal")
{
	std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "[Animal] Copy constructor called" << std::endl;
}

/* ************************************************************************** */
/*                        ASSIGNMENT OPERATOR                                 */
/* ************************************************************************** */
Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "[Animal] Copy assignment operator called" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                              DESTRUCTOR                                    */
/* ************************************************************************** */
Animal::~Animal()
{
	std::cout << "[Animal] Destructor called"<<std::endl;
}

std::string	Animal::getType(void) const
{
	return (type);
}

/* ************************************************************************** */
/*                              METHODS	                                      */
/* ************************************************************************** */
void Animal::makeSound() const
{
    std::cout << "[Animal] Animal makes sound" << std::endl;
}
