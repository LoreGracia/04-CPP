#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	srand(time(NULL));
	int fo= rand() % MAX;
	switch (fo)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void identify(Base* p)
{
	if (!p)
		return ;
	int i = -1;
	std::string type[MAX] = { "A", "B", "C"};
	i += dynamic_cast<A *>(p)? 1 : 0;
	i += dynamic_cast<B *>(p)? 2 : 0;
	i += dynamic_cast<C *>(p)? 3 : 0;
	std::cout << "Reference type is " << (i < MAX? type[i] : "unrecognized") << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Reference type is A" << std::endl;
		(void)a;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "Reference type is B" << std::endl;
		(void)b;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "Reference type is C" << std::endl;
		(void)c;
		return ;
	}
	catch(const std::exception& e) {}
	std::cout << "Reference type is unrecognized" << std::endl;
}

int main()
{
	Base *base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}
