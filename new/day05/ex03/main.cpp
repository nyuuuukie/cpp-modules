#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	{
		Intern someRandomIntern;
		Form* f1;
		Form* f2;
		Form* f3;
		Form* f4;
		
		f1 = someRandomIntern.makeForm("Robotomy Request", "mhufflep");
		f2 = someRandomIntern.makeForm("Presidential Pardon", "ziza");
		f3 = someRandomIntern.makeForm("Shrubbery Creation", "tree");
		f4 = someRandomIntern.makeForm("Energy Absorbation", "clu");

		Bureaucrat b1;
		Bureaucrat b2;

		try {
			b1 = Bureaucrat("John", 10);
			b2 = Bureaucrat("Amy", 150);

			std::cout << b1 << std::endl;
			std::cout << b2 << std::endl;

			std::cout << std::endl << *f1 << std::endl;
			b1.executeForm(*f1);
			std::cout << std::endl;
			b1.signForm(*f1);
			std::cout << std::endl << *f1 << std::endl;
			b1.executeForm(*f1);

			std::cout << std::endl << *f2 << std::endl;
			b2.executeForm(*f2);
			b2.signForm(*f2);
			std::cout << std::endl << *f2 << std::endl;

			b1.signForm(*f2);
			b1.executeForm(*f2);
			std::cout << std::endl << *f2 << std::endl;

			b1.signForm(*f3);
			b1.executeForm(*f3);
			std::cout << std::endl << *f3 << std::endl;

		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
