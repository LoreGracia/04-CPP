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
extern size_t comp;

#define TYPE std::vector< Node >

class Node
{
	public:
		Node * litt;
		size_t head;
		Node * big;
		Node();
		Node(Node * l, size_t h, Node * b);
		Node(const Node& other);
		Node& operator=(const Node& other);
		~Node();
};

class PmergeMe
{
	private:
		std::vector<size_t> _parsed;
		TYPE _original;
		std::vector<size_t> _result;
		int					parse(char **av);
		TYPE*				fordJhonson(TYPE& original);
		size_t				binarySearchIndex(const std::vector<size_t>& arr, size_t value, size_t end);
		void				jacobstalOrder(std::vector < std::vector<size_t> >& Iorder, size_t size);
		// std::vector<size_t>	jacobsthalSequence(size_t n);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		std::vector<size_t> getRes() const;
		void	calculate(char **av);
};

std::ostream& operator<<(std::ostream& out, const PmergeMe& pm);
