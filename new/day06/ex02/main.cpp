#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>

void	identify(Base *p);
void	identify(Base &p);
Base	*generate(void);

int main() {
	srand(time(0));

	Base *ptr = generate();
	Base &ref = *ptr;

	std::cout << "By ptr: ";
	identify(ptr);
	std::cout << "By ref: ";
	identify(ref);

	std::cout << "By ptr: ";
	identify(NULL);
	std::cout << "By ref: ";
	identify(0);

	return 0;
}
