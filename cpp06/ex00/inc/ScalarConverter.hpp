#ifndef SCALARCONVERTER_HPP	
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>

#define MIN_INT std::numeric_limits<int>::min()// 2147483647
#define MAX_INT std::numeric_limits<int>::max()// -2147483648

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	ERROR
};

e_type	isType(std::string literal);
void	printChar(std::string literal);
void	printInt(std::string literal);
void	printFloat(std::string literal);
void	printDouble(std::string literal);
void	printSpecial(std::string literal);

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
	public:
		static void convert(const std::string &literal);
};

#endif
