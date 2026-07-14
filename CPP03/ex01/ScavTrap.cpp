/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:21:58 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/12 16:35:31 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/*                            CONSTRUCTORS                                    */
/* ************************************************************************** */

ScavTrap::ScavTrap() 
: ClapTrap("default")
{
    hitPoints    = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "[ScavTrap] Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) 
: ClapTrap(name)
{
    hitPoints    = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "[ScavTrap] Parameterized constructor of " 
              << name 
              << "      called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) 
: ClapTrap(other)
{
    *this = other;
	std::cout << "[ScavTrap] Copy constructor of " 
              << name 
              << "      called." << std::endl;
}

/* ************************************************************************** */
/*                        ASSIGNMENT OPERATOR                                 */
/* ************************************************************************** */

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        name         = other.name;
        hitPoints    = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
	std::cout << "[ScavTrap] Copy assignment operator of " 
              << name 
              << "      called." << std::endl;
    return (*this);
}

/* ************************************************************************** */
/*                              DESTRUCTOR                                    */
/* ************************************************************************** */

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] Destructor of" 
              << "                "
              << name 
              << "      called." 
              << std::endl;
}

/* ************************************************************************** */
/*                              ACTIONS                                       */
/* ************************************************************************** */

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints < 1 || energyPoints < 1)
    {
        std::cout << "[ScavTrap]"
                  << "                              "
                  << name 
                  << "      can't attack." 
                  << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "[ScavTrap]"
              << "                              "
              << name 
              << "      attacks " 
              << target 
              << ",      causing " 
              << attackDamage 
              << " points of damages!" 
              << "     EnergyPoints: " 
              << energyPoints 
              << "     HitPoints   : " 
              << hitPoints
              << std::endl;
}


void ScavTrap::guardGate()
{
    std::cout << "[ScavTrap]"
              << "                              "
              << name 
              << " is now in Gate keeper mode." 
              << std::endl;
}
