/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:30:15 by atok              #+#    #+#             */
/*   Updated: 2024/05/28 10:30:15 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream> // print
#include <exception> // throw
#include <algorithm> // sort
#include <iterator> // i++
#include <vector> // container
// #include <limits>
#include <climits> // INT_MAX
#include <ctime> // time()

class Span
{
	private:

	public:
	unsigned int _N; // container size limit
	std::vector<int> _container; // container to store numbers
	Span();
	Span(unsigned int N);
	Span(const Span &copy);
	Span& operator=(const Span &rhs);
	~Span();

	void addNumber(int number); // check if _N exceeded before push_back()
	int shortestSpan() const;   // return shortest span between all numbers stored
	int longestSpan() const;    // return longest span between all numbers stored
	void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end); // adds many numbers in 1 call
};

#endif