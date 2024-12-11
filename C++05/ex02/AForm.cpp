/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:32:45 by atok              #+#    #+#             */
/*   Updated: 2024/04/29 01:32:45 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

using std::cout;

AForm::AForm() : _name("Default Form"), _signed(false), _gradeReqToSign(75), _gradeReqToExecute(75)
{
	cout << "AForm Default constructor called\n";
}

AForm::AForm(std::string name, int gradeReqToSign, int gradeReqToExecute) : _name(name), _signed(false), _gradeReqToSign(gradeReqToSign), _gradeReqToExecute(gradeReqToExecute)
{
	if (this->_gradeReqToSign < 1 || this->_gradeReqToSign < 1)
		throw AForm::GradeTooHighException();
	if (this->_gradeReqToExecute > 150 || this->_gradeReqToExecute > 150)
		throw AForm::GradeTooLowException();
	cout << "AForm Parameter constructor called\n";
}

// the copy initiaize then parse pased in the vars
AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeReqToSign(copy._gradeReqToSign), _gradeReqToExecute(copy._gradeReqToExecute)
// Form::Form(const Form &copy) : _name(copy.getName()), _signed(copy.getSgined()), _gradeReqToSign(copy.getGradeReqToSign()), _gradeReqToExecute(copy.getGradeReqToExecute())
// getter only works with const getter funtion
{
	cout << "AForm Copy Constructor Called\n";
	// *this = copy;
}

AForm &AForm::operator=(AForm const &rhs)
{
	cout << "AForm Copy Assingment Operator called\n";
	if (this != &rhs)
	{
		cout << " Notice : unable to get name because is const\n";
		cout << " Notice : unable to get grade req to sign because is const\n";
		cout << " Notice : unable to get grade req to exe because is const\n";
		// AForm(rhs.getName(), rhs.getGradeReqToSign(), rhs.getGradeReqToExecute());
		this->_signed = rhs._signed;
	}
	return *this;
}

AForm::~AForm()
{
	cout << "AForm Deconstructor called\n";
}

// getter funtion
std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getGradeReqToSign() const
{
	return this->_gradeReqToSign;
}

int AForm::getGradeReqToExecute() const
{
	return this->_gradeReqToExecute;
}

void AForm::beSigned(const Bureaucrat& burea)
{
	cout << "Burea - " + burea.getName() + " attempting beSgined form...\n";
	if (burea.getGrade() <= this->_gradeReqToSign)
	{
		//check if is ture, if it is say already signed
		//else, as below turn it ture
		this->_signed = true;
		cout << "  - Signing successfull! -\n";
	}
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	// could be ... const = 0; at the class 
	(void) executor;
	return;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High! \n"); //
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low! \n");  //
}

std::ostream & operator<<(std::ostream & os, AForm const & rhs)
{
	os << "-=Form information=-\n" 
	"Form Name: " << rhs.getName() << '\n' <<
	"Signed status: " << rhs.getSigned() << '\n' <<
	"Grade reg to sign: " << rhs.getGradeReqToSign() << '\n' <<
	"Grade reg to exec: " << rhs.getGradeReqToExecute() << '\n' <<
	"-=\n";

	return (os);
}