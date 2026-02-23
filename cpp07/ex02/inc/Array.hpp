#ifndef WHATEVER_HPP	
# define WHATEVER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T *v;
		unsigned int _size;
	public:
		Array() : v(NULL), _size(0) { std::cout << "\033[34mDefault Array constructor called\033[0m" << std::endl; };
		Array(unsigned int i) { v = new T[i](); _size = i; std::cout << "\033[34mArray constructor called\033[0m" << std::endl; };
		Array(const Array& other)
		{
			_size = other.size();
			v = new T[_size](); 
				for (unsigned int i = 0; i < other.size(); i++)
					v[i] = other.v[i];
				std::cout << "\033[34mArray copy constructor called\033[0m" << std::endl;
		};
		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] v;
				_size = other.size();
				v = new T[_size]();
				for (unsigned int i = 0; i < other.size(); i++)
					v[i] = other.v[i];
			}
				return *this;
		};
		~Array() { delete[] v; std::cout << "\033[34mDefault Array destructor called\033[0m" << std::endl; };

		T& operator[](unsigned int i)
		{
			if (i >= size())
				throw std::out_of_range("Iterator out of range");
			return (v[i]);
		};

		unsigned int size() const
		{
			return _size;
		};
};

#endif
