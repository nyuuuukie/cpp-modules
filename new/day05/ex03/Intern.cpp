#include "Intern.hpp"

Intern::Intern(void) {
	_fnames[0] = "Presidential Pardon";
	_fnames[1] = "Robotomy Request";
	_fnames[2] = "Shrubbery Creation";

	_formCreators[0] = &Intern::createPresidentialPardonForm;
	_formCreators[1] = &Intern::createRobotomyRequestForm;
	_formCreators[2] = &Intern::createShrubberyCreationForm;
}

Intern::~Intern(void) {}

Intern::Intern(const Intern & other) {
	*this = other;
}
Intern &Intern::operator=(const Intern & other) {
	if (this != &other) {

	}
	return *this;
}

Form *Intern::createRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

Form *Intern::createShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

Form *Intern::createPresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(const std::string &name, const std::string &target) {
	for (int i = 0; i < Intern::_size; i++) {
		if (_fnames[i] == name) {
			return (this->*_formCreators[i])(target);
		}
	}
	
	std::cout << "Form was not found" << std::endl;
	return 0;
}
