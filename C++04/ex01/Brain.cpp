/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:47:09 by atok              #+#    #+#             */
/*   Updated: 2023/08/21 19:56:55 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

using std::cout;

Brain::Brain() : _ideas()
{
	cout << "Default Brain constructor called\n";
	for (int i = 0; i < 100; i++)
		_ideas[i] = 100 + i;
}

Brain::Brain(const Brain &copy)
{
	cout << "Copy Brain constructor called\n";
	*this = copy;
}

Brain &Brain::operator=(Brain const &rhs)
{
	cout << "Brain Copy assingment operator called\n";
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = rhs.getIdeas(i);
		}
	}

	return *this;
}

Brain::~Brain()
{
	cout << "Brain Destructor called\n";
}

void Brain::setIdeas(int i , std::string ideas)
{
	_ideas[i] = ideas;
}

std::string Brain::getIdeas(int i) const
{
	return (this->_ideas[i]);
}