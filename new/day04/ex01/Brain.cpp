#include "Brain.hpp"
#include <cstdlib>

static std::string	makeIdea() {
	std::string idea = "";

	for (size_t i = 0; i < 10; i++)
	{
		idea += (rand() % 10) + '0';
	}
	return idea;
}

Brain::Brain( void ) {
	_size = 100;
	_ideas = new std::string[_size];
	
	if (this->_ideas != 0) {
		for (int i = 0; i < _size; i++) {
			this->_ideas[i] = "idea " + makeIdea();
		}
	}
	std::cout << "[Brain constructor]" << std::endl;
}

Brain::~Brain( void ) {
	if (_ideas != 0)
		delete[] _ideas;
	std::cout << "[Brain destructor]" << std::endl;
}

Brain::Brain(const Brain &other) {
	*this = other;
}

Brain& Brain::operator=(const Brain &other) {
	if (this != &other) {
		if (this->_ideas != 0 && other._ideas != 0) {
			for (int i = 0; i < _size; i++) {
				this->_ideas[i] = other._ideas[i];
			}
		}
	}
	return *this;
}

const std::string &Brain::getIdea( int index ) const {
	return _ideas[index];
}

