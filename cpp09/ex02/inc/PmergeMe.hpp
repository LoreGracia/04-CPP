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
		int					parse(char **av);
		std::vector<int>	fordJohnson(std::vector<int> input);
		size_t				binarySearchIndex(const std::vector<int>& arr, int value, size_t end);
		std::vector<size_t>	jacobsthalSequence(size_t n);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		std::vector<int> getRes() const;
		void	calculate(char **av);
};

std::ostream& operator<<(std::ostream& out, const PmergeMe& pm);
