/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:52:47 by atok              #+#    #+#             */
/*   Updated: 2024/05/10 23:52:47 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

using std::cout;

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
	this->_target = "Default PresidentialPardonForm target";
	cout << "Pardon Default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm( "PresidentialPardonForm",145,137), _target(target)
{
	cout << "Pardon Parameter constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy.getName(), copy.getGradeReqToSign(), copy.getGradeReqToExecute())
{
	cout << "Pardon Copy Constructor Called\n";
	// *this = copy;
	this->_target = copy._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	cout << "Pardon Copy Assingment Operator called\n";
	AForm::operator=(rhs);
	this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "pardon Deconstructor called\n";
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
	{
		throw std::runtime_error(getName() + " - Form is not signed & unable to execute");
	}
	else if (executor.getGrade() > AForm::getGradeReqToExecute())
	{
		throw std::runtime_error(getName() + " - Form is signed but " + executor.getName() + " Burea Grade to low to execute");
	}
	else
	{
		cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
	}
}