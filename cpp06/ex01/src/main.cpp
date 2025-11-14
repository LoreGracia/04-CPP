#include "Serializer.hpp"

int main()
{
	Data a;
	a.a = 123;
	a.b = 'D';
	uintptr_t b = Serializer::serialize(&a);
	int *c = reinterpret_cast<int *>(b);
	std::cout << "First iter : " << *c << std::endl;
	c++;
	char *d = reinterpret_cast<char *>(c);
	std::cout << "Second iter : "  << *d << std::endl;
	Data *e = Serializer::deserialize(b);
	std::cout << &a << std::endl << "uintptr_t: " << b << std::endl << e << std::endl;
	std::cout << a.a << std::endl << a.b << std::endl;
	return 0;
}
