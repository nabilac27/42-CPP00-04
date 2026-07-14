/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:06:58 by nchairun          #+#    #+#             */
/*   Updated: 2025/11/02 17:06:36 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

/*
    Human A:
        * Takes weapon as constructor
        * Always have a weapon
*/

class HumanA
{
    private:
        std::string name;
        Weapon& weapon;

    public:
        HumanA(const std::string& name, Weapon& weaponA);
        void attack() const;
};

#endif