/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 23:13:55 by nchairun          #+#    #+#             */
/*   Updated: 2026/04/02 22:29:54 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

/* ************************************************************************** */
/*                            CONSTRUCTORS                                    */
/* ************************************************************************** */
Cat::Cat() : Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "[Cat]    Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	this->brain = new Brain(*other.brain);
	std::cout << "[Cat]    Copy constructor called" << std::endl;
}

/* ************************************************************************** */
/*                        ASSIGNMENT OPERATOR                                 */
/* ************************************************************************** */
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
	std::cout << "[Cat]    Assignment operator called" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                              DESTRUCTOR                                    */
/* ************************************************************************** */
Cat::~Cat()
{
	std::cout <<"[Cat]    Destructor called" << std::endl;
	delete (brain);
}

/* ************************************************************************** */
/*                              METHODS	                                      */
/* ************************************************************************** */
void Cat::makeSound() const
{
	std::cout << "[Cat]    meow meow meow" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return (brain->getIdea(index));
}