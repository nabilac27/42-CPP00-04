/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:24:44 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/12 17:58:14 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
/*                            CONSTRUCTORS                                    */
/* ************************************************************************** */

FragTrap::FragTrap() 
: ClapTrap("default")
{
    hitPoints    = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "[FragTrap] Default constructor called." << std::endl;
}


FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints    = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "[FragTrap] Parameterized constructor of " 
              << name 
              << "      called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    *this = other;
	std::cout << "[FragTrap] Copy constructor of " 
              << name 
              << "      called." << std::endl;
}

/* ************************************************************************** */
/*                        ASSIGNMENT OPERATOR                                 */
/* ************************************************************************** */

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
	std::cout << "[FragTrap] Copy assignment operator of " 
              << name 
              << "      called." << std::endl;
    return (*this);
}

/* ************************************************************************** */
/*                              DESTRUCTOR                                    */
/* ************************************************************************** */

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] Destructor of" 
              << "                "
              << name 
              << "      called." 
              << std::endl;
}

/* ************************************************************************** */
/*                              ACTIONS                                       */
/* ************************************************************************** */

void FragTrap::highFivesGuys(void)
{
    std::cout << "[FragTrap]"
              << "                              "
              << name 
              << "      requests a positive high five!" 
              << std::endl;
}