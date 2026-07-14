/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:08:42 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/12 21:09:56 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"

void Contact::setContactInfo(std::string setFirstName, std::string setLastName, std::string setNickName,
                             std::string setPhoneNumber, std::string setDarkestSecret)
{
    firstName     = setFirstName;
    lastName      = setLastName;
    nickName      = setNickName;
    phoneNumber   = setPhoneNumber;
    darkestSecret = setDarkestSecret;
}

void Contact::displaySearch(int index)
{
    std::string displayFirstName = firstName;
    if (displayFirstName.length() > 10) {
        displayFirstName = displayFirstName.substr(0, 9);
        displayFirstName += ".";
    }

    std::string displayLastName = lastName;
    if (displayLastName.length() > 10) {
        displayLastName = displayLastName.substr(0, 9);
        displayLastName += ".";
    }

    std::string displayNickName = nickName;
    if (displayNickName.length() > 10) {
        displayNickName = displayNickName.substr(0, 9);
        displayNickName += ".";
    }

    std::cout << std::setw(10) << index             << "|"
              << std::setw(10) << displayFirstName  << "|"
              << std::setw(10) << displayLastName   << "|"
              << std::setw(10) << displayNickName   << std::endl;
}


void Contact::displayContacts()
{
    printMessage("\n-----------------------------------------\n"); 
    printMessage("              CONTACT INFO               \n");
    printMessage("-----------------------------------------\n");        

    std::cout << "First Name     : " << firstName    << std::endl;
    std::cout << "Last Name      : "   << lastName     << std::endl;
    std::cout << "Nickname       : "   << nickName     << std::endl;
    std::cout << "Phone Number   : "   << phoneNumber  << std::endl;
    std::cout << "Darkest Secret : "   << darkestSecret<< std::endl;
    std::cout << std::endl;
}
