/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 07:45:45 by atok              #+#    #+#             */
/*   Updated: 2024/05/28 07:45:45 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <limits>

template <typename T>
class Span
{
private:
    unsigned int _N; // container size limit
    T _container;    // container to store numbers

public:
    Span();
    Span(unsigned int N);
    Span(const Span &copy);
    Span& operator=(const Span &rhs);
    ~Span();

    void addNumber(int number); // check if _N exceeded before push_back()
    int shortestSpan() const;   // return shortest span between all numbers stored
    int longestSpan() const;    // return longest span between all numbers stored
    void addNumber(typename T::iterator start, typename T::iterator end); // adds many numbers in 1 call
};

#include "Span.tpp" // <<
#endif
