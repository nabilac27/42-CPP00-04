/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:09:22 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/12 18:34:49 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapA("ClapA");
    ClapTrap clapB("ClapB");

    clapA.attack("ClapB");
    clapB.takeDamage(5);
    clapB.beRepaired(3);

    return (0);
}

// int main()
// {
//     ClapTrap a("ClapA");
//     ClapTrap b("ClapB");

//     std::cout << "\n--------- ATTACK TEST ---------\n" << std::endl;
//     a.attack("ClapB");
//     b.takeDamage(3);

//     std::cout << "\n--------- REPAIR TEST ---------\n" << std::endl;
//     b.beRepaired(2);

//     std::cout << "\n--------- NO ENERGY TEST ---------\n" << std::endl;
//     for (int i = 0; i < 11; i++)
//         a.attack("ClapB");

//     std::cout << "\n--------- Death test ---------\n" << std::endl;
//     b.takeDamage(10);
//     b.attack("ClapA");

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
*/
