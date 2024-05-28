/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:22:14 by atok              #+#    #+#             */
/*   Updated: 2023/07/20 21:22:14 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie()
		{
			static int i = 1;
			//_name = "Zombie ";
			//std::cout << _name << i <<" default constructor called\n";
			std::cout << i <<" default constructor called\n";
			//announce();
			i++;
		};
		Zombie(std::string name)
		{
			std::cout << "user defined constructor called to set name\n";
			_name = name;
			//announce();
		};
		~Zombie()
		{
			std::cout << "DEconstructed is called\n";
			// std::cout << this->_name << "DEconstructed\n";
		};
		void announce();
};

Zombie *zombieHorde( int N, std::string name );

#endif

/* Time to create a horde of Zombies!

Implement the following function in the appropriate file:
Zombie* zombieHorde( int N, std::string name );

It must allocate N Zombie objects in a single allocation. 
Then, it has to initialize the zombies, 
giving each one of them the name passed as parameter. 
The function returns a pointer to the first zombie.

Implement your own tests to ensure your zombieHorde() function works as expected.
Try to call announce() for each one of the zombies.
Don’t forget to delete all the zombies and check for memory leaks. */