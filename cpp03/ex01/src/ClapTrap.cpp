#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("BOB"), healthP(10), energyP(10), attackP(0)
{
	std::cout << "\033[34mClapTrap created\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), healthP(10), energyP(10), attackP(0)
{
	std::cout << "\033[34mClapTrap created\033[0m" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other)
	:name(other.name), healthP(other.healthP), energyP(other.energyP), attackP(other.attackP)
{
	std::cout << "\033[34mCopy of ClapTrap created\033[0m" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		healthP = other.healthP;
		energyP = other.energyP;
		attackP = other.attackP;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[34mClapTrap destructor called\033[0m" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyP)
	{
		std::cout << "ClapTrap "  << this->name << " attacks " << target << " causing " << this->attackP << " points of damage !" << std::endl;
		this->energyP--;
	}
	else
		std::cout << "No energy left" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	this->healthP -= amount;
	std::cout << "ClapTrap " << this->name << " lost " << amount << " health" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyP)
	{
		std::cout << "ClapTrap " << this->name << " regained " << amount << " health" << std::endl;
		this->healthP += amount;
		this->energyP--;
	}
	else
		std::cout << "No energy left" << std::endl;
}
