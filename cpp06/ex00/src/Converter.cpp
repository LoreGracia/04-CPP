#include "ScalarConverter.hpp"

e_type	isType(std::string str)
{
	size_t len = str.size();
	if (str == "nan" || str == "-inf" || str == "+inf" ||str == "-inff" || str == "+inff" || str == "nanf")
		return SPECIAL;
	if (isascii(str.at(0)) && !isdigit(str.at(0)))
	{
		if (len == 1)
			return CHAR;
		else if (!((str.at(0) == '-' || str.at(0) == '+')) && isdigit(str.at(1)))
		{
			std::cout << "\033[31mToo many characters, try a char int or float/double value\033[0m" << std::endl;
			return ERROR;
		}
	}
	short dot = 0;
	size_t i = 0;
	if (str.at(0) == '+' || str.at(0) == '-')
		i++;
	while (i < len - 1 && (isdigit(str.at(i)) || str.at(i) == '.'))
	{
		if (str.at(i) == '.')
			dot++;
		if (dot > 1)
			break ;
		i++;
	}
	if (dot > 1)
	{
		std::cout << "\033[31mToo many dots for number type\033[0m" << std::endl;
		return ERROR;
	}
	if (i != len && str.at(i) == 'f')
	{
		if (i == len - 1)
			return FLOAT;
		else
		{
			std::cout << "\033[31mExtra characters after float number\033[0m" << std::endl;
			return ERROR;
		}
	}
	if (i == len - 1)
	{
		i = str.find('.');
		if (i != std::string::npos)
			return DOUBLE;
		else
			return INT;
	}
	std::cout << "\033[31mToo many characters, try a char int or float/double value\033[0m" << std::endl;
	return ERROR;
}

void	cnvrtNprintChar(int literal)
{
	char c = static_cast<char>(literal);
	if (!isprint(c))
		std::cout << "Char: not displayable" << std::endl;
	else if (isascii(c))
		std::cout << "Char: '" << c << "'" << std::endl;
	else
		std::cout << "Char: impossible" << std::endl;
}

void	limitInt(long i)
{
	if (i <= MAX_INT && i >= MIN_INT)
		std::cout << "Int: " << static_cast<int>(i) << std::endl;
	else
		std::cout << "Int: impossible" << std::endl;
}

void	limitFloat(float f)
{
	if (f == static_cast<int>(f))
		std::cout << "Float: " << f << ".0f" << std::endl;
	else
		std::cout << "Float: " << f << "f" << std::endl;
}

void	limitDouble(double d)
{
	if (d == static_cast<int>(d))
		std::cout << "Double: " << d << ".0" << std::endl;
	else
		std::cout << "Double: " << d << std::endl;
}

void	printChar(std::string literal)
{
	char c = static_cast<char>(literal.c_str()[0]);
	std::cout << "Char: " << c << std::endl;
	limitInt(static_cast<int>(c));
	limitFloat(static_cast<float>(c));
	limitDouble(static_cast<double>(c));
}
void	printInt(std::string literal)
{
	int	i = atoi(literal.c_str());
	cnvrtNprintChar(i);
	limitInt(atol(literal.c_str()));
	limitFloat(static_cast<float>(i));
	limitDouble(static_cast<double>(i));
}
void	printFloat(std::string literal)
{
	float	f = strtof(literal.c_str(), NULL);
	cnvrtNprintChar(static_cast<int>(f));
	limitInt(static_cast<long>(f));
	limitFloat(f);
	limitDouble(static_cast<double>(f));
}
void	printDouble(std::string literal)
{
	double d = strtod(literal.c_str(), NULL);
	cnvrtNprintChar(static_cast<int>(d));
	limitInt(static_cast<long>(d));
	limitFloat(static_cast<float>(d));
	limitDouble(d);
}
void	printSpecial(std::string str)
{
	std::cout << "Char: impossible" << std::endl
	<< "Int: impossible" << std::endl;
	if (str == "nan" || str == "nanf")
	{
		std::cout << "Float: nanf" << std::endl
		<< "Double: nan" << std::endl;
	}
	if (str == "-inf" ||str == "-inff")
	{
		std::cout << "Float: -inff" << std::endl
		<< "Double: -inf" << std::endl;
	}
	if (str == "+inf" || str == "+inff")
	{
		std::cout << "Float: +inff" << std::endl
		<< "Double: +inf" << std::endl;
	}
}
