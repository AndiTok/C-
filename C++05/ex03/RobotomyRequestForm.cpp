/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:47:34 by atok              #+#    #+#             */
/*   Updated: 2024/05/10 23:47:34 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

using std::cout;

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
	this->_target = "Default RobotomyForm target";
	cout << "Robo Default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm( "RobotomyRequestForm",72,45), _target(target)
{
	cout << "Robo Parameter constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), copy.getGradeReqToSign(), copy.getGradeReqToExecute())
{
	cout << "Robo Copy Constructor Called\n";
	// *this = copy;
	this->_target = copy._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	cout << "Robo Copy Assingment Operator called\n";
	AForm::operator=(rhs);
	this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "Robo Deconstructor called\n";
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	// std::random_device rd;
	// std::uniform_int_distribution<int>dist(0,1);
	// int output = dist(rd);

	static int i = 0;
	srand(time(0) + i++);
	int output = rand() % 2;

	cout << " *Drilling noise* \n";
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
		if (output == 1)
			cout << _target << " has been Robotomized successfully!\n";
		else if (output == 0)
			cout << "Robotomi has failed...\n";
	}
}