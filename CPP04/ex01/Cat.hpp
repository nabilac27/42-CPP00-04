/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 02:51:11 by nchairun          #+#    #+#             */
/*   Updated: 2026/04/02 22:37:30 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain* brain;

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat &other);
		~Cat();

	    void   		makeSound() const;

		void        setIdea(int indexIdea, const std::string& idea);
		std::string getIdea(int indexIdea) const;
};

/*
	Dog and Cat has own Brain*
	they must allocate it with new
	they must delete it in the destructor
	they must deep-copy it in copy constructor and assignment operator

	Shallow copy = Copy the pointer only
	Deep copy	 = Copy the actual data

	*/


#endif