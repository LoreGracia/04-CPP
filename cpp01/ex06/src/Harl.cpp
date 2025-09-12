#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error( void )
{
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	void (Harl::*res[4]) ();
	res[0] = &Harl::debug;
	res[1] = &Harl::info;
	res[2] = &Harl::warning;
	res[3] = &Harl::error;
	std::string	lvl[4];
	lvl[0] = "DEBUG";
	lvl[1] = "INFO";
	lvl[2] = "WARNING";
	lvl[3] = "ERROR";
	int i = 0;
	while (i < 4 && lvl[i] != level)
		i++;
	if (i >= 4)
		std::cout << "\033[31mOptions: DEBUG , INFO , WARNING , ERROR\033[0m" << std::endl;
	switch (i)
	{
	case 0:
		(this->*res[i++])();
	case 1:
		(this->*res[i++])();
	case 2:
		(this->*res[i++])();
	case 3:
		(this->*res[i++])();
	default:
		break;
	}
}
