#include "mutantstack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator beg = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();

	MutantStack<int>::reverse_iterator rbeg = mstack.rbegin();
	MutantStack<int>::reverse_iterator rend = mstack.rend();

	while (beg != end) {
		std::cout << *beg;
		++beg;
	}

	std::cout << std::endl;

	while (rbeg != rend) {
		std::cout << *rbeg;
		++rbeg;
	}
	std::cout << std::endl;

	std::stack<int> copy(mstack);
	return 0;
}
