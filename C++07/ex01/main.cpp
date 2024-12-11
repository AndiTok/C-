/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:06:14 by atok              #+#    #+#             */
/*   Updated: 2024/05/21 07:06:14 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

using std::cout;

void intf(int &i)
{
	i = i + 1;
}

void floatf(float &i)
{
	i = i + 0.1f;
}

void doublef(double &i)
{
	i = i + 0.1;
}

void charf(char &i)
{
	i = i + 32;
}

int main()
{
	cout << "int\n";
	int iarr[] = {1,2,3,4};
	size_t ilen = sizeof(iarr) / sizeof(iarr[0]);

	for(int i = 0; i < ilen; i++)
		cout << iarr[i] << ' ';
	
	cout << '\n';

	iter(iarr,ilen,intf);

	for(int i = 0; i < ilen; i++)
		cout << iarr[i] << ' ';

	cout << '\n';
//--------------------------------------------------------
	cout << "\nfloat\n";
	float faar[] = {1.1f,2.1f,3.1f,4.1f};
	size_t flen = sizeof(faar) / sizeof(faar[0]);

	for(int i = 0; i < flen; i++)
		cout << faar[i] << "f ";
	
	cout << '\n';

	iter(faar,flen,floatf);

	for(int i = 0; i < flen; i++)
		cout << faar[i] << "f ";

	cout << '\n';
//--------------------------------------------------------
	cout << "\ndouble\n";
	double darr[] = {1.5,2.5,3.5,4.5};
	size_t dlen = sizeof(darr) / sizeof(darr[0]);

	for(int i = 0; i < dlen; i++)
		cout << darr[i] << ' ';
	
	cout << '\n';

	iter(darr,dlen,doublef);

	for(int i = 0; i < dlen; i++)
		cout << darr[i] << ' ';

	cout << '\n';
//--------------------------------------------------------
	cout << "\nchar\n";
	char carr[] = "HELLO WORLD";
	size_t clen = sizeof(carr) / sizeof(carr[0]);

	for(int i = 0; i < clen; i++)
		cout << carr[i];
	
	cout << '\n';

	iter(carr,clen,charf);

	for(int i = 0; i < clen; i++)
		cout << carr[i];

	cout << '\n';
}

// class Awesome
// {
// public:
// Awesome( void ) : _n( 42 ) { return; }
// int get( void ) const { return this->_n; }
// private:
// int _n;
// };
// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
// template< typename T >
// void print( T const & x ) { std::cout << x << std::endl; return; }
// int main() {
// int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
// Awesome tab2[5];
// iter( tab, 5, print );
// iter( tab2, 5, print );
// return 0;
// }

/* If everything went well, it should display:
0
1
2
3
4
42
42
42
42
42 */