/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:42:45 by atok              #+#    #+#             */
/*   Updated: 2023/08/20 15:42:45 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// const Animal *a = new Animal();
	// allocating an object of abstract class type 'Animal'
	// object of abstract class type "Animal" is not allowed:C/C++(322)
	// main.cpp(21, 24): function "Animal::makeSound" is a pure virtual function
// main.cpp:21:24: error: allocating an object of abstract class type 'Animal'
//         const Animal *a = new Animal();
//                               ^
// ./Animal.hpp:34:15: note: unimplemented pure virtual method 'makeSound' in 'Animal'
//         virtual void makeSound() const = 0; //virtual ft... = 0; turn this into pure virtual funtion which no one can invoke
	// Animal.hpp line 34 "virtual void makeSound() const = 0;"
	// std::cout << "\n";
	
	// a->makeSound();
	// std::cout << "\n";

	
	const Animal* i = new Cat();
	std::cout << "\n";
	const Animal* j = new Dog(); 
	std::cout << "\n";
	i->makeSound();
	delete i;
	std::cout << "\n";
	j->makeSound();
	delete j;
	std::cout << "\n";

	Cat *k = new Cat(); 
	std::cout << "\n";
	Cat *l = new Cat(*k);
	std::cout << "\n";
	k->makeSound();
	l->makeSound();
	std::cout << "address k: " << &k << std::endl;
	std::cout << "address l: " << &l << std::endl;
	delete l;
	std::cout << "\n";
	k->makeSound();

	Dog *m = new Dog(); 
	std::cout << "\n";
	Dog *n = new Dog(*m); 
	std::cout << "\n";
	m->makeSound();
	n->makeSound();
	std::cout << "address m: " << &m << std::endl;
	std::cout << "address n: " << &n << std::endl;
	delete n;
	std::cout << "\n";
	m->makeSound();
}