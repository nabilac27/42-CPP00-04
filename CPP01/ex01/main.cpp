/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:06:26 by nchairun          #+#    #+#             */
/*   Updated: 2025/11/02 17:00:30 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

int main()
{
    int N = 5;
    std::string name = "Test Zombie";

    Zombie* horde = zombieHorde(N, name);

    for (int i = 0; i < N; i++)
        horde[i].announce();

    delete[] (horde);
    return (0);
}
