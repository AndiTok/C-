/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 02:57:51 by atok              #+#    #+#             */
/*   Updated: 2024/05/21 02:57:51 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

using std::cout;

Base* Base::generate(void)
{
	// std::random_device rd;
	// std::uniform_int_distribution<int>dist(1,3);
	// int output = dist(rd);

	static int i = 0;
	srand(time(0) + i++);
	int output = 1 + rand() % 3;

	cout << output << "\n";
	
	if(output == 1)
		return new A;
	else if( output == 2)
		return new B;
	else
		return new C;
}

void Base::identify(Base* p)
{
	// if (A* a = dynamic_cast<A*>(p))
	// 	// cout << a << '\n';
	// 	cout << "Object is of type A\n";
	// else if (B* b = dynamic_cast<B*>(p))
	// 	cout << "Object is of type B\n";
	// else if (C* c = dynamic_cast<C*>(p))
	// 	cout << "Object is of type C\n";

	if (dynamic_cast<A*>(p)) // attemp to downcast from Base to A ,B or C
		cout << "Object is of type A\n";
	else if (dynamic_cast<B*>(p))
		cout << "Object is of type B\n";
	else if (dynamic_cast<C*>(p))
		cout << "Object is of type C\n";

	// if(dynamic_cast<A*>(p) != nullptr)
	// 	cout << "Object is A!" << '\n';
	// else if(dynamic_cast<B*>(p) != nullptr)
	// 	cout << "Object is B!" << '\n';
	// else
	// 	cout << "Object is C!" << '\n';
}

void Base::identify(Base& p)
{
	// try
	// {
	// 	/* code */
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	try
	{
		// A a = dynamic_cast<A&>(p);
		dynamic_cast<A&>(p);
		// cout << &p << '\n';
		cout << "Object is of type A\n";
	}
	catch(const std::exception& e) {} //blank to prevent printing error & stopping

	try
	{
		// B &b = dynamic_cast<B&>(p);
		dynamic_cast<B&>(p);
		cout << "Object is of type B\n";
	}
	catch(const std::exception& e) {
		// cout << "Object is of type C\n";
	}

	try
	{
		// C &c = dynamic_cast<C&>(p);
		dynamic_cast<C&>(p);
		cout << "Object is of type C\n";
	}
	catch(const std::exception& e) {}

}