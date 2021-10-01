#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const & other);	
		ScavTrap(const std::string name);
		~ScavTrap(void);
		
		ScavTrap & operator=(ScavTrap const & other);

		void guardGate(void) const;
};
