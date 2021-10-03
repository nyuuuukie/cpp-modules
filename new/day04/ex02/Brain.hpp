#pragma once

#include <string>
#include <iostream>

class Brain
{
	private:
		int _size;
		std::string *_ideas;
	
	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain & other);
		Brain & operator=(const Brain & other);
		
		const std::string &getIdea( int index ) const;
};
