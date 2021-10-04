#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int size = 10;
	Animal **animals = new Animal*[size];
	for (size_t i = 0; i < size; i++) {
		if (i < size / 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	
	for (size_t i = 0; i < size; i++) {
		animals[i]->makeSound();	
	}

	Cat *cat = dynamic_cast<Cat *>(animals[0]);
	Cat *cat2 = dynamic_cast<Cat *>(animals[3]);
	
	std::cout << "animals[0]'s idea: " << cat->getBrain()->getIdea(1) << std::endl;
	std::cout << "animals[6]'s idea: " << cat2->getBrain()->getIdea(1) << std::endl;	
	
	std::cout << "animals[0] = animals[3]" << std::endl;
	*cat = *cat2;
	
	std::cout << "animals[0]'s idea: " << cat->getBrain()->getIdea(1) << std::endl;
	std::cout << "animals[6]'s idea: " << cat2->getBrain()->getIdea(1) << std::endl;	

	for (size_t i = 0; i < size; i++)
		delete animals[i];
	delete[] animals;

	Dog basic;
	{
		Dog tmp = basic;
	}

	return 0;
}
