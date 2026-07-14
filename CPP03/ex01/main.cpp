/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:09:22 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/12 18:38:05 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clapA("ClapA");
    ClapTrap clapB("ClapB");
    ScavTrap scavC("ScavC");

    clapA.attack("ClapB");
    clapB.takeDamage(5);
    clapB.beRepaired(3);

    scavC.attack("ClapA");
    clapA.takeDamage(20);

    scavC.guardGate();
    
    return (0);
}

// int main()
// {
//     ClapTrap a("ClapA");
//     ClapTrap b("ClapB");
//     ScavTrap c("ScavC");

//     std::cout << "\n--------- CLAPTRAP ATTACK TEST ---------\n" << std::endl;
//     a.attack("ClapB");
//     b.takeDamage(3);

//     std::cout << "\n--------- CLAPTRAP REPAIR TEST ---------\n" << std::endl;
//     b.beRepaired(2);


//     std::cout << "\n--------- SCAVTRAP ATTACK TEST ---------\n" << std::endl;
//     c.attack("ClapA");
//     a.takeDamage(20);

//     std::cout << "\n--------- GUARD GATE TEST ---------\n" << std::endl;
//     c.guardGate();

//     std::cout << "\n--------- NO ENERGY TEST ---------\n" << std::endl;
//     for (int i = 0; i < 51; i++)
//         c.attack("ClapA");

//     std::cout << "\n--------- DEATH TEST ---------\n" << std::endl;
//     c.takeDamage(21);
//     c.attack("ClapA");
//     c.beRepaired(5);

//     std::cout << "\n-------------------------------\n" << std::endl;
//     return 0;
// }

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
*/
