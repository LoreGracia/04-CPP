#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "\033[34mSerializer constructor called\033[0m" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << "\033[34mSerializer copy constructor called\033[0m" << std::endl;
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	if (this != &other)
	{
		*this = other;
	}
	return *this; 
}

Serializer::~Serializer()
{
	std::cout << "\033[34mSerializer destructor called\033[0m" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
