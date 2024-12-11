/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:50:57 by atok              #+#    #+#             */
/*   Updated: 2024/05/15 08:50:57 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define n 42
class AForm;

class Intern
{
	private:
		// AForm* box[n];
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &rhs);
		~Intern();
		static AForm* createShrubForm(const std::string &target);
		static AForm* createRoboForm(const std::string &target);
		static AForm* createPardonForm(const std::string &target);
		typedef AForm* (*CreateForm)(const std::string &target);

	AForm* makeForm(std::string name, std::string target); //form's name & form's target
/* 	place in here as memeber funtion because it is run like this
	Intern a; a.makeform(); reffer to pdf
	if place outside of brace,  it runs like this
	makeform(); as a stand alone function*/
};

#endif