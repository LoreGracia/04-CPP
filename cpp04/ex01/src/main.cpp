#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <new>

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	std::cout << std::endl;
	{
		Animal* j = new Dog();
		Animal* i = new Cat();
		Animal* k = new Animal(*i);
		delete j;
		delete i;
		k->getType();//should not work
		delete k;
	}
	std::cout << std::endl;
	{
		Animal* animals[10];
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
