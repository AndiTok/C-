/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:25:33 by atok              #+#    #+#             */
/*   Updated: 2023/08/25 14:25:33 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include <iostream>

#include "AMateria.hpp"

class Cure : public AMateria
{
    private:
    
    public:
        Cure();
        Cure(const Cure &copy);
        Cure &operator=(const Cure &rhs);
        ~Cure();

        AMateria *clone() const;
        void use(ICharacter &target);
};

#endif