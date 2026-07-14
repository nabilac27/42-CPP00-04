/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:13:51 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/12 21:10:08 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

PhoneBook::PhoneBook()
{
    countContacts = 0;
}

void PhoneBook::add()
{
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

    // ----- asking for contact info ----- //
    while (true) {
        std::cout << "\nFirst Name     : ";
        std::getline(std::cin, firstName);
        if (!firstName.empty()) break;
        std::cout << "\033[31mCan't be empty!\033[0m" << std::endl;
    }

    while (true) {
        std::cout << "Last Name      : ";
        std::getline(std::cin, lastName);
        if (!lastName.empty()) break;
        std::cout << "\033[31mCan't be empty!\033[0m" << std::endl;
    }

    while (true) {
        std::cout << "Nickname       : ";
        std::getline(std::cin, nickName);
        if (!nickName.empty()) break;
        std::cout << "\033[31mCan't be empty!\033[0m" << std::endl;
    }

    while (true) {
        std::cout << "Phone Number   : ";
        std::getline(std::cin, phoneNumber);
        if (!phoneNumber.empty() && checkValidNumber(phoneNumber) ) break;
        std::cout << "\033[31mCan't be empty and must contain only digits!\033[0m" << std::endl;
    }

    while (true) {
        std::cout << "Darkest Secret : ";
        std::getline(std::cin, darkestSecret);
        if (!darkestSecret.empty()) break;
        std::cout << "\033[31mCan't be empty!\033[0m" << std::endl;
    }

    // ----- save contact ----- //
    if (countContacts < 8) {
        contacts[countContacts].setContactInfo(firstName, lastName, nickName, phoneNumber, darkestSecret);
        countContacts++;
    } 
    else 
        contacts[7].setContactInfo(firstName, lastName, nickName, phoneNumber, darkestSecret);

    printMessage("\033[32m\nContact Added\n");
};


void PhoneBook::search() {
    if (countContacts == 0)
        return;

    printMessage("\n-----------------------------------------\n"); 
    printMessage("            PHONEBOOK SEARCH             \n");
    printMessage("-----------------------------------------\n\n");   
    
    std::cout << std::setw(10) << "Index"       << "|"
              << std::setw(10) << "First Name"  << "|"
              << std::setw(10) << "Last Name"   << "|"
              << std::setw(10) << "Nickname"    << std::endl;
    printMessage("--------------------------------------------\n");
    
    for (int i = 0; i < countContacts; i++)
        contacts[i].displaySearch(i);

    // ----- asking for index to view contact info ----- //
    std::string input;
    
    printMessage("\n\033[32mEnter index to view contact information: ");
    std::getline(std::cin, input);
    
    if (checkValidNumber(input) == false)
    {
        printMessage("\n\033[31mInvalid Index\n");
        return;
    }
    
    int index = std::stoi(input);

    if (index < 0 || index >= countContacts) {
        printMessage("\n\033[31mInvalid Index \n");
        return;
    }

    contacts[index].displayContacts();
};


bool checkValidNumber(const std::string &input) {
    if (input.empty()) 
        return false;

    size_t i = 0;
    while (i < input.length()) {
        if (input[i] < '0' || input[i] > '9') {
            return false;
        }
        i++;
    }

    return true;
}

void printMessage(const std::string &message)
{
    std::cout << message << "\033[0m";
}