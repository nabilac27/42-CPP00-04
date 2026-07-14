/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:26:34 by nchairun          #+#    #+#             */
/*   Updated: 2025/11/02 17:10:43 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "DEBUG    : I love having extra sauce for my burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "INFO     : I cannot believe adding extra sauce costs more money." << std::endl;
}

void Harl::warning()
{
	std::cout << "WARNING  : I think I deserve to have some extra sauce for free."  << std::endl;
}

void Harl::error()
{
	std::cout << "ERROR    : This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levelType[]        = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*harl_function[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (level == levelType[i])
        {
            (this->*harl_function[i]) (); // 
            return;
        }
    }

    std::cout << "Invalid Level" << std::endl;
}
