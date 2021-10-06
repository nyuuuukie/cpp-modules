#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b1;
	Bureaucrat b2;

	ShrubberyCreationForm f1 = ShrubberyCreationForm("tree");
	RobotomyRequestForm f2 = RobotomyRequestForm("mhufflep");
	PresidentialPardonForm f3 = PresidentialPardonForm("ziza");

	try {
		b1 = Bureaucrat("John", 10);
		b2 = Bureaucrat("Amy", 150);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;

		std::cout << std::endl << f1 << std::endl;
		b1.executeForm(f1);
		std::cout << std::endl;
		b1.signForm(f1);
		std::cout << std::endl << f1 << std::endl;
		b1.executeForm(f1);

		std::cout << std::endl << f2 << std::endl;
		b2.executeForm(f2);
		b2.signForm(f2);
		std::cout << std::endl << f2 << std::endl;

		b1.signForm(f2);
		b2.executeForm(f2);
		std::cout << std::endl << f2 << std::endl;

		b1.signForm(f3);
		b2.executeForm(f3);
		std::cout << std::endl << f3 << std::endl;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}	
	return 0;
}
