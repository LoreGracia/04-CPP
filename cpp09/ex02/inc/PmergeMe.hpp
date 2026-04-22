#pragma once

#include <string>
#include <cstdlib>
#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>

#define TYPE std::vector< t_list >

typedef struct s_list
{
	void *litt;
	int *head;
	void *big;
}			t_list;

class PmergeMe
{
	private:
		std::vector<int> _parsed;
		TYPE _original;
		TYPE _result;
		int					parse(char **av);
		void				fordJhonson(TYPE& original);
		size_t				binarySearchIndex(const std::vector<int>& arr, int value, size_t end);
		std::vector<size_t>	jacobsthalSequence(size_t n);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		TYPE getRes() const;
		void	calculate(char **av);
};

std::ostream& operator<<(std::ostream& out, const PmergeMe& pm);
