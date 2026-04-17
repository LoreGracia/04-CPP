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
		int		parse(char **av);
		void	execute(std::vector<int>& movPI);
		void	swapPairs(std::vector<int>& movS);
		void	createPent(std::vector< std::vector<int> >& pent);
		std::vector< std::vector<int> >	applyMov(std::vector<int> mov, std::vector< std::vector<int> > pent);
		void	insertion(std::vector< std::vector <int> > pent, std::vector<int> movI);
		void	jacobstalOrder(std::vector<int>& Iorder, std::vector< std::vector<int> > pent);
		void	binarySearch(std::vector<int>::iterator& it, int half, int insert, int& m);
		std::vector<int> addMovs(std::vector<int> mov, std::vector<int> movS, std::vector<int> movI);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		std::vector<int> getRes() const;
		void	calculate(int ac, char **av);
};

std::ostream& operator<<(std::ostream& out, const PmergeMe& pm);
