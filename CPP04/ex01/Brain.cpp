/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:24:46 by nchairun          #+#    #+#             */
/*   Updated: 2026/04/02 23:27:46 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/*                            CONSTRUCTORS                                    */
/* ************************************************************************** */
Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "[Brain]  ideas called";
    
	std::cout << "[Brain]  Default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << "[Brain]  Copy constructor called" << std::endl;
}

/* ************************************************************************** */
/*                        ASSIGNMENT OPERATOR                                 */
/* ************************************************************************** */
Brain& Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	std::cout << "[Brain]  Copy assignment operator called" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                              DESTRUCTOR                                    */
/* ************************************************************************** */
Brain::~Brain()
{
	std::cout << "[Brain]  Destructor called"<<std::endl;
}

/* ************************************************************************** */
/*                              METHODS	                                      */
/* ************************************************************************** */
void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
		this->ideas[index] = idea;
    else
	    std::cout << "[Brain]  Invalid idea index" << std::endl;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
		return (this->ideas[index]);
    else
    {
	    std::cout << "[Brain]  Invalid idea index" << std::endl;
	    return ("");
    }
}