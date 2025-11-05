#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "\033[34mScalarConverter constructor called\033[0m" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "\033[34mScalarConverter copy constructor called\033[0m" << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		*this = other;
	}
	return *this; 
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "\033[34mScalarConverter destructor called\033[0m" << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	e_type type = isType(literal);
	std::cout << "Type: " << type << std::endl;
	switch (type)
	{
		case CHAR:
			printChar(literal);
			break;
		case SPECIAL:
			printSpecial(literal);
			break;
		case INT:
			printInt(literal);
			break;
		case FLOAT:
			printFloat(literal);
			break;
		case DOUBLE:
			printDouble(literal);
			break;
		
		default:
			break;
	}
}


