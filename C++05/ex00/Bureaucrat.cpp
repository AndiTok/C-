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
		Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		Bureaucrat::GradeTooLowException();
	cout << "Burea Parameter constructor called\n";
}

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
		/* No assignment for _name since it's const
		this->_name = rhs._name; // dont' work & cant' run */
		cout << " Error : unable to get name because is const\n";
		this->_grade = rhs._grade;

		/* below using const_cast to temporary cast away 'const' for it to work
		but the attr/var is const indicating it is designed to be not modified */
		// const_cast<std::string&>(this->_name) = rhs._name;
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
		Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade()
{
	this->_grade++;
	cout << "Grade/Rank decreased\n";
	if (this->_grade > 150)
	// if (this->_grade++ > 150)
		Bureaucrat::GradeTooLowException();
}

void Bureaucrat::GradeTooHighException()
{
	throw std::runtime_error("Grade Too High! < 1 \n");
}

void Bureaucrat::GradeTooLowException()
{
	throw std::runtime_error("Grade Too Low! > 150 \n");
}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & rhs)
{
	os << "Name : " << rhs.getName() << ", Grade : " << rhs.getGrade() << "\n";
	return (os);
}