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

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name; //const name
		bool _signed; //bool indicator if signed or not (at construction it's not)
		const int _gradeReqToSign; // grade req to sign
		const int _gradeReqToExecute; // grade req to exe
	
	public:
		Form();
		// signed att not needed as it will be false by default
		Form(std::string name, int gradeReqToSign, int gradeReqToExecute);
		Form (const Form &copy);
		Form &operator=(const Form& rhs);
		~Form();
	
	// getter for all 4 att
	// when not using getter for copy constructor
	// std::string getName();
	// bool getSgined();
	// int getGradeReqToSign();
	// int getGradeReqToExecute();
	// use this for when require attr to be modified in getter function

	// when using getter for copy constructor
	std::string getName() const; 
	bool getSigned() const ;
	int getGradeReqToSign() const;
	int getGradeReqToExecute() const;
	// also because getter funtion dont modify things

	void beSgined(const Bureaucrat& burea); // signed by who/which burea?

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

std::ostream & operator<<(std::ostream & os, Form const & rhs);

#endif