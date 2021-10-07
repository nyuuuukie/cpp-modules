#include "span.hpp"

Span::Span(unsigned int max) : _count(0), _max(max) {}

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
		throw Span::Exception("Overflow of span");
	} else {
		_storage.push_back(number);
		_count++;
	}
}

void Span::addNumber( iter beg, iter end ) {
	
	for (iter it = beg; it != end; it++)
	{
		if (_count >= _max) {
			throw Span::Exception("Overflow of span");
		} else {
			_storage.push_back(*it);
			_count++;
		}
	}
}

void Span::addNumber( int *arr, int n ) {
	
	for (int i = 0; i < n; i++)
	{
		if (_count >= _max) {
			throw Span::Exception("Overflow of span");
		} else {
			_storage.push_back(arr[i]);
			_count++;
		}
	}
}

int Span::shortestSpan() {

	if (_storage.size() <= 1) {
		throw Span::Exception("Span is too small");
	}

	iter beg = _storage.begin();
	iter end = _storage.end();

	std::sort(beg, end);

	int delta;
 	int min = *(beg + 1) - *beg;

	for (const_iter it = beg + 1; it < end; it++) {
		delta = *it - *(it - 1);
		min = std::min(min, delta);
	}
	
	return min;
}

int Span::longestSpan() {

	if (_storage.size() <= 1) {
		throw Span::Exception("Span is too small");
	}
	
	const_iter min = std::min_element(_storage.begin(), _storage.end());
	const_iter max = std::max_element(_storage.begin(), _storage.end());

	return *max - *min;
}

//Exceptions
Span::Exception::Exception(std::string msg) : _msg(msg) {}

Span::Exception::~Exception() throw () {}

const char* Span::Exception::what() const throw() {
	return _msg.c_str();
}
