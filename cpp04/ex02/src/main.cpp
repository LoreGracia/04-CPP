#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <new>

int main()
{
	{
		const A_Animal* j = new Dog();
		const A_Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	std::cout << std::endl;
	{
		// A_Animal* k = new A_Animal(*i);
		// k->getType();//should not work
		// delete k;
	}
	std::cout << std::endl;
	{
		A_Animal* animals[10];
		for (int i = 0; i != 5; i++)
			animals[i] = new Dog();
		for (int i = 5; i != 10; i++)
			animals[i] = new Cat();
		for (int i = 0; i != 10; i++)
			animals[i]->makeSound();
		for (int i = 0; i != 10; i++)
			delete animals[i];
	}
	return 0;
}
