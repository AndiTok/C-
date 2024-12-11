/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 05:50:26 by atok              #+#    #+#             */
/*   Updated: 2024/05/21 05:50:26 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T> T max(T st, T nd)
{
	if (st == nd)
		return nd;
	else
		return (st > nd) ? st : nd;
}

template <typename T> T min(T st, T nd)
{
	if(st == nd)
		return nd;

	if (st < nd)
		return st;
	else
		return nd;
}

#endif