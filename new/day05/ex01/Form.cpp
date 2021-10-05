#include "Form.hpp"

Form::Form(void) :
	_name("Anonymous"),
	_maxGrade(1),
	_minGrade(150),
	_signRequiredGrade(150),
	_execRequiredGrade(150),
	_isSigned(false)
{}

Form::Form(const std::string &name, const unsigned int signGrade, const unsigned int execGrade) :
	_name(name),
	_maxGrade(1),
	_minGrade(150),
	_signRequiredGrade(signGrade),
	_execRequiredGrade(execGrade),
	_isSigned(false)
{
	if (signGrade < static_cast<unsigned int>(_maxGrade)) {
		throw GradeTooHighException("Sign grade is too high");
	} else if (signGrade > static_cast<unsigned int>(_minGrade)) {
		throw GradeTooLowException("Sign grade is too low");
	}

	if (execGrade < static_cast<unsigned int>(_maxGrade)) {
		throw GradeTooHighException("Exec grade is too high");
	} else if (execGrade > static_cast<unsigned int>(_minGrade)) {
		throw GradeTooLowException("Exec grade is too low");
	}
	std::cout << "[Form constructor]" << std::endl;
}

Form::~Form(void) {
	std::cout << "[Form destructor]" << std::endl;
}

Form::Form(const Form &other) : 
_name(other._name),
_maxGrade(1),
_minGrade(150),
_signRequiredGrade(other._signRequiredGrade),
_execRequiredGrade(other._execRequiredGrade),
_isSigned(false)
{}

Form &Form::operator=(const Form & other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
		const_cast<int &>(this->_signRequiredGrade) = other.getSignRequiredGrade();
		const_cast<int &>(this->_execRequiredGrade) = other.getExecRequiredGrade();
		const_cast<std::string &>(this->_name) = other.getName();
	}
	return *this;
}

const std::string &Form::getName( void ) const {
	return _name;
}

int Form::getSignRequiredGrade( void ) const {
	return _signRequiredGrade;
}

int Form::getExecRequiredGrade( void ) const {
	return _execRequiredGrade;
}

bool Form::isSigned( void ) const {
	return _isSigned;
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= this->getSignRequiredGrade()) {
		if (this->_isSigned)
			throw Form::AlreadySignedException("the form is already signed");
		this->_isSigned = true;
	}
	else {
		throw Form::GradeTooLowException("grade is too low");
	}
}

//Operators overloads
std::ostream &operator<<(std::ostream &out, const Form &rhs) {
	out << "######## Form " << rhs.getName() << " ########" << std::endl;
	out << "Grade required to sign: " << rhs.getSignRequiredGrade() << std::endl;
	out << "Grade required to exec: " << rhs.getExecRequiredGrade() << std::endl;
	out << "Signed: " << rhs.isSigned() << std::endl;
	
	return out;
}

//Exceptions
Form::GradeTooHighException::GradeTooHighException(std::string msg) : _msg(msg) {}
Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Form::GradeTooHighException::what() const throw() {
	return _msg.c_str();
}

Form::GradeTooLowException::GradeTooLowException(std::string msg) : _msg(msg) {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Form::GradeTooLowException::what() const throw() {
	return _msg.c_str();
}

Form::AlreadySignedException::AlreadySignedException(std::string msg) : _msg(msg) {}
Form::AlreadySignedException::~AlreadySignedException() throw() {}

const char *Form::AlreadySignedException::what() const throw() {
	return _msg.c_str();
}

