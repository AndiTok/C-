/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:09:38 by atok              #+#    #+#             */
/*   Updated: 2024/04/29 01:09:38 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name; //const name
		bool _signed; //bool indicator if signed or not (at construction it's not)
		const int _gradeReqToSign; // grade req to sign
		const int _gradeReqToExecute; // grade req to exe
	
	public:
		AForm();
		AForm(std::string name, int gradeReqToSign, int gradeReqToExecute);
		AForm (const AForm &copy);
		AForm &operator=(const AForm& rhs);
		virtual ~AForm(); // virtual syntax made it an abstarct class
		// virtual ~AForm() = 0; // adding = 0 made it a pure abstarct class (aka interface)
		// wehre it cannnot initilize itself and defualt construtor is not needed

		// Use virtual ~AForm(); if you want Form to have a default destructor 
		// implementation that can be overridden by derived classes and 
		// allow instances of Form to be created directly.
		
		// Use virtual ~AForm() = 0; if you want Form to be an abstract class with 
		// no instances directly creatable and expect derived classes to 
		// provide their own destructor implementations.


	std::string getName() const; 
	bool getSigned() const ;
	int getGradeReqToSign() const;
	int getGradeReqToExecute() const;

	void beSigned(const Bureaucrat& burea);
	virtual void execute(Bureaucrat const & executor) const; //virtual syntax for concrete class to override

	//exception
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

std::ostream & operator<<(std::ostream & os, AForm const & rhs);

#endif