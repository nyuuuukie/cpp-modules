#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void identify(Base *p) {

	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
	else {
		std::cout << "Not identified" << std::endl;
	}
	
}

void identify(Base &p) {
	bool found = false;

	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		found = true;
	} catch (std::exception &e) {}

	try {
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		found = true;
	} catch (std::exception &e) {}

	try {
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		found = true;
	} catch (std::exception &e) {}

	if (!found)
		std::cout << "Not identified" << std::endl;
}
