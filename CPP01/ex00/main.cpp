/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:26:40 by nchairun          #+#    #+#             */
/*   Updated: 2025/11/02 14:41:03 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

int main() {
    randomChump("Stack Zombie");
     
    Zombie* zombie1 = newZombie("Heap Zombie");
    zombie1->announce();
    delete (zombie1); 
    
    return (0);
}
