#pragma once

#include <string>
#include <cstdlib>
#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <stdint.h>

#define TYPE std::vector< Node >

class Node
{
	public:
		Node * litt;
		int head;
		Node * big;
		Node();
		Node(Node * l, int h, Node * b);
		Node(const Node& other);
		Node& operator=(const Node& other);
		~Node();
};

class PmergeMe
{
	private:
		std::vector<int> _parsed;
		TYPE _original;
		std::vector<int> _result;
		int					parse(char **av);
		TYPE*				fordJhonson(TYPE& original);
		size_t				binarySearchIndex(const std::vector<int>& arr, int value, size_t end);
		void				jacobstalOrder(std::vector<int>& Iorder, size_t size);
		// std::vector<size_t>	jacobsthalSequence(size_t n);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		std::vector<int> getRes() const;
		void	calculate(char **av);
};

std::ostream& operator<<(std::ostream& out, const PmergeMe& pm);
