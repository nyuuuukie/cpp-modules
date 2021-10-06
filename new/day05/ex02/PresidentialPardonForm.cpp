#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
Form("Presidential Pardon", 25, 5) 
{
	_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
Form(other) 
{
	*this = other;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	this->Form::operator=(other);
	this->_target = other._target;

	return *this;
}

void PresidentialPardonForm::executeAction(Bureaucrat const &executor) const {
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox (";
	std::cout << executor.getName() << ")" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	Form::execute(executor);
}
