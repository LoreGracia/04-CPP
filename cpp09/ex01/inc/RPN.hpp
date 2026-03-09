#pragma once

#include <string>
#include <cstdlib>
#include <iostream>
#include <exception>
#include <algorithm>
#include <stack>

class RPN
{
	private:
		int		execute(std::stack<char> *s, int a);
		std::stack<char>&	parse(std::string str, std::stack<char>& s);
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int	calculate(std::string str);
};
