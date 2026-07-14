/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:06:08 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/12 21:08:34 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/phonebook.hpp"

int main() {
    PhoneBook phonebook;
    std::string command;
    
    printMessage("\n=========================================\n");       
    printMessage("                 PHONEBOOK               \n");
    printMessage("=========================================\n");

    while (true) {
        printMessage("\033[32m\nEnter a command (ADD, SEARCH, EXIT): ");
        std::getline(std::cin, command);
        printMessage("\n");
        
        if (command == "ADD")
            phonebook.add();
        else if (command == "SEARCH")
            phonebook.search();
        else if (command == "EXIT")
            break;
        else
            printMessage("\n\033[31mInvalid Input\n\n");
    }

    return 0;
}

