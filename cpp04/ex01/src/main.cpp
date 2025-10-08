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
		Cat* cat = new Cat();
		cat->setThought("I hate dogs", 0);
		Cat* copycat = new Cat(*cat);
		std::cout << cat->getBrain() << std::endl;
		std::cout << cat->getThought(0) << std::endl;
		delete cat;
		std::cout << copycat->getThought(0) << std::endl;
		copycat->setThought("I love dogs", 0);
		std::cout << copycat->getThought(0) << std::endl;//should not be the same
		std::cout << copycat->getBrain() << std::endl;
		delete copycat;
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
