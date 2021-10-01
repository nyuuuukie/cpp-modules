#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(FragTrap const & other);	
		FragTrap(const std::string name);
		~FragTrap(void);
		
		FragTrap &operator=(FragTrap const & other);

		void highFivesGuys(void) const;
};
