#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>

int main()
{
	int _a[5] = {1, 9, 5, 6, 4};
	double _b[5] = {4.5, 6.4, 3.55, 7.65, 2.11};
	std::string _c[5] = {"one", "two", "three", "four", "five"};

	std::vector<int> av(_a, _a + 5);
	std::vector<double> bv(_b, _b + 5);
	std::vector<std::string> cv(_c, _c + 5);

	std::list<int> al(_a, _a + 5);
	std::list<double> bl(_b, _b + 5);
	std::list<std::string> cl(_c, _c + 5);

	try {
		std::vector<int>::iterator res = easyfind(av, 5);
		std::cout << *res << " was found" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<double>::iterator res = easyfind(bv, 6.4);
		std::cout << *res << " was found" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		std::vector<std::string>::iterator res = easyfind(cv, "three");
		std::cout << *res << " was found" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		std::list<int>::iterator res = easyfind(al, 6);
		std::cout << *res << " was found" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::list<double>::iterator res = easyfind(bl, 3.55);
		std::cout << *res << " was found" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::list<std::string>::iterator res = easyfind(cl, "four");
		std::cout << *res << " was found" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
