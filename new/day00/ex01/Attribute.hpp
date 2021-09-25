#pragma once

#include <string>

class Attribute
{
private:
	std::string _name;
	std::string _value;

public:
	void setValue(std::string);
	void setName(std::string);

	std::string &getValue(void);
	std::string getName(void) const;

	Attribute();
	~Attribute();
};
