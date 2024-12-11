/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:33:40 by atok              #+#    #+#             */
/*   Updated: 2024/05/15 18:33:40 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

using std::cout;

Intern::Intern()
{
	std::cout << "Intern Default constructor called" << std::endl;
	// for (int i = 0; i < n; i++)
	// 	 box[i] = nullptr;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
	// for (int i = 0; i < n; i++)
	// 	delete box[i];
}

Intern::Intern(const Intern& rhs)
{
	std::cout << "AForm copy created" << std::endl;
	*this = rhs;
}

Intern &Intern::operator=(const Intern& rhs)
{
	std::cout << "AForm operator copy created" << std::endl;
	if(this != &rhs)
	{
		// for (int i = 0; i < n; i++)
		// 	box[i] = rhs.box[i];
	}
	return (*this);
}

AForm* Intern::createShrubForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRoboForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	//pointer to class funtion 
	//refer to CPP01 ex05 Harl
	//array of Form name

	// AForm func[3] = {ShrubberyCreationForm(target),RobotomyRequestForm(target),PresidentialPardonForm(target)};
	CreateForm form[3] = {&Intern::createShrubForm,&Intern::createRoboForm,&Intern::createPardonForm};
	std::string formname[3] = {"shrub","robo","pardon"};
	
	//loop torugh array find if is == name
	//if yes create the form pasrsing in the target and return it
	//else print explcit error msg
	for(int i = 0; i < 3; i++)
	{
		if(formname[i] == name)
		{
			/* store from in box array */
			// for(int j = 0; j < n; j++)
			// {
			// 	if(j == n - 1)
			// 	{
			// 		cout << "Oooops! Intern Box is FULL! ..can't make anymore Forms\n";
			// 		return nullptr;
			// 	}
			// 	else if(box[j] == nullptr)
			// 	{
			// 		AForm* tmp = form[i](target);
			// 		return tmp;
			// 	}
			// }
			cout << "Notice : Intern created - " + name + "form\n";
			// return (&func[i]); // dont work because local memory
			return (form[i](target)); // if not storing box in array
		}
	}
	//options
	throw std::runtime_error("Form name - " + name + " does not exist");
	// cout << "Form name - " + name + " does not exist\n";
	// std::cerr << "Form name - " + name + " does not exist\n";
	return nullptr;
}