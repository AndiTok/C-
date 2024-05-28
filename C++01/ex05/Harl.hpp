/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:20:35 by atok              #+#    #+#             */
/*   Updated: 2023/07/26 14:20:35 by atok             ###   ########.fr       */
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
		void complain(std::string level);
		//void (Harl::*complain_level)(std::string level) = &Harl::complain;
		typedef void (Harl::*ptr2memberFunction)();  // Typedef for pointer to member function
};

#endif