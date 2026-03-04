#ifndef SPAN_HPP	
# define SPAN_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>
#include <algorithm>
#include <set>
#include <vector>
#include <climits>
#include <ctime>

class Span
{
	private:
		std::multiset<int> v;
		size_t	size;
	public:
		Span();
		Span(int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		void	addRange(int len);
		template<typename T>
		void	addRange(T a, int len)
		{
			for (int i = 0; i < len; i++)
			{
				this->addNumber(a[i]);
			}
		};
};

#endif
