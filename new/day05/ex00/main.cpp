#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b("John", 10);
		std::cout << b << std::endl;
		b.decrease();
		b.decrease(120);
		std::cout << b << std::endl;
		b.decrease(20);
		std::cout << b << std::endl;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b;
		b.increase(149);
		std::cout << b << std::endl;
		b.increase(4294967164); //should throw an exception
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
