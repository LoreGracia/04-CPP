#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: name("Bob_clap_name")
{
	healthP = FragTrap::healthP;
	energyP = ScavTrap::energyP;
	attackP = FragTrap::attackP;
	std::cout << "\033[34mDiamondTrap created\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	ClapTrap::name = name + "_clap_name";
	this->name = name;
	healthP = FragTrap::healthP;
	energyP = ScavTrap::energyP;
	attackP = FragTrap::attackP;
	std::cout << "\033[34mDiamondTrap created\033[0m" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[34mDiamondtrap destructor called\033[0m" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap: " << this->name << " ClapTrap: " << ScavTrap::name << std::endl;
}
