#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string msg) : _msg(msg) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return _msg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string msg) : _msg(msg) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return _msg.c_str();
}

Bureaucrat::Bureaucrat(void) : _maxGrade(1), _minGrade(150), _name("Anonymous"), _grade(150) {
	std::cout << "[Bureaucrat constructor]" << std::endl;
}

Bureaucrat::Bureaucrat(const int grade) : _maxGrade(1), _minGrade(150), _grade(grade) {
	if (_grade < _maxGrade) {
		throw GradeTooHighException("Grade is too high");
	} else if (_grade > _minGrade) {
		throw GradeTooLowException("Grade is too low");
	}	

	std::cout << "[Bureaucrat constructor]" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string & name) :  _maxGrade(1), _minGrade(150), _name(name) {
	std::cout << "[Bureaucrat constructor]" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string & name, const int grade) : _maxGrade(1), _minGrade(150), _name(name), _grade(grade) {
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
		const_cast<std::string &>(this->_name) = other._name;
		this->_grade = other._grade;
	}
	return *this;
}

const std::string &Bureaucrat::getName( void ) const {
	return _name;
}

int Bureaucrat::getGrade( void ) const {
	return _grade;
}

void Bureaucrat::increase( unsigned int x ) {

	_grade -= x;
	if (x > static_cast<unsigned int>(_minGrade)) {
		throw GradeTooHighException("Grade is too high");
	}

 	if (_grade < _maxGrade) {
		throw GradeTooHighException("Grade is too high");
	}
}

void Bureaucrat::decrease( unsigned int x ) {
	_grade += x;

	if (x > static_cast<unsigned int>(_minGrade)) {
		throw GradeTooLowException("Grade is too low");
	}

	if (_grade > _minGrade) {
		throw GradeTooLowException("Grade is too low");		
	}
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " cannot sign " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs) {
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return out;
}
