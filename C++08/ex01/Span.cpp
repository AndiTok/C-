/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:30:11 by atok              #+#    #+#             */
/*   Updated: 2024/05/28 10:30:11 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Default constructor
Span::Span() : _N(0) {}

// Parameterized constructor
Span::Span(unsigned int N) : _N(N) {}

// Copy constructor
Span::Span(const Span &copy) : _N(copy._N), _container(copy._container) {}

// Assignment operator
Span& Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_N = rhs._N;
		_container = rhs._container;
	}
	return *this;
}

// Destructor
Span::~Span() {}

// Add a single number
void Span::addNumber(int number)
{
	if (_container.size() >= _N)
	{
		throw std::out_of_range("Container is full!");
	}

	// add back
	_container.push_back(number);
}

// Find the shortest span
int Span::shortestSpan() const
{
	if (_container.size() < 2)
	{
		throw std::logic_error("Not enough elements to find shortestSpan");
	}

	std::vector<int> tmp(_container.begin(), _container.end()); // copy the array
	std::sort(tmp.begin(), tmp.end()); // sort array ascending

	int min = INT_MAX; // start with INT_MAX
	for (std::vector<int>::iterator i = tmp.begin() + 1; i != tmp.end(); ++i)
	{
		// if the difference < min replace min
		if (*i - *(i - 1) < min)
			min = *i - *(i - 1);
	}
	return min;
}

// Find the longest span
int Span::longestSpan() const
{
	if (_container.size() < 2)
	{
		throw std::logic_error("Not enough elements to find longetSpan");
	}

	// get the biggest element - smallest element 
	std::vector<int>::const_iterator small = std::min_element(_container.begin(), _container.end());
	std::vector<int>::const_iterator big = std::max_element(_container.begin(), _container.end());

	return *big - *small;
}

// Add multiple numbers
void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (std::distance(start, end) + _container.size() > _N)
	{
		throw std::out_of_range("Adding these numbers would exceed Span capacity");
	}

	// start adding from the end of container/array
	_container.insert(_container.end(), start, end);
}
