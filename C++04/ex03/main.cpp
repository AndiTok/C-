/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:21:29 by atok              #+#    #+#             */
/*   Updated: 2023/08/28 18:24:27 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

int main() 
{
	IMateriaSource* src = new MateriaSource(); 
	src->learnMateria(new Ice()); 
	src->learnMateria(new Cure());
	// src->learnMateria(new Ice()); 
	// src->learnMateria(new Cure());
	// src->learnMateria(new Ice()); 

	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice"); // << Ameteria* = IMateria*
	me->equip(tmp);
	me->unequip(0);
	tmp = src->createMateria("cure"); 
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure"); 
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure"); 
	me->equip(tmp);

	ICharacter* bob = new Character("bob"); 
	
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	delete bob; 
	delete me; 
	delete src;
	
	return 0; 
}

//Materail = Magic
//can learn a max of 4 magic type
//can only create magic that is learned
//can only equip/store what is created
//character has only 4 slots therefor can only equip/store/keep 4 magic
//can only use the magic that is learned,created and stored in character inventory
//when unequip, it will be store in temporary space to be deleted WHILE the 4 inventory slot remains
//weh storing magic, it will find the 1st empty slot in inventory

//treat AMateria & Ice/Cure like Claptrap &FragTrap/ScavTrap with alittlle bit of Fixpoint & Point
//the child/derived class will use the Abstarct class as a template
//Abstract funtion will be overided if the child/derived class has the same funtion
//funtions in child/derived class will be prioritized 1st  child/derived > parent/abstarct
//treat Interface class (I...)as a reference to & for the Concrete class 
//Concrete class will have all public fuctnion of interface & more 