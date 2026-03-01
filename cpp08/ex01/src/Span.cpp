#include "Span.hpp"

Span::Span() : v(0), size(0)
{
	std::cout << "\033[34mDefault constructor called\033[0m" << std::endl;
}

Span::Span(int N) : v(0), size(N)
{
	std::cout << "\033[34mSpan constructor called\033[0m" << std::endl;
}

Span::Span(const Span& other)
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		v = other.v;
		size = other.size;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "\033[34mDefault destructor called\033[0m" << std::endl;
}

void	Span::addNumber(int n)
{
	if (v.size() == size)
		throw std::out_of_range("Span is already full");
	v.push_back(n);
}

int		Span::shortestSpan()
{
	if (v.size() <= 1)
		throw std::logic_error("\033[31mToo few for span\033[0m");
	int span = INT_MAX;
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v.size(); j++)
		{
			if (i == j)
			continue;
			if (v[i] < v[j])
			{
				if (v[j] - v[i] < span)
					span = v[j] - v[i];
			}
			else
			{
				if (v[i] - v[j] < span)
					span = v[i] - v[j];
			}
		}
	}
	return span;
}

int		Span::longestSpan()
{
	if (v.size() <= 1)
		throw std::logic_error("\033[31mToo few for span\033[0m");
	int max = 0;
	int min = v[0];
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] < min)
			min = v[i];
		if (v[i] > max)
			max = v[i];
	}
	return (max - min);
}
