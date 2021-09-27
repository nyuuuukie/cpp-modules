#pragma once

#include <iostream>

class Zombie
{
public:
	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);
	void announce(void) const;
	void setAnnounceText(std::string text);

private:
	std::string _name;
	std::string _announceText;
};

Zombie *zombieHorde(int N, std::string name);
