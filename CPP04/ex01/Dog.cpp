/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 23:15:20 by nchairun          #+#    #+#             */
/*   Updated: 2026/04/03 12:41:01 by nchairun         ###   ########.fr       */
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
	brain = new Brain();
	std::cout << "[Dog]    Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	this->brain = new Brain(*other.brain);
	std::cout << "[Dog]    Copy constructor called" << std::endl;
}

/* ************************************************************************** */
/*                        ASSIGNMENT OPERATOR                                 */
/* ************************************************************************** */
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	std::cout << "[Dog]    Assignment operator called" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                              DESTRUCTOR                                    */
/* ************************************************************************** */
Dog::~Dog()
{
	std::cout <<"[Dog]    Destructor called" << std::endl;
	delete (brain);
}

/* ************************************************************************** */
/*                              METHODS	                                      */
/* ************************************************************************** */
void Dog::makeSound() const
{
	std::cout << "[Dog]    woof woof woof" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return (brain->getIdea(index));
}