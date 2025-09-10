#pragma once

#include <string>
#include <iostream>

class	Weapon
{
	private:
		std::string	type;
	public:
		Weapon(std::string type) { this->type = type; };
		~Weapon() { ; };
		std::string const &getType() { return this->type; };
		void	setType(std::string type) { this->type = type; };
};
