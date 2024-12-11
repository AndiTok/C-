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

template <typename T, typename Container = std::deque<T> > // '>>' needs to be '> >'
class MutantStack : public std::stack<T, Container>
{
	private:

	public:
	MutantStack() : std::stack<T, Container>() {}
	MutantStack(const MutantStack &copy) : std::stack<T, Container>(copy) {}
	MutantStack& operator=(const MutantStack &rhs)
	{
		if (this != &rhs)
			std::stack<T, Container>::operator=(rhs);
		return *this;
	}
	~MutantStack() {}

	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return std::stack<T, Container>::c.end(); }
};

#endif