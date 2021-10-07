#include <iostream>
#include <cstdlib>

#include "Array.hpp"

#define MAX_VAL 750

//class A
//{
//	private:
//		int _i;

//	public:
//		A(void) : _i(0) {}
//		~A(void) {}
//		A(const A & other) : _i(other._i) {}
//		A & operator=(const A & other) { _i = other._i; return *this; }
//		A & operator=(int num) { _i = num; return *this; }

//};

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
	//SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

	// Nothing should appear
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

	// Causing exceptions on indexer
    try {
        numbers[-2] = 0;
    }
    catch(const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

	//checking for correct assignment operator overloading
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }

	//Array<A> As(MAX_VAL);
	//for (int i = 0; i < MAX_VAL; i++) {
    //    As[i] = rand();
    //}

    delete [] mirror;
    return 0;
}
