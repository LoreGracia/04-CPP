#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name= "BOB";
	this->healthP = 100;
	this->energyP = 50;
	this->attackP = 20;
	std::cout << "\033[34mScavTrap created\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name= name;
	this->healthP = 100;
	this->energyP = 50;
	this->attackP = 20;
	std::cout << "\033[34mScavTrap created\033[0m" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[34mScavtrap destructor called\033[0m" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energyP)
	{
		std::cout << "ScavTrap "  << this->name << " attacks " << target << " causing " << this->attackP << " points of damage !" << std::endl;
		this->energyP--;
	}
	else
		std::cout << "No energy left" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "Scavtrap " << this->name << " is in Gate keeper mode" << std::endl;
}
