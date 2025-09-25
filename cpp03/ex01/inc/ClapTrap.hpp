#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class	ClapTrap
{	
	protected:
		std::string name;
		int healthP;
		int	energyP;
		int attackP;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
#endif
