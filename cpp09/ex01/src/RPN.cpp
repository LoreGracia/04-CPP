#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& other) { *this = other; }
RPN& RPN::operator=(const RPN& other)  { (void)other; return *this; }
RPN::~RPN() {}

std::stack<char>& RPN::parse(std::string str, std::stack<char>& s)
{
	if (str.empty())
		throw std::logic_error("empty input");
	for (int i = str.size() - 1; i != -1; i--)
	{
		if (i != (int)(str.size() - 1) && str[i] != ' ')
			throw std::logic_error("too many consecutive characters");
		while (i && str[i] == ' ')
			--i;
		if (i == -1)
			return s;
		if (std::isdigit(str[i]))
			s.push(str[i]);
		else if (str[i] == '-' || str[i] == '+' || str[i] == '/' || str[i] == '*')
			s.push(str[i]);
		else
			throw std::logic_error("unaccepted character");
	}
	return s;
}

int	RPN::execute(std::stack<char> *s, int a)
{
	int b = - 1;
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
		if (sign && b == -1)
			throw std::logic_error("incorrect order");
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
			if (!b)
				throw std::logic_error("not possible");
			a = a / b;
			break;
		
		default:
			throw std::logic_error("unaccepted character");
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
	a = execute(&s, a);
	if (!s.empty())
		throw std::logic_error("what are you doing with those consecutive signs");
	return a;
}
