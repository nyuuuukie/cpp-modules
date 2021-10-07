#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>

int main()
{
	//int arr[] = {33, -135, 42, 274, 216, -17, 256, -347, 756};
	//int n = sizeof(arr) / sizeof(arr[0]);

	std::vector<int>v(100);
	for (int i = 0; i < 100; i++)
		v.push_back(i);
	
	try {
		std::vector<int>::iterator res = easyfind(v, 42);
		std::cout << *res << " was found" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator res = easyfind(v, 4221);
		std::cout << *res << " was found" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::list<int>l(100);
	
	try {
		std::list<int>::iterator res = easyfind(l, 0);
		std::cout << *res << " was found" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator res = easyfind(l, 1000);
		std::cout << *res << " was found" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
