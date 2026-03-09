#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& other) { *this = other; }
RPN& RPN::operator=(const RPN& other)  { (void)other; return *this; }
RPN::~RPN() {}

std::stack<char>& RPN::parse(std::string str, std::stack<char>& s)
{
	
	if (str.empty())
		throw std::logic_error("empty input");
	for (size_t i = str.size() - 1; i != 0; i--)
	{
		if (i != str.size() - 1 && str[i] != ' ')
			throw std::logic_error("too many consecutive characters");
		while (i && str[i] == ' ')
			--i;
		if (std::isdigit(str[i]))
			s.push(str[i]);
		else if (str[i] == '-' || str[i] == '+' || str[i] == '/' || str[i] == '*')
			s.push(str[i]);
		else
			throw std::logic_error("unaccepted character");
		if (!i)
			return s;
	}
	return s;
}

int	RPN::execute(std::stack<char> *s, int a)
{
	int b;
	char sign;
	if (s->empty())
		throw std::logic_error("incomplete formula");
	while (!s->empty())
	{
		if (std::isdigit(s->top()))
		{
			b = s->top() - '0';
			s->pop();
			if (s->empty())
				throw std::logic_error("incomplete formula");
			else if (std::isdigit(s->top()))
				b = execute(s, b);
		}
		if (s->top() == '-' || s->top() == '+' || s->top() == '/' || s->top() == '*')
		{
			sign = s->top();
			s->pop();
		}
		else
			throw std::logic_error("incomplete formula");
		switch (sign)
		{
		case '+':
			a = a + b;
			break;
		case '-':
			a = a - b;
			break;
		case '*':
			a = a * b;
			break;
		case '/':
			a = a / b;
			break;
		
		default:
			throw std::logic_error("2unaccepted character");
		}
		if (!s->empty() && (s->top() == '-' || s->top() == '+' || s->top() == '/' || s->top() == '*'))
			return a;
	}
	return a;
}

int	RPN::calculate(std::string str)
{
	std::stack<char> s;
	parse(str, s);
	int a = std::atoi(&s.top());
	s.pop();
	return execute(&s, a);
}
