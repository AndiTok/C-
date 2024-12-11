/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 03:53:21 by atok              #+#    #+#             */
/*   Updated: 2024/05/28 03:53:21 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <deque>
#include <list>
#include <algorithm> // std::find()
#include <iterator> // std::distance()
// #include <array> // only in C++11

/* returns type T to store */
template <typename T>
typename T::iterator easyfind(T &hay, int needle) // use T& to reference and not just T to copy
{												// will cause std::distance() to return weird value
	typename T::iterator it;
	it = std::find(hay.begin(), hay.end(), needle);
	if(it != hay.end())
		return it;
	else
		throw std::runtime_error("-=Value not found=-");
		// return hay.end();


	/* without using std::find() */
	// typename T::iterator it = hay.begin();
	// for (; it != hay.end(); ++it)
	// {
	// 	if (*it == needle)
	// 		return it;
	// }
	// throw std::runtime_error("Value not found");
	// }
}

/* returns an error value */
// template <typename T>
// int easyfind(T &hay, int needle) // does not matter if using T or T&
// {
// 	typename T::iterator it;
// 	it = std::find(hay.begin(), hay.end(), needle);
// 	if(it == hay.end())
// 		return 1;
// }

/* the simplest form */
// template <typename T> 
// void easyfind(T &hay, int needle) // does not matter if using T or T&
// {
// 	typename T::iterator it;
// 	it = std::find(hay.begin(), hay.end(), needle);
// 	if(it == hay.end())
// 		throw std::runtime_error("Value not found");
// }

#endif