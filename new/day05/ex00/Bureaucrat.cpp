#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string msg) : _msg(msg) {}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return _msg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string msg) : _msg(msg) {}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return _msg.c_str();
}

Bureaucrat::Bureaucrat(void) : _maxGrade(1), _minGrade(150) {
	std::cout << "[Bureaucrat constructor]" << std::endl;
}

Bureaucrat::Bureaucrat(const int grade) : _grade(grade), _maxGrade(1), _minGrade(150) {
	if (_grade < _maxGrade) {
		throw GradeTooHighException("Grade is too high");
	} else if (_grade > _minGrade) {
		throw GradeTooHighException("Grade is too low");
	}	

	std::cout << "[Bureaucrat constructor]" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string & name) : _name(name), _maxGrade(1), _minGrade(150) {
	std::cout << "[Bureaucrat constructor]" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string & name, const int grade) : _name(name), _grade(grade), _maxGrade(1), _minGrade(150) {
	std::cout << "[Bureaucrat constructor]" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "[Bureaucrat destructor]" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat & other) : _maxGrade(1), _minGrade(150) {
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat & other) {
	if (this != &other) {
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return *this;
}

const std::string &Bureaucrat::getName( void ) const {
	return _name;
}

const int Bureaucrat::getGrade( void ) const {
	return _grade;
}

void Bureaucrat::increase( void ) {
	_grade--;
	if (_grade < _maxGrade) {
		throw GradeTooHighException("Grade is too high");
	}
}

void Bureaucrat::decrease( void ) {
	_grade++;

	if (_grade > _minGrade) {
		throw GradeTooHighException("Grade is too low");		
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs) {
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return out;
}
