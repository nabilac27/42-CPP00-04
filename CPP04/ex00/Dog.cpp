/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 23:15:20 by nchairun          #+#    #+#             */
/*   Updated: 2026/04/03 11:32:10 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

/* ************************************************************************** */
/*                            CONSTRUCTORS                                    */
/* ************************************************************************** */
Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "[Dog]    Default constructor called" << std::endl;
}

/* ************************************************************************** */
/*                        ASSIGNMENT OPERATOR                                 */
/* ************************************************************************** */
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "[Dog]    Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "[Dog]    Assignment operator called" << std::endl;
	return *this;
}

/* ************************************************************************** */
/*                              DESTRUCTOR                                    */
/* ************************************************************************** */
Dog::~Dog()
{
	std::cout <<"[Dog]    Destructor called" << std::endl;
}

/* ************************************************************************** */
/*                              METHODS	                                      */
/* ************************************************************************** */
void Dog::makeSound() const
{
	std::cout << "[Dog]    woof woof woof" << std::endl;
}