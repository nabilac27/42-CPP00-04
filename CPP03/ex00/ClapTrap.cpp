/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:50:46 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/12 16:30:49 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/*                            CONSTRUCTORS                                    */
/* ************************************************************************** */

ClapTrap::ClapTrap() 
: name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "[ClapTrap] Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) 
: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "[ClapTrap] Parameterized constructor of " 
              << name 
              << "      called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "[ClapTrap] Copy constructor of " 
              << name 
              << "      called." << std::endl;
}

/* ************************************************************************** */
/*                        ASSIGNMENT OPERATOR                                 */
/* ************************************************************************** */

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		name            = other.name;
		hitPoints       = other.hitPoints;
		energyPoints    = other.energyPoints;
		attackDamage    = other.attackDamage;
	}
	std::cout << "[ClapTrap] Copy assignment operator of " 
              << name 
              << "      called." << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                              DESTRUCTOR                                    */
/* ************************************************************************** */

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] Destructor of" 
              << "                "
              << name 
              << "      called." 
              << std::endl;
}

/* ************************************************************************** */
/*                              ACTIONS                                       */
/* ************************************************************************** */

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints < 1 || energyPoints < 1)
    {
        std::cout << "[ClapTrap]"
                  << "                              "
                  << name 
                  << "      can't attack." 
                  << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "[ClapTrap]"
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

void	ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints < 1)
    {
        std::cout << "[ClapTrap]"
                  << "                              "
                  << name 
                  << "          can't take damage." 
                  << std::endl;
        return;
    }
    if (amount >= (unsigned int)hitPoints)
        hitPoints = 0;
    else
        hitPoints = hitPoints - amount;
    
    std::cout << "[ClapTrap]" 
              << "                              "
              << name 
              << "                          takes   " 
              << amount 
              << " points of damages!" 
              << "     EnergyPoints: " 
              << energyPoints 
              << "     HitPoints   : " 
              << hitPoints
              << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints < 1 || energyPoints < 1)
    {
        std::cout << "[ClapTrap]"
                  << "                              "
                  << name 
                  << "        can't be repaired." 
                  << std::endl;
        return;
    }
    energyPoints--;
	hitPoints = hitPoints + amount;
	std::cout << "[ClapTrap]"
              << "                              "
              << name
              << "      repairs,"
              << "            for     " 
              << amount 
              << " hit points!       " 
              << "     EnergyPoints: " 
              << energyPoints 
              << "     HitPoints   : " 
              << hitPoints
              << std::endl;
}
