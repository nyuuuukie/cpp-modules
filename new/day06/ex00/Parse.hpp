#pragma once

#include <iostream>

class ParseError : public std::exception {
	public:
		virtual const char *what() const throw() = 0;
};

class Parse
{
	typedef void (Parse::*parser)( void );

	private:
		static const std::string _whitespaces;
		static const int _parsersCount = 4;
		std::string _arg;
		parser 		_parsers[_parsersCount];
		std::string _prefixes[_parsersCount];
		int _floatTail;

	public:
		Parse(std::string arg);
		~Parse();
		Parse(const Parse &other);
		Parse &operator=(const Parse &other);
		
		int parse( void );

		void setFloatTail( void );


		int readInt( void );
		double readDouble( void );

		void toInt( void );
		void toChar( void );
		void toFloat( void );
		void toDouble( void );

		std::string trim(const std::string &s);

		class InvalidParse : public ParseError {
			public:
				const char *what() const throw();
		};

		class NonDisplayable : public ParseError {
			public:
				const char *what() const throw();
		};
};
