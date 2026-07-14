/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:24:48 by nchairun          #+#    #+#             */
/*   Updated: 2025/11/01 15:17:20 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream> 
# include <string>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(std::string name);
  		~Zombie();
    	void announce();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif