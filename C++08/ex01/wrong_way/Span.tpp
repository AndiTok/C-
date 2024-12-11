/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 07:41:27 by atok              #+#    #+#             */
/*   Updated: 2024/05/28 07:41:27 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Default constructor
template <typename T>
Span<T>::Span() : _N(0) {}

// Parameterized constructor
template <typename T>
Span<T>::Span(unsigned int N) : _N(N) {}

// Copy constructor
template <typename T>
Span<T>::Span(const Span &copy) : _N(copy._N), _container(copy._container) {}

// Assignment operator
template <typename T>
Span<T>& Span<T>::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_N = rhs._N;
		_container = rhs._container;
	}
	return *this;
}

// Destructor
template <typename T>
Span<T>::~Span() {}

// Add a single number
template <typename T>
void Span<T>::addNumber(int number)
{
	if (_container.size() >= _N)
	{
		throw std::out_of_range("Span is already full");
	}
	_container.push_back(number);
}

// Find the shortest span
template <typename T>
int Span<T>::shortestSpan() const
{
	if (_container.size() < 2)
	{
		throw std::logic_error("Not enough elements to find a span");
	}

	T sorted(_container.begin(), _container.end());
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for (typename T::iterator it = sorted.begin() + 1; it != sorted.end(); ++it)
	{
		minSpan = std::min(minSpan, *it - *(it - 1));
	}
	return minSpan;
}

// Find the longest span
template <typename T>
int Span<T>::longestSpan() const
{
	if (_container.size() < 2)
	{
		throw std::logic_error("Not enough elements to find a span");
	}

	typename T::const_iterator minIt = std::min_element(_container.begin(), _container.end());
	typename T::const_iterator maxIt = std::max_element(_container.begin(), _container.end());
	return *maxIt - *minIt;
}

// Add multiple numbers
template <typename T>
void Span<T>::addNumber(typename T::iterator start, typename T::iterator end)
{
	// if the number of insert + current contaner size > allowed max size
	if (std::distance(start, end) + _container.size() > _N)
	{
		throw std::out_of_range("Adding these numbers would exceed Span capacity");
	}
	//.end() to append
	_container.insert(_container.end(), start, end);
}
