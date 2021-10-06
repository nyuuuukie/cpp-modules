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

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		this->Form::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	Form::execute(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
