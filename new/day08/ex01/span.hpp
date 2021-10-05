#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

typedef std::vector<int>::iterator iter;

class Span
{
	private:
		std::vector<int> _storage;
		int _count;
		int _max;

	public:
		Span(unsigned int max);
		~Span(void);
		Span(const Span &other);
		Span &operator=(const Span &other);

		void addNumber( int number );
		void addNumber(iter beg, iter end);
		int shortestSpan() const;
		int longestSpan() const;

	class Exception : public std::exception {
		private:
			std::string _msg;
		
		public:
			Exception(std::string msg);
			virtual ~Exception() throw ();
			virtual const char* what() const throw();
	};
};
