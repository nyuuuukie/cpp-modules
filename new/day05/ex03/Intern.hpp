#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	typedef Form *(Intern::*creator) (const std::string &);

	private:
		static const int _size = 3;
		std::string _fnames[_size];
		creator		_formCreators[_size];
	
	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern & other);
		Intern & operator=(const Intern & other);
	
		Form* makeForm(const std::string &name, const std::string &target);

		Form *createRobotomyRequestForm(const std::string &target);
		Form *createShrubberyCreationForm(const std::string &target);
		Form *createPresidentialPardonForm(const std::string &targext);
};
