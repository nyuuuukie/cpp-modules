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
	
	protected:
		static const int __hp__ = 100;
		static const int __ep__ = 100;
		static const int __dmg__ = 30;
};
