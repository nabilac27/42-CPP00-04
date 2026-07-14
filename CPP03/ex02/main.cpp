/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 12:18:33 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/12 18:39:35 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// int main()
// {
//     ClapTrap clapA("ClapA");
//     FragTrap fragD("FragD");

//     clapA.attack("FragD");
//     fragD.takeDamage(5);
//     fragD.beRepaired(3);

//     fragD.attack("ClapA");
//     clapA.takeDamage(20);

//     fragD.highFivesGuys();
    
//     return (0);
// }

int main()
{
    ClapTrap a("ClapA");
    FragTrap b("FragD");

    std::cout << "\n--------- FRAGTRAP ATTACK TEST ---------\n" << std::endl;
    b.attack("ClapA");
    a.takeDamage(30);

    std::cout << "\n--------- HIGH FIVES GUYS TEST ---------\n" << std::endl;
    b.highFivesGuys();

    std::cout << "\n--------- NO ENERGY TEST ---------\n" << std::endl;
    for (int i = 0; i < 101; i++)
        b.attack("ClapA");

    std::cout << "\n--------- DEATH TEST ---------\n" << std::endl;
    b.takeDamage(200);
    b.attack("ClapA");
    b.beRepaired(5);

    std::cout << "\n-------------------------------\n" << std::endl;
    return 0;
}

/*
    CLAPTRAP
        - HitPoints         = 10
        - EnergyPoints      = 10
        - AttackDamage      = 0

        - attack()          = -1 EnergyPoints
        - takeDamage()      = -x HitPoints
        - beRepaired()      = -1 EnergyPoints  &  +x HitPoints
    
    SCAVTRAP
        - HitPoints         = 100
        - EnergyPoints      = 50
        - AttackDamage      = 20
    
        - Override Function = attack()
        - Special Actions   = guardGate()

    FRAGTRAP
        - HitPoints         = 100
        - EnergyPoints      = 100
        - AttackDamage      = 30
    
        - Special Actions   = highFivesGuys()
*/
