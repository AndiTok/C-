/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:23:41 by atok              #+#    #+#             */
/*   Updated: 2024/05/21 03:23:41 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

using std::cout;

int main ()
{
	Base base;
	// A *a = new A;
	Base *output = base.generate();
	cout << output << '\n';

	base.identify(output);
	base.identify(*output);
	// base.identify(a);
	// base.identify(*a);
	return 0;
}