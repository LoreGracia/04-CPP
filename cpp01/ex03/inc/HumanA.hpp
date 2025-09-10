#pragma once
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon&		weapon;
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA() { ; };
		void	attack() { std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl; };
};
