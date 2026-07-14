/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:37:07 by nchairun          #+#    #+#             */
/*   Updated: 2025/11/02 17:06:24 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string  value     = "HI THIS IS BRAIN";
    std::string* stringPTR = &value;        
    std::string& stringREF = value;          

    std::cout << "\n\033[32mPRINT MEMORY ADDRESS \033[0m" << std::endl;
    std::cout << "--------------------" << std::endl;
    
    std::cout << "Memory address of string variable : " << &value << std::endl;
    std::cout << "Memory address held by PTR        : " << stringPTR << std::endl;
    std::cout << "Memory address held by REF        : " << &stringREF << std::endl;

    std::cout << "\n\033[32m    PRINT VALUE \033[0m" << std::endl;
    std::cout << "--------------------" << std::endl;

    std::cout << "Value of string variable          : " << value << std::endl;
    std::cout << "Value pointed by PTR              : " << *stringPTR << std::endl;
    std::cout << "Value pointed by REF              : " << stringREF << std::endl;

    return (0);
}


