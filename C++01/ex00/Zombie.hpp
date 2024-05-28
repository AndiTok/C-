/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:18:31 by atok              #+#    #+#             */
/*   Updated: 2023/07/19 18:18:31 by atok             ###   ########.fr       */
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
		// Zombie()
		// {
		// 	_name = "Foo ";
		// 	std::cout << this->_name << "constructed\n";
		// };
		Zombie(std::string name)
		{
			_name = name;
			std::cout << this->_name << "constructed\n";
		};
		~Zombie()
		{
			std::cout << this->_name << "DEconstructed\n";
		};
		void announce(void);
};

Zombie *newZombie( std::string name ); //heap allocated like C char * "malloc" but is "new" then keep/retrn or pass around untill "free"/"delete"
void randomChump( std::string name ); // stack allocated like auto create then delete once done

#endif