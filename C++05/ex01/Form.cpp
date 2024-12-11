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

#include "Form.hpp"

using std::cout;

Form::Form() : _name("Default Form"), _signed(false), _gradeReqToSign(75), _gradeReqToExecute(75)
{
	cout << "Form Default constructor called\n";
}

Form::Form(std::string name, int gradeReqToSign, int gradeReqToExecute) : _name(name), _signed(false), _gradeReqToSign(gradeReqToSign), _gradeReqToExecute(gradeReqToExecute)
{
	if (this->_gradeReqToSign < 1 || this->_gradeReqToSign < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeReqToExecute > 150 || this->_gradeReqToExecute > 150)
		throw Form::GradeTooLowException();
	cout << "Form  Parameter constructor called\n";
}

// the copy initiaize then parse pased in the vars
Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeReqToSign(copy._gradeReqToSign), _gradeReqToExecute(copy._gradeReqToExecute)
// Form::Form(const Form &copy) : _name(copy.getName()), _signed(copy.getSgined()), _gradeReqToSign(copy.getGradeReqToSign()), _gradeReqToExecute(copy.getGradeReqToExecute())
// getter only works with const getter funtion
{
	cout << "Form  Copy Constructor Called\n";
	// *this = copy;
}

Form &Form::operator=(Form const &rhs)
{
	cout << "Form Copy Assingment Operator called\n";
	if (this != &rhs)
	{
		cout << " Notice : unable to get name because is const\n";
		cout << " Notice : unable to get grade req to sign because is const\n";
		cout << " Notice : unable to get grade req to exe because is const\n";
		this->_signed = rhs._signed;
	}
	return *this;
}

Form::~Form()
{
	cout << "Form Deconstructor called\n";
}

// getter funtion
std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getGradeReqToSign() const
{
	return this->_gradeReqToSign;
}

int Form::getGradeReqToExecute() const
{
	return this->_gradeReqToExecute;
}

void Form::beSgined(const Bureaucrat& burea)
{
	if (burea.getGrade() <= this->_gradeReqToSign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High! \n"); //
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low! \n");  //
}

std::ostream & operator<<(std::ostream & os, Form const & rhs)
{
	os << "Form Name: " << rhs.getName() << '\n' <<
	"Signed status: " << rhs.getSigned() << '\n' <<
	"Grade reg to sign: " << rhs.getGradeReqToSign() << '\n' <<
	"Grade reg to exec: " << rhs.getGradeReqToExecute() << '\n';

	return (os);
}