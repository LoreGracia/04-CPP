#include "Span.hpp"

Span::Span() : v(), size(0)
{
	std::cout << "\033[34mDefault constructor called\033[0m" << std::endl;
}

Span::Span(int N) : v(), size(N)
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
		throw std::out_of_range("\033[31mSpan is already full\033[0m");
	v.insert(n);
}

int		Span::shortestSpan()
{
	if (v.size() <= 1)
		throw std::logic_error("\033[31mToo few for span\033[0m");
	int span = INT_MAX;
	std::multiset<int>::iterator next = v.begin();
	++next;
	for (std::multiset<int>::iterator i = v.begin(); next != v.end(); ++i)
	{
		if (*next - *i < span)
			span = *next - *i;
		++next;
	}
	return span;
}

int		Span::longestSpan()
{
	if (v.size() <= 1)
		throw std::logic_error("\033[31mToo few for span\033[0m");
	std::multiset<int>::iterator end = --v.end();
	return (*end - *v.begin());
}

void	Span::addRange(int len)
{
	srand(time(0));
	for (int i = 0; i < len; i++)
		this->addNumber(rand());
}
