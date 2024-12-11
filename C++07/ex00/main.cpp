/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 06:16:02 by atok              #+#    #+#             */
/*   Updated: 2024/05/21 06:16:02 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

// class Awesome
// {
// public:
// Awesome(void) : _n(0) {}
// Awesome( int n ) : _n( n ) {}
// Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
// bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
// bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
// bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
// bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
// bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
// bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
// int get_n() const { return _n; }
// private:
// int _n;
// };
// std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }
// int main(void)
// {
// Awesome a(2), b(4);
// swap(a, b);
// std::cout << a << " " << b << std::endl;
// std::cout << max(a, b) << std::endl;
// std::cout << min(a, b) << std::endl;
// return (0);
// }

int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

// using std::cout;

// int main ()
// {
// 	int st = 42;
// 	int nd = -42;

// 	::swap(st,nd);
// 	cout << "st = " << st << ", nd = " << nd << '\n';
// 	cout << ::min(st,nd) << '\n';
// 	cout << ::max(st,nd) << '\n';

// 	cout << '\n';

// 	float f1 = 42.42f;
// 	float f2 = -42.42f;

// 	::swap(f1,f2);
// 	cout << "f1 = " << f1 << ", f2 = " << f2 << '\n';
// 	cout << ::min(f1,f2) << '\n';
// 	cout << ::max(f1,f2) << '\n';

// 	cout << '\n';

// 	std::string left = "Andi";
// 	std::string right = "Tok";
	
// 	::swap(left,right);
// 	cout << "left = " << left << ", right = " << right << '\n';
// 	cout << ::min(left,right) << '\n';
// 	cout << ::max(left,right) << '\n';
// }