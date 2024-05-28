/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 00:18:17 by atok              #+#    #+#             */
/*   Updated: 2023/08/21 00:18:17 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &rhs);
		virtual ~WrongAnimal(); // so the dog and cat class can use their decon funtion
		
	std::string getType() const; 
	virtual void makeSound() const; 
	//virtual syntax allow the child/derived class to overide and run their ouwn funtion
};



#endif