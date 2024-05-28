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
	// virtual void makeSound() const; //const required for compatibility due to main const Animal
	virtual void makeSound() const = 0; //virtual ft... = 0; turn this into pure virtual funtion which no one can invoke
	//virtual syntax allow the child/derived class to overide and run their ouwn funtion
};

#endif