#ifndef SERIALIZER_HPP	
# define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
# include <stdint.h>

typedef struct s_Data
{
	std::string a;
} Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
