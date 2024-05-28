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
	// const Animal* meta = new Animal();
	// std::cout << "\n";
	// const Animal* j = new Dog();
	// std::cout << "\n";
	// const Animal* i = new Cat();
	// //const WrongAnimal* i = new WrongCat();
	// std::cout << "\n";
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// std::cout << "\n";
	// j->makeSound(); //
	// i->makeSound(); //will output the cat sound!
	// meta->makeSound();
	// std::cout << "\n";
    // delete j;
    // delete i;
	// delete meta;
	
	std::cout << "\n";
	std::cout << "=========\n";
	std::cout << "\n";
	const WrongAnimal* w = new WrongAnimal();
	std::cout << "\n";
	const WrongAnimal* x = new WrongCat();
	std::cout << "\n";
	const WrongCat* y = new WrongCat();
	std::cout << "\n";
	w->makeSound();
	x->makeSound();
	y->makeSound();
	
	return 0;
}

//extercise is a combination of Zombie horde + Claptrap inheritence