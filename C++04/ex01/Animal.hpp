/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:44:27 by atok              #+#    #+#             */
/*   Updated: 2023/08/20 15:44:27 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &rhs);
		// ~Animal();
		virtual ~Animal(); // virtual is used so the dog & cat class can use their decon funtion
		
	std::string getType() const; //const required for compatibility due to main const Animal
	// void makeSound() const;
	virtual void makeSound() const; //const required for compatibility due to main const Animal
	//virtual syntax allow the child/derived class to overide and run their ouwn funtion
};

#endif

// virtual syntax in a sense tells the computer it can be overridded/overloaded by derived
// the Animal is declared as a pointer that holds either Cat or Dog (heap)
// we dont need to use class Cat/Dog : "virtual" public Animal ???
// as it is not a hybrid inheritence but multiple inheritence
// BUT mainly because in this case we are deling with heap memory "new" & *
// also is in reverse this case becase we need them to use their on decon
// by making "virtual" ~Animal() it will then deconstruce/delete correctly