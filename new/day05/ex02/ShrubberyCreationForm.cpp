#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
Form("Shrubbery Creation", 145, 137) 
{
	_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
Form(other) 
{
	*this = other;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	this->Form::operator=(other);
	this->_target = other._target;

	return *this;
}


void ShrubberyCreationForm::executeAction(Bureaucrat const &executor) const {
	std::string filename = _target + "_shrubbery";
	std::ofstream out;

	std::cout << executor.getName() << " planting tree..." << std::endl;

	out.open(filename.c_str());
	if (out.is_open()) {
		out << "                                        " << std::endl;
		out << "                .,-'```````````--.      " << std::endl;
		out << "             ,-'          __,,-- \\     " << std::endl;
		out << "           ,'    __,--````dF      )     " << std::endl;
		out << "          /   .-`Hb_,--``dF      /      " << std::endl;
		out << "        ,'       _Hb ___dF`-._,-'       " << std::endl;
		out << "      ,'      _,-````   ``--..__        " << std::endl;
		out << "     (     ,-'                  `.      " << std::endl;
		out << "      `._,'     _   _             ;     " << std::endl;
		out << "       ,'     ,' `-'Hb-.___..._,-'      " << std::endl;
		out << "       \\    ,'`Hb.-'HH`-.dHF`          " << std::endl;
		out << "        `--'    Hb  HH  dF              " << std::endl;
		out << "                 Hb HH dF               " << std::endl;
		out << "                  HbHHdF                " << std::endl;
		out << "                  |HHHF                 " << std::endl;
		out << "                  |HHH|                 " << std::endl;
		out << "                  |HHH|                 " << std::endl;
		out << "                  |HHH|                 " << std::endl;
		out << "                  |HHH|                 " << std::endl;
		out << "                  |HHH|                 " << std::endl; 
		out << "                 .dF|Hb.                " << std::endl; 
		out << "               .dddH|Hbbb.              " << std::endl; 
		out << "             .ddFdHH|HHhbb.             " << std::endl; 
		out << "########################################" << std::endl;
		out.close();
	}
	else {
		std::cout << "Cannot open file \"" + _target + "_shrubbery\"" << std::endl;
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	Form::execute(executor);
}
