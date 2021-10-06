#pragma once

#include <cstdlib>
#include <iostream>

class Form;

class Bureaucrat
{
	private:
		const int _maxGrade;
		const int _minGrade;
		const std::string _name;
		int _grade;
	
	public:	
		Bureaucrat(void);
		Bureaucrat(const int grade);
		Bureaucrat(const std::string &name);
		Bureaucrat(const std::string &name, const int grade);

		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat & operator=(const Bureaucrat &other);

		const std::string &getName( void ) const;
		int getGrade( void ) const;

		void increase( unsigned int x = 1 );
		void decrease( unsigned int x = 1 );

		void signForm(Form &form);
		void executeForm(Form const &form);

		class GradeTooHighException : public std::exception {
			private:
				std::string _msg;	

			public:
				GradeTooHighException(std::string msg);
				virtual ~GradeTooHighException() throw();
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			private:
				std::string _msg;

			public:
				GradeTooLowException(std::string msg);
				virtual ~GradeTooLowException() throw();
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs);

#include "Form.hpp"

