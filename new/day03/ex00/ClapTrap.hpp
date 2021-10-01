#pragma once

#include <iostream>
#include "Utils.hpp"

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &other);
	~ClapTrap(void);

	ClapTrap &operator=(ClapTrap const &other);

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	//GETTERS AND SETTERS
	int getHP(void) const;
	int getEP(void) const;
	const std::string getInfo(void) const;
	const std::string getName(void) const;

private:
	int _hp;
	int _ep;
	int _damage;
	std::string _type;
	std::string _name;
};
