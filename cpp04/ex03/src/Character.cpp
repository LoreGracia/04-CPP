#include "Character.hpp"

Character::Character(std::string name)
	: name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "\033[34mCharacter created\033[0m" << std::endl;
}

Character::Character(const Character &other)
	: name(other.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++)
		this->inventory[i] = other.inventory[i]->clone();
	std::cout << "\033[34mCopy of Character created\033[0m" << std::endl;
}

Character& Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
			{
				delete inventory[i];
				inventory[i] = NULL;
			}
		}
		name = other.getName();
		for (int i = 0; i < 4; i++)
			this->inventory[i] = other.inventory[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
	std::cout << "\033[34m" << "Character destructor called\033[0m" << std::endl;
}

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == m)
		{
			std::cout << m->getType() << "'s already in " << this->name << "'s inventory" << std::endl;
			break ;
		}
		if (!inventory[i])
		{
			this->inventory[i] = m;
			break;
		}
		else if (i == 3)
			std::cout << "No space in " << this->name << "'s inventory" << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !inventory[idx])
		std::cout << "Not existing inventory slot" << std::endl;
	else
	{
		inventory[idx] = NULL;
	}
}

AMateria* Character::getMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{	
		if (inventory[i] && !type.empty() && !inventory[i]->getType().compare(type))
			return inventory[i];
	}
	std::cout << "No ocurrence in Character" << std::endl;
	return NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || !inventory[idx])
		std::cout << "Not existing inventory slot" << std::endl;
	else
		inventory[idx]->use(target);
}
