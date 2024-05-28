/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:25:37 by atok              #+#    #+#             */
/*   Updated: 2023/08/25 14:25:37 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
    private:
    
    public:
        Ice();
        Ice(const Ice &copy);
        Ice &operator=(const Ice &rhs);
        ~Ice();

        AMateria *clone() const;
        void use(ICharacter &target);
};

#endif