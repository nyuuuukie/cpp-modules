#pragma once

#include "Form.hpp"
#include <ctime>

class RobotomyRequestForm : public Form
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm & other);
		RobotomyRequestForm & operator=(const RobotomyRequestForm & other);

		void execute(Bureaucrat const &executor) const;
};
