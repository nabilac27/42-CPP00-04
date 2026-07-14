/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:17:09 by nchairun          #+#    #+#             */
/*   Updated: 2025/10/30 14:32:58 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void setContactInfo(std::string setFirstName, std::string setLastName, std::string setNickName,
                        std::string setPhoneNumber, std::string setDarkestSecret);
    void displaySearch(int index);
    void displayContacts();
};

void printMessage(const std::string &message);

#endif