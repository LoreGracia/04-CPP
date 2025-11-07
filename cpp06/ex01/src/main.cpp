#include "Serializer.hpp"

int main()
{
	Data a;
	a.a  = "Put here your data\n";
	uintptr_t b = Serializer::serialize(&a);
	Data *c = Serializer::deserialize(b);
	std::cout << &a << std::endl << b << std::endl << c << std::endl;
	return 0;
}
