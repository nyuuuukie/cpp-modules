#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &other);
		virtual ~DiamondTrap(void);

		DiamondTrap &operator=(const DiamondTrap &other);

		void attack(std::string const &target);
		void whoAmI(void);
};
