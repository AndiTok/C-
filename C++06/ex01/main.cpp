/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:05:47 by atok              #+#    #+#             */
/*   Updated: 2024/05/21 01:05:47 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

using std::cout;

int main ()
{
	// Serializer a; // inaccessible 
	// cannot be initialized which is intended

	Data data;
	data.c = '*';
	data.i = 42;
	uintptr_t s;
	Data *ds;


	cout << "Originla address : " << &data << "\n";
	
	s = Serializer::serialize(&data);
	cout << "Serialized address : " << s << "\n";
	// cout << reinterpret_cast<Data*>(s) << "\n";

	ds = Serializer::deserialize(s);
	cout << "Deserialize address : " <<ds << "\n";
	cout << ds->c << "\n";
	cout << ds->i << "\n";

	cout << "Modify data...\n";

	ds->c = 'x';
	ds->i = -42;
	cout << ds->c << "\n";
	cout << ds->i << "\n";
	return 0;
}