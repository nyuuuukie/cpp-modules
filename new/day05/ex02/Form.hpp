#pragma once

#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		const int _maxGrade;
		const int _minGrade;
		const int _signRequiredGrade;
		const int _execRequiredGrade;
		bool _isSigned;

	public:
		//Constructors & Destructor
		Form(void);
		Form(const std::string &name, 
			const unsigned int signGrade = 150, 
			const unsigned int execGrade = 150);
		virtual ~Form(void);
		Form(const Form &other);

		//Operators overloads
		Form & operator=(const Form &other);

		// Getters & Setters
		const std::string &getName( void ) const;
		int getSignRequiredGrade( void ) const;
		int getExecRequiredGrade( void ) const;
		bool isSigned( void ) const;

		// Methods
		void beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const & executor) const; 
		
		//Exceptions
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

		class SignException : public std::exception {
			private:
				std::string _msg;

			public:
				SignException(std::string msg);
				virtual ~SignException() throw();
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &rhs);
