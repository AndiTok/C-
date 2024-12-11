/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:23:23 by atok              #+#    #+#             */
/*   Updated: 2024/05/21 16:23:23 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define	 ARRAY_HPP

#include <iostream>
#include <ctime>
#include <stdexcept>

template <class T>
class Array
{
	public:
	T *arr;
	unsigned int _size; // had to use _ due to naming issue

	Array()
	{
		// create empty array with new[]
		// this->arr = nullptr;
		this->arr = new T [0];
		this->_size = 0;
	}

	Array(unsigned int n)
	{
		// create array with n number with new[]
		this->arr = new T [n];
		this->_size = n;
	}

	Array(const Array &copy)
	{	
		*this = copy;
	}

	Array& operator=(const Array &rhs)
	{
		if (this != &rhs)
		{
			// shallow copy
			// this->arr = rhs.arr;
			// this->_size = rhs._size;
			
			//deep copy
			delete[] this->arr;
			this->arr = new T [rhs._size]; // deep copy
			this->_size = rhs._size;

			for(unsigned int i = 0; i < rhs._size; i++)
			{
				arr[i] = rhs.arr[i];
			}
		}
		return *this;
	}

	~Array()
	{
		delete [] arr;
	}

	T& operator[](int index)
	{
		if (index < 0 || index >= this->_size)
			throw std::runtime_error("-=Index is out of bound=-");
		return (arr[index]);
	}

	unsigned int size()
	{
		return this->_size;
	}
};

#endif