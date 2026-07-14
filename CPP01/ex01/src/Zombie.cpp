/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:03:30 by nchairun          #+#    #+#             */
/*   Updated: 2025/11/02 16:59:29 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie() : name("") {}

Zombie::Zombie(std::string n) : name(n) {}

Zombie::~Zombie() 
{
    std::cout << name << ": destroyed" << std::endl;
}

void Zombie::announce() 
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setZombie(std::string name)
{
    this->name = name;
}