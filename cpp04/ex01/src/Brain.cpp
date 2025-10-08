#include "Brain.hpp"

Brain::Brain()
	: ideas()
{
	std::cout << "\033[34mBrain created\033[0m" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i != 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "\033[34mCopy of Brain created\033[0m" << std::endl;
}

Brain& Brain::operator=(const Brain &other)
{
	if (this != &other)
	{	
		for (int i = 0; i != 100; i++)
		{
			ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "\033[34mBrain destructor called\033[0m" << std::endl;
}

std::string Brain::getThought(int idx)
{
	if (idx >= 100 || idx < 0 || ideas[idx].empty())
		return NULL;
	return ideas[idx];
}

void Brain::setThought(std::string idea, int idx)
{
	if (idx < 100 && idx >= 0)
		ideas[idx] = idea;
}
