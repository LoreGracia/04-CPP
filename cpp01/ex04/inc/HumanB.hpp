#pragma once
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon*		weapon;
	public:
		HumanB(std::string name);
		~HumanB() { ; };
		void	setWeapon(Weapon& weapon) { this->weapon = &weapon; };
		void	attack() { std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl; };
};
