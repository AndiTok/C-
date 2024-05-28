/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:39:26 by atok              #+#    #+#             */
/*   Updated: 2023/08/21 12:40:31 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

// class Cat : virtual public Animal
class Cat : public Animal
{
	protected:

	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &rhs);
		~Cat();

	void makeSound() const; // need its own if not will use parent ft
};

#endif