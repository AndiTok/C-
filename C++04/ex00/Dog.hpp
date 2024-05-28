/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:01:02 by atok              #+#    #+#             */
/*   Updated: 2023/08/21 13:01:57 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

// class Dog : virtual public Animal
class Dog : public Animal
{
	protected:

	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &rhs);
		~Dog();
		
	void makeSound() const; // need its own if not will use parent ft
};

#endif
