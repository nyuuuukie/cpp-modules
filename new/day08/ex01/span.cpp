#include "span.hpp"

Span::Span(unsigned int max) : _max(max), _count(0) {}

Span::~Span(void) {}

Span::Span(const Span & other) {
	*this = other;
}

Span & Span::operator=(const Span & other) {
	if (this != &other) {
		this->_storage = other._storage;
		this->_count = other._count;
		this->_max = other._max;
	}
	return *this;
}

void Span::addNumber( int number ) {
	if (_count >= _max) {
		throw Span::Exception("Overflow of span (<Exception>)");
	} else {
		_storage.push_back(number);
		_count++;
	}
}

int Span::shortestSpan() const {
	if (_storage.size() <= 1) {
		throw Span::Exception("Span is too small (<Exception>)");
	}

	std::sort(_storage.begin(), _storage.end());
	return _storage[_count - 1] - _storage[0];
}

int Span::longestSpan() const {
	if (_storage.size() <= 1) {
		throw Span::Exception("Span is too small (<Exception>)");
	}

	std::sort(_storage.begin(), _storage.end());
 
 	int diff = 0xffffffff;
	std::vector<int>::iterator it = _storage.begin();
	std::vector<int>::iterator end = _storage.end() - 1;
	
	int delta;
	while (it != end) {
		delta = *(it + 1) - *it;
      	if (delta < diff)
        	diff = delta;
		it++;
	}
 	return diff;
}


//Exceptions
Span::Exception::Exception(std::string msg) : std::exception(), _msg(msg) {}

Span::Exception::~Exception() throw () {}

const char* Span::Exception::what() const throw() {
	return _msg.c_str();
}
