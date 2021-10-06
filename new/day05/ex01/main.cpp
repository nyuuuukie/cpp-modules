#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat b1;
	Bureaucrat b2;
	Form f1;

	try {

		b1 = Bureaucrat("John", 10);
		b2 = Bureaucrat("Amy", -15);
		f1 = Form("f1", 12, 53);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << std::endl << f1 << std::endl;
		b1.signForm(f1);
		std::cout << std::endl << f1 << std::endl;
		b2.signForm(f1);
		std::cout << std::endl << f1 << std::endl;
	
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
