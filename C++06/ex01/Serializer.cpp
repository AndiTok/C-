/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:03:39 by atok              #+#    #+#             */
/*   Updated: 2024/05/21 01:03:39 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

using std::cout;

Serializer::Serializer()
{
	cout << "Default Serializer constructor called\n";
}

Serializer::Serializer(const Serializer &copy)
{
	cout << "Copy Serializer constructor called\n";
}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	cout << "Copy assingment constructor Serializer called\n";
	return *this;
}

Serializer::~Serializer()
{
	cout << "Deconstructor Serializer called\n";
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}