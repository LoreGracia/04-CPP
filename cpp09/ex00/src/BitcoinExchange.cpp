#include "BitcoinExchange.hpp"

std::string	Btc::readData(char end, size_t size, std::ifstream& file)
{
	std::getline(file, tmp, end);
	if (tmp.empty() && !value.empty() && size == 4)
		return (tmp.clear(), tmp);
	if (tmp.empty() && value.empty())
		throw std::logic_error("Database is uncompleted");
	if (tmp.size() != size)
		throw std::logic_error("Datbase date not acceptable");
	for (size_t i = 0; i < tmp.size(); i++)
	{
		if (!isdigit(tmp[i]))
			throw std::logic_error("Database year not acceptable");
	}
	return tmp;
}

Btc::Btc()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::logic_error("Default database unaccessible");
	std::getline(file, tmp);
	if (tmp.empty())
		throw std::logic_error("Database is empty");
	while (tmp.size())
	{
		date = readData('-', 4, file);
		if (date.empty())
			continue ;
		date += readData('-', 2, file);
		date += readData(',', 2, file);
		std::getline(file, value, '\n');
		if (value.empty() && value.empty()) 
			throw std::logic_error("Database is uncompleted");
		for (size_t i = 0; i < value.size(); ++i)
		{
			if (!isdigit(value[i]) && value[i] != '.')
				throw std::logic_error("Database value not acceptable");
		}
		_data[std::strtoul(date.c_str(), NULL, 10)] = std::atof(value.c_str());
	}
	file.close();
}

Btc::Btc(std::string av)
{
	std::ifstream file(av.c_str());
	if (!file.is_open())
		throw std::logic_error("Default database unaccessible");
	std::getline(file, tmp);
	if (tmp.empty())
		throw std::logic_error("Database is empty");
	while (tmp.size())
	{
		date = readData('-', 4, file);
		if (date.empty())
			continue ;
		date += readData('-', 2, file);
		date += readData(',', 2, file);
		std::getline(file, value, '\n');
		if (value.empty() && value.empty()) 
			throw std::logic_error("Database is uncompleted");
		for (size_t i = 0; i < value.size(); ++i)
		{
			if (!isdigit(value[i]) && value[i] != '.')
				throw std::logic_error("Database value not acceptable");
		}
		_data[std::strtoul(date.c_str(), NULL, 10)] = std::atof(value.c_str());
	}
	file.close();
}

Btc::Btc(const Btc& other)
{
	*this = other;
}

Btc& Btc::operator=(const Btc& other)
{
	if (this != &other)
	{
		_data = other._data;
	}
	return *this;
}

Btc::~Btc()
{
}

std::string	Btc::getDate()
{
	std::string date;
	if (tmp[4] != '-' && tmp[7] != '-' && tmp[10] != ' ' && tmp[11] != '|')
		return date;
	std::string year;
	std::string month;
	std::string day;
	for (size_t i = 0; i < 4; i++)
	{
		if (!isdigit(tmp[i]) && (i < 2 && (!isdigit(tmp[i + 5]) || !isdigit(tmp[i + 8]))))
			return date;
	}
	year = tmp.substr(0, 4);
	month = tmp.substr(5, 2);
	day = tmp.substr(8, 2);
	int imonth = std::atoi(month.c_str());
	int iday = std::atoi(day.c_str());
	int iyear = std::atoi(year.c_str());
	if (imonth < 1 || imonth > 12 || iday == 0)
		return date;
	switch (imonth)
	{
		case 2:
			if (iday > 29)
				return date;
			else if (iday == 29 && !(!(iyear % 400) || (!(iyear % 4) && iyear % 100)))
				return date;
			break;
		default:
			if (imonth < 8 && imonth % 2 && iday <= 31)
				break;
			else if (imonth < 8 && !(imonth % 2) && iday <= 30)
				break;
			else if (imonth > 7 && !(imonth % 2) && iday <= 31)
				break;
			else if (imonth > 7 && imonth % 2 && iday <= 30)
				break;
			return date;
	}
	date = year + month + day;
	return date;
}

std::string	Btc::getQuantity()
{
	std::string q;
	int flag = 0;
	for (size_t i = 13; i < tmp.size(); ++i)
	{
		if (!std::isdigit(tmp[i]) && tmp[i] != '.')
			return q;
		if (tmp[i] == '.')
			flag++;
		if (flag > 1)
			return print_error("yeah right, too many point"), "";
	}
	q = tmp.substr(13, tmp.size() - 13);
	if (std::strtof(q.c_str(), NULL) > std::numeric_limits<int>::max())
		return print_error("too large a number"), "";
	return q;
}

void	Btc::print_error(std::string str)
{
	std::cout << "Error: " << str << std::endl;
}

float	Btc::searchPrize()
{
	size_t tdate = std::strtoul(date.c_str(), NULL, 10);
	std::map<size_t, float>::iterator min = std::min_element(_data.begin(), _data.end());
	if (min->first > tdate)
		return -1;
	std::map<size_t, float>::iterator max = std::max_element(_data.begin(), _data.end());
	if (max->first < tdate)
		return max->second;
	for (std::map<size_t, float>::iterator i = min; i != max; i++)
	{
		if (i->first == tdate)
			return i->second;
		else if (i->first > tdate)
			return (--i, i->second);
	}
	return -1;
}

void	Btc::print_prize(std::string str)
{
	float prize = searchPrize();
	if (prize == -1)
		print_error("no data for date");
	else
	{
		prize = prize * std::strtof(value.c_str(), NULL);
		if (prize > std::numeric_limits<int>::max())
			print_error("too large a number");
		else
		{
			int len = 0;
			int i = prize;
			while (i)
			{
				len++;
				i /= 10;
			}
			std::cout << std::setprecision(len + 2) << str << prize << std::endl;
		}
	}
}

void	Btc::findPrize(std::string input)
{
	std::ifstream file(input.c_str());
	if (!file.is_open())
		throw std::logic_error("Input file unaccessible");
	if (!getline(file, tmp))
		throw std::logic_error("Empty file");
	while (getline(file, tmp))
	{
		date = getDate();
		if (date.empty())
		{
			print_error("bad input => " + tmp.substr(0, 10));
			continue ;
		}
		if (tmp.size() < 13)
		{
			print_error ("missing arguments");
			continue ;
		}
		if (tmp.substr(10, 3) != " | ")
		{
			print_error ("wrong sintax"); continue ;
			continue ;
		}
		value = getQuantity();
		if (value.empty())
		{
			print_error("not a positive number");
			continue ;
		}
		print_prize(tmp.substr(0, 10) +  " => " + value + " = ");
	}
}

