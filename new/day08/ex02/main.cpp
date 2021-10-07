#include "mutantstack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator beg = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();

	MutantStack<int>::reverse_iterator rbeg = mstack.rbegin();
	MutantStack<int>::reverse_iterator rend = mstack.rend();

	std::cout << "direct: ";
	while (beg != end) {
		std::cout << *beg << " ";
		++beg;
	}
	std::cout << std::endl;

	std::cout << "reverse: ";
	while (rbeg != rend) {
		std::cout << *rbeg << " ";
		++rbeg;
	}
	std::cout << std::endl;


	MutantStack<int> mstack2;

	std::cout << "empty: " << mstack2.empty() << std::endl;
	mstack2.push(4);
	mstack2.push(2);
	mstack2.push(2);
	mstack2.push(1);

	MutantStack<int>::iterator beg2 = mstack2.begin();
	MutantStack<int>::iterator end2 = mstack2.end();

	std::cout << "direct: ";
	while (beg2 != end2) {
		std::cout << *beg2 << " ";
		++beg2;
	}
	std::cout << std::endl;

	std::stack<int> copy(mstack);
	return 0;
}
