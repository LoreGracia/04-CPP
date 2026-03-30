#pragma once

#include <string>
#include <cstdlib>
#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>

class PmergeMe
{
	private:
		std::vector<int> _res;
		void	execute(std::vector<int>& movPI);
		int		parse(char **av);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		std::vector<int> getRes() const;
		int	calculate(int ac, char **av);
};

std::ostream& operator<<(std::ostream& out, const PmergeMe& pm);
