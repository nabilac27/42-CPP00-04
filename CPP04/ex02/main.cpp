/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:54:07 by nchairun          #+#    #+#             */
/*   Updated: 2026/04/03 13:15:08 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
// 	const Animal *j = new Dog();
// 	const Animal *i = new Cat();
// 	delete j; // should not create a leak
// 	delete i;
// }


int main()
{
	// Animal a; // will fail

    const Animal* a = new Dog();

    a->makeSound();

    delete a;

    return 0;
}