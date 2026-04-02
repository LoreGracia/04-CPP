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
		void	swapPairs(std::vector<int>& movS);
		void	createPent(std::vector< std::vector<int> >& pent, std::vector<int>& movI);
		void	jacobstalOrder(std::vector<int>& Iorder, std::vector< std::vector<int> >& new_pent);
		void	getOrder(std::vector<int>& Iorder, std::vector< std::vector<int> >& pent, std::vector<int> mov);
		void	binarySearch(std::vector<int>::iterator& it, std::vector<int>::iterator& itI, size_t half, int insert, int& m);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		std::vector<int> getRes() const;
		void	calculate(int ac, char **av);
};

std::ostream& operator<<(std::ostream& out, const PmergeMe& pm);
