#ifndef ITER_HPP	
# define ITER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

template <typename T>
void	iter(T* array, const size_t size, void (*f)(T *))
{
	for (size_t i = 0; i < size; i++)
		f(&array[i]);
}

template<typename T>
void	print(T *a)
{
	std::cout << "a = " << *a << std::endl;
}

#endif
