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

		Array( const Array & other ) : _storage(0), _size(0) {
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
				
				if (this->_storage != 0 && this->_size != 0) {
					delete[] _storage;
				}
				_size = other.size();
				_storage = new T[_size];
				
				for (int i = 0; i < _size; i++) {
					_storage[i] = other[i];
				}
			}
			return *this;
		}

		T& operator[](int i) const {
			if (i >= 0 && i < _size)
				return _storage[i];	
			throw std::out_of_range("Index is out of range");
		}
};
