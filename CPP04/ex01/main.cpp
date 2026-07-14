/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:54:07 by nchairun          #+#    #+#             */
/*   Updated: 2026/04/03 12:59:36 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j; // should not create a leak
	delete i;
}


// int main()
// {
//     std::cout << "----- With virtual destructor -----" << std::endl;
//     Animal* a = new Cat();
//     delete a;
// }

// int main()
// {
// 	// std::cout << " " << std::endl;
//     // std::cout << "--------------- 1 DOG IDEA TEST ---------------" << std::endl;
//     // std::cout << " " << std::endl;

// 	// Dog dog_a;

//     // dog_a.setIdea(0, "foods");

//     // std::cout << " " << std::endl;
//     // std::cout << dog_a.getIdea(0) << std::endl;
//     // std::cout << " " << std::endl;

//     // std::cout << " " << std::endl;
//     std::cout << "--------------- 2 DOGS IDEA TEST ---------------" << std::endl;
//     std::cout << std::endl;

//     Dog dog_a2;
//     dog_a2.setIdea(0, "foods");

//     Dog dog_b2 = dog_a2;  // copy constructor
//     dog_b2.setIdea(0, "sleep");

//     std::cout << "dog_a2: " 		<< std::endl;
//     std::cout << " " 				<< std::endl;
//     std::cout << dog_a2.getIdea(0)  << std::endl;
//     std::cout << " "				<< std::endl;

//     std::cout << "dog_b2: "			<< std::endl;
//     std::cout << " " 				<< std::endl;
//     std::cout << dog_b2.getIdea(0)  << std::endl;
//     std::cout << " " 				<< std::endl;

// 	return (0);
// }


// int main()
// {
// 	std::cout << "--------------- DOG IDEA TEST ---------------" << std::endl;
// 	std::cout << std::endl;

// 	Dog dog_a;
// 	dog_a.setIdea(0, "foods");

// 	std::cout << dog_a.getIdea(0) << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "--------------- DOG COPY TEST ---------------" << std::endl;
// 	std::cout << std::endl;

// 	Dog dog_a2;
// 	dog_a2.setIdea(0, "foods");

// 	Dog dog_b2 = dog_a2;
// 	dog_b2.setIdea(0, "sleep");

// 	std::cout << "dog_a2: " << dog_a2.getIdea(0) << std::endl;
// 	std::cout << "dog_b2: " << dog_b2.getIdea(0) << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "--------------- MULTIPLE DOG IDEAS TEST ---------------" << std::endl;
// 	std::cout << std::endl;

// 	Dog dog4;
// 	dog4.setIdea(0, "eat");
// 	dog4.setIdea(1, "sleep");
// 	dog4.setIdea(2, "play");

// 	std::cout << dog4.getIdea(0) << std::endl;
// 	std::cout << dog4.getIdea(1) << std::endl;
// 	std::cout << dog4.getIdea(2) << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "--------------- CAT COPY TEST ---------------" << std::endl;
// 	std::cout << std::endl;

// 	Cat cat_a;
// 	cat_a.setIdea(0, "fish");

// 	Cat cat_b = cat_a;
// 	cat_b.setIdea(0, "sleep");

// 	std::cout << "cat_a: " << cat_a.getIdea(0) << std::endl;
// 	std::cout << "cat_b: " << cat_b.getIdea(0) << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "--------------- ARRAY TEST ---------------" << std::endl;
// 	std::cout << std::endl;

// 	Animal* animals[4];
// 	animals[0] = new Dog();
// 	animals[1] = new Cat();
// 	animals[2] = new Dog();
// 	animals[3] = new Cat();

// 	for (int i = 0; i < 4; i++)
// 		animals[i]->makeSound();

// 	for (int i = 0; i < 4; i++)
// 		delete animals[i];

// 	std::cout << std::endl;

//     std::cout << "--------------- ARRAY BRAIN TEST ---------------" << std::endl;
// 	std::cout << std::endl;

// 	Animal* animals_b[4];

// 	animals_b[0] = new Dog();
// 	animals_b[1] = new Cat();
// 	animals_b[2] = new Dog();
// 	animals_b[3] = new Cat();

// 	// Set ideas (need cast because Animal doesn't have setIdea)
// 	((Dog*)animals_b[0])->setIdea(0, "bone");
// 	((Cat*)animals_b[1])->setIdea(0, "fish");
// 	((Dog*)animals_b[2])->setIdea(0, "run");
// 	((Cat*)animals_b[3])->setIdea(0, "sleep");

// 	std::cout << std::endl;

// 	// Print ideas
// 	std::cout << ((Dog*)animals_b[0])->getIdea(0) << std::endl;
// 	std::cout << ((Cat*)animals_b[1])->getIdea(0) << std::endl;
// 	std::cout << ((Dog*)animals_b[2])->getIdea(0) << std::endl;
// 	std::cout << ((Cat*)animals_b[3])->getIdea(0) << std::endl;

// 	std::cout << std::endl;

// 	// Clean up
// 	for (int i = 0; i < 4; i++)
// 		delete animals_b[i];

// 	return 0;
// }
