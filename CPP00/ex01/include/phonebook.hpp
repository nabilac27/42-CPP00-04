/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:26:56 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/12 21:08:49 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "../include/contact.hpp"
# include <iomanip>
# include <iostream>
# include <string>

class PhoneBook
{
private:
    Contact contacts[8];
    int countContacts;

public:
    PhoneBook();
    void add();
    void search();
};

void printMessage(const std::string &message);
bool checkValidNumber(const std::string &input);

#endif