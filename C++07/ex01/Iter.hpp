/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 06:49:20 by atok              #+#    #+#             */
/*   Updated: 2024/05/21 06:49:20 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* arr, size_t len , void (*funct)(T &))
{
	int i = 0;
	// while (arr[i] != 0x00)
	while (i < len)
	{
		funct(arr[i]);
		i++;
	}
}

template <typename T>
void iter(T* arr, size_t len , void (*funct)(T const &))
{
	int i = 0;
	// while (arr[i] != 0x00)
	while (i < len)
	{
		funct(arr[i]);
		i++;
	}
}

#endif