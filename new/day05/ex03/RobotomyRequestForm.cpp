#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
Form("Robotomy Request", 72, 45) 
{
	_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
Form(other) 
{
	*this = other;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	this->Form::operator=(other);
	this->_target = other._target;

	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	Form::execute(executor);
	
	std::cout << "* drilling noises *" << std::endl;
	srand(time(0));
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}
