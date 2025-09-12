#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "\033[31mMissing (single) option: DEBUG , INFO , WARNING , ERROR\033[0m" << std::endl, 1);
	Harl().complain(std::string(av[1]));
	return 0;
}
