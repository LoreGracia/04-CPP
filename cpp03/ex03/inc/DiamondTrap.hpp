#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
    	std::string name;
		int healthP;
		int energyP;
		int attackP;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);
		~DiamondTrap();
		void whoAmI();
		using ScavTrap::beRepaired;
		using ScavTrap::attack;
		using ScavTrap::takeDamage;
};

#endif
