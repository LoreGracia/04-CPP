#ifndef EASYFIND_HPP	
# define EASYFIND_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <limits>

class Btc
{
	private:
		std::map<size_t, float> _data;

		std::string tmp;
		std::string date;
		std::string value;

		std::string	readData(char end, size_t size, std::ifstream& file);
		std::string	getDate();
		std::string	getQuantity();
		void	print_error(std::string str);
		void	print_prize(std::string str);
		float	searchPrize();
	public:
		Btc();
		Btc(std::string av);
		Btc(const Btc& other);
		Btc& operator=(const Btc& other);
		~Btc();

		void	findPrize(std::string input);
};

#endif
