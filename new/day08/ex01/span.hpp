#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Span
{
	typedef vector<int>::iterator iter;
	typedef vector<int>::const_iterator const_iter;
	
	private:
		vector<int> _storage;
		int _count;
		int _max;

	public:
		Span(unsigned int max);
		~Span(void);
		Span(const Span &other);
		Span &operator=(const Span &other);

		void addNumber( int number );
		void addNumber(iter beg, iter end);
		void addNumber( int *arr, int n );
		int shortestSpan();
		int longestSpan();

	class Exception : public std::exception {
		private:
			std::string _msg;
		
		public:
			Exception(std::string msg);
			virtual ~Exception() throw ();
			virtual const char* what() const throw();
	};
};
