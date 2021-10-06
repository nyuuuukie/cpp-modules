#pragma once

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm & other);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & other);

		void execute(Bureaucrat const &executor) const;
};
