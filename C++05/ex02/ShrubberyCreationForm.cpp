/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:54:29 by atok              #+#    #+#             */
/*   Updated: 2024/05/10 20:54:29 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

using std::cout;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
	this->_target = "Default ShrubForm target";
	cout << "Shrub Default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm( "ShrubberyCreationForm",145,137), _target(target)
{
	cout << "Shrub Parameter constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), copy.getGradeReqToSign(), copy.getGradeReqToExecute())
{
	cout << "Shrub Copy Constructor Called\n";
	// *this = copy;
	this->_target = copy._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	cout << "Shrub Copy Assingment Operator called\n";
	AForm::operator=(rhs);
	this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "Shrub Deconstructor called\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	// executor.signForm(*this); // this does not work becase is const
	// executor.executeForm(*this); // same here...
	if(this->getSigned() == false)
	{
		// cout << "Executor - " << executor.getName() << " unable to execute Shrub because Form is not signed\n";
		throw std::runtime_error(getName() + " - Form is not signed & unable to execute");
	}
	else if (executor.getGrade() > AForm::getGradeReqToExecute())
	{
		// cout << "Executor - " << executor.getName() << " unable to execute Shrub because Grade is too low\n";
		throw std::runtime_error(getName() + " - Form is signed but " + executor.getName() + " Burea Grade to low to execute");
	}
	else
	{
		cout << "  - Shrub executed! -  check current directory for " << this->_target + "_shrubbery\n";
		std::string file_name = this->_target + "_shrubbery";
		const char* output = file_name.c_str(); // convert std::string to const char*
		std::ofstream outFile(output); //takes in const char*
		// std::ofstream outFile(this->_target + "_shrubbery");
		outFile << "     >x<    \n"
				<< "   .xXxXx.  \n"
				<< "  -xxXxXxx- \n"
				<< "  X'xxxxx'X \n"
				<< "     | |    \n"
				<< "     | |    \n";
	}
}