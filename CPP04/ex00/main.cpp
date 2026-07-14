/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:54:07 by nchairun          #+#    #+#             */
/*   Updated: 2026/04/03 12:07:13 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); 
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    return 0;
}

// int main()
// {
//     const Animal* testAnimal = new Animal(); 
//     testAnimal->makeSound();

//     std::cout << "----------------------------------------------------" << std::endl;

//     const Animal* testCat = new Cat(); 
//     testCat->makeSound();

//     std::cout << "----------------------------------------------------" << std::endl;
//     const WrongAnimal* testWrongCat = new WrongCat(); 
//     testWrongCat->makeSound();

//     delete(testAnimal);
//     delete(testCat);
//     delete(testWrongCat);
// }

// int main()
// {
//     std::cout << " " << std::endl;
//     std::cout << "------------- Default Constructor Test ------------" << std::endl;
//     std::cout << " " << std::endl;

//     Animal a;

//     std::cout << " " << std::endl;
//     std::cout << "---------------- Copy Constructor Test -----------" << std::endl;
//     std::cout << " " << std::endl;
    
//     Animal black;
//     Animal white = black;   // copy constructor: Creates new object from another (initialize)

//     /* ***************************************************************************** */
//     std::cout << " " << std::endl;
//     std::cout << "-------------- Assignment Operator Test -----------" << std::endl;
//     std::cout << " " << std::endl;

//     Animal green;
//     Animal yellow;

//     green = yellow;           // copy assignment operator: Copies into existing object (overwrite)

//     /* ***************************************************************************** */
//     std::cout << " " << std::endl;
// 	std::cout << "--------------- Correct Polymorphism ---------------" << std::endl;
//     std::cout << " " << std::endl;

// 	const Animal* test_dog = new Dog();
// 	const Animal* test_cat = new Cat();

//     std::cout << " " << std::endl;
//     std::cout << "  test_dog->makeSound(): " << std::endl;
//      std::cout << " " << std::endl;
// 	test_dog->makeSound();

//     std::cout << " " << std::endl;
//     std::cout << "  test_cat->makeSound(): " << std::endl;
//     std::cout << " " << std::endl;
// 	test_cat->makeSound(); 
//     std::cout << " " << std::endl;

// 	delete (test_dog);
// 	delete (test_cat);

//     /* ***************************************************************************** */
//     std::cout << " " << std::endl;
// 	std::cout << "--------------- Wrong Polymorphism ---------------" << std::endl;
//     std::cout << " " << std::endl;

// 	const WrongAnimal* test_cat2 = new WrongCat();

//     std::cout << " " << std::endl;
//     std::cout << "  test_cat2->makeSound(): " << std::endl;
//     std::cout << " " << std::endl;
// 	test_cat2->makeSound(); 
//     std::cout << " " << std::endl;

// 	delete (test_cat2);

// 	return (0);
// }