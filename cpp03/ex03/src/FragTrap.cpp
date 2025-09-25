#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name= "BOB";
	this->healthP = 100;
	this->energyP = 100;
	this->attackP = 30;
	std::cout << "\033[34mFragTrap created\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name= name;
	this->healthP = 100;
	this->energyP = 100;
	this->attackP = 30;
	std::cout << "\033[34mFragTrap created\033[0m" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[34mFragtrap destructor called\033[0m" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Fragtrap " << this->name << " request a high five" << std::endl;
}
