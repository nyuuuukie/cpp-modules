#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack( void ) : std::stack<T>() {}
		~MutantStack( void ) {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		
		MutantStack & operator=(const MutantStack &other) {
			if (this != &other) {
				std::stack<T>::operator=(other);
			}
			return *this;
		}

		// Iterators
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::iterator const_iterator;

		iterator begin() {
			return std::stack<T>::c.begin();
		}

		iterator end() {
			return std::stack<T>::c.end();
		}

		const_iterator begin() const {
			return std::stack<T>::c.begin();
		}

		const_iterator end() const {
			return std::stack<T>::c.end();
		}
};
