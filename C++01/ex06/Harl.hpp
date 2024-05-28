/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:58:42 by atok              #+#    #+#             */
/*   Updated: 2023/07/26 16:58:42 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	private:
		void  debug(void);
		void  info(void);
		void  warning(void);
		void  error(void);

	public:
		Harl();
		~Harl();
		void complain(std::string input);
		//typedef void (Harl::*ptr2memberFunction)(); 
};

#endif