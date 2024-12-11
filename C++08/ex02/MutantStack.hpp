/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:52:13 by atok              #+#    #+#             */
/*   Updated: 2024/05/31 06:52:13 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream> // print
#include <iterator> // std::iterator
#include <stack> // Base class 
#include <cstdlib> // for c.

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
	MutantStack() : std::stack<T>(){} ;
	MutantStack(const MutantStack &copy) : std::stack<T>(copy){};
	MutantStack& operator=(const MutantStack &rhs)
	{
		if (this != &rhs)
			std::stack<T>::operator=(rhs);
		return *this;
	};
	~MutantStack() {};

	typedef typename std::stack<T>::container_type::iterator iterator; // define the type of iterator
	iterator begin() {return this->c.begin();}; // i = 0
	iterator end() {return std::stack<T>::c.end();}; //i = nullptr
};

#endif