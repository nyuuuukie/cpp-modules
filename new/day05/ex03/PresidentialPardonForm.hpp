#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm & other);
		PresidentialPardonForm & operator=(const PresidentialPardonForm & other);

		void execute(Bureaucrat const &executor) const;
};
