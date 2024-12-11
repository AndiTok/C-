/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:42:17 by atok              #+#    #+#             */
/*   Updated: 2024/04/29 00:42:17 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

using std::cout;

Bureaucrat::Bureaucrat() : _name("Default Bure"), _grade(42)
{
	cout << "Burea Default constructor called\n";
	// cout << _name << ", Grade - " << _grade << "\n";
	// not needed as we have an overloader insertion aka («) operator
	// to print name and grade out
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	cout << "Burea Parameter constructor called\n";}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	cout << "Burea Copy Constructor Called\n";
	// *this = copy;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	cout << "Burea Copy Assingment Operator called\n";
	if (this != &rhs)
	{
		// No assignment for _name since it's const
		// this->_name = rhs._name; // dont' work & cant' run
		cout << " Notice : unable to get name because is const\n";
		this->_grade = rhs._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	cout << "Burea Deconstructor called\n";
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::increaseGrade()
{
	this->_grade--;
	cout << "Grade/Rank increased\n";
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade()
{
	this->_grade++;
	cout << "Grade/Rank decreased\n";
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(AForm& form)
{
	// try
	// {
	// 	form.beSgined(*this);
	// 	// <bureaucrat> signed <form>
	// 	cout << "Burea " << this->_name << " signed form " << form.getName() << '\n';
	// }
	// catch(Form::GradeTooLowException &e)
	// {
	// 	// std::cerr << e.what() << '\n';
	// 	// <bureaucrat> couldn’t sign <form> because <reason>
	// 	cout << "Burea " << this->_name << " coudn't signed Form " << form.getName() << " because " << e.what() << '\n';
	// }

	cout << "Burea - " << getName() + " - checking " + form.getName() + " singForm for signature ...\n";
	if(form.getSigned() == true)
	{
		cout << "\tForm - " << form.getName() << " already signed.\n";
	}
	else
	{
		if(getGrade() > form.getGradeReqToSign())
			cout << "Burea - " << this->_name << " couldn't signed Form - " << form.getName() << " because Grade to low to sign! \n";
		else
			cout << "Burea - " << this->_name << " have not signed Form - " << form.getName() << '\n';
	}

	// form.beSigned(*this); // this will redirect and use beSigned funtion of "Form"
	// but i would like to saperate/decouple it
	
}

void Bureaucrat::executeForm(AForm const & form)
{
	//must attemp to execute form
	//if succes print who scecc executed from
	//else an explicit erro msg

	cout << "Burea - " << getName() + " - attempting to execute form - " + form.getName() + " ...\n";
	if(form.getSigned() == false)
		cout << "Form - " << form.getName() << " is not signed... unable to execute\n";
	else if (this->getGrade() > form.getGradeReqToExecute())
		cout << "Form is signed but Grade to low to execute\n";
	else
		form.execute(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High! \n"); //
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low! \n");  //
}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & rhs)
{
	os << "-=Burea information=-\n" << "Name : " << rhs.getName() << ", Grade : " << rhs.getGrade() << "\n" << "-=\n";
	return (os);
}