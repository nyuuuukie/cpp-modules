#pragma once

#include <stdexcept>

template <class T>
class Array {

private:
	T *_storage;
	int _size;
public:
	Array( void ) {
		_size = 0;
		_storage = 0;
	}

	Array( unsigned int n ) {
		_size = n;
		_storage = new T[n];		
	}

	Array( const Array & other ) {
		*this = other;
	}

	~Array( void ) {
		delete[] _storage;
	}

	unsigned int size( void ) const {
		return this->_size;
	}

	Array& operator=(const Array & other) {
		if (this != &other) {
			
			int size = other.size();
			T *temp = new T[size];
			
			//delete[] _storage;
			_storage = 0;
			_size = size;
			for (int i = 0; i < size; i++) {
				temp[i] = other[i];
			}
			_storage = temp;
		}
		return *this;
	}

	T& operator[](int i) const {
		if (i >= 0 && i < _size)
			return _storage[i];	
		throw std::out_of_range("Index is out of range");
	}
};
