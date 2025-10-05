#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "\033[34mMateriaSource created\033[0m" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = other.inventory[i]->clone();
	std::cout << "\033[34mCopy of MateriaSource created\033[0m" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	std::cout << "\033[34m" << "MateriaSource destructor called\033[0m" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			this->inventory[i] = m;
			break;
		}
		else if (i == 3)
		{
			delete m;
			std::cout << "No space in MateriaSource" << std::endl;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{	
		if (inventory[i] && !type.empty() && !inventory[i]->getType().compare(type))
		{
			return inventory[i]->clone();
		}
	}
	std::cout << "No ocurrence in MateriaSource" << std::endl;
	return NULL;
}

