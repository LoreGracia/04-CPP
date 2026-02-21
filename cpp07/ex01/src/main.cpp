#include "iter.hpp"

void	addition(int *i)
{
	*i += 1;
}

void	capitalize(char *a)
{
	if (*a < 'a' && *a > 'A' - 1)
		*a -= 'A' - 'a';
}

void	cammel(std::string *s)
{
	while ((*s).find(' '))
		(*s).at((*s).find(' ')) = '_';
}

int main()
{
	{ //*int + 1
		std::cout << "		*Int +1" << std::endl;
		int a[] = {4, 2, 42, 3, 1, 41};
		iter(a, 6, &print);
		std::cout << std::endl;
		iter(a, 6, &addition);
		iter(a, 6, &print);
		std::cout << std::endl;
	}
	{ //char capitalize
		std::cout << "		*Char capitalize" << std::endl;
		char a[4] = {'h', 'o', 'l', 'a'};
		iter(a, 4, &print);
		std::cout << std::endl;
		iter(a, 4, &capitalize);
		iter(a, 4, &print);
		std::cout << std::endl;
	}
	{ //char capitalize
		std::cout << "		*String capitalize" << std::endl;
		std::string a[3] = {"hola que tal", "Como va la vida", "jajaja hahaha ha"};
		iter(a, 3, &print);
		std::cout << std::endl;
		iter(a, 3, &cammel);
		iter(a, 3, &print);
		std::cout << std::endl;
	}
	return 0;
}
