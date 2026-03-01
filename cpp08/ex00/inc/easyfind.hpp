#ifndef EASYFIND_HPP	
# define EASYFIND_HPP

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

template<typename T>
typename T::const_iterator	easyfind(T& temp, int ocurrence)
{
	typename T::const_iterator it = find(temp.begin(), temp.end(), ocurrence);
	if (it == temp.end())
		throw std::out_of_range("No ocurrence found");
	return (it);
}

#endif
