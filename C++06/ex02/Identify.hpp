/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 02:49:58 by atok              #+#    #+#             */
/*   Updated: 2024/05/21 02:49:58 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <iostream>
// #include <random>
#include <cstdlib>
#include <ctime>

class Base
{
	private:

	public:
	virtual ~Base() {};

	Base *generate(void);
	void identify(Base* p);
	void identify(Base& p);
};

class A : public Base
{
	private:

	public:
	~A() {}
};

class B : public Base
{
	private:

	public:
	~B() {}
};

class C : public Base
{
	private:

	public:
	~C() {}
};

#endif