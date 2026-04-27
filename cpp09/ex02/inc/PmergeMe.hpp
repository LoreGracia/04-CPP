#pragma once

#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <exception>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <stdint.h>
#include <ctime>
extern size_t compv;

#define TYPE_V std::vector< Node_V >

class Node_V
{
	public:
		Node_V * litt;
		size_t head;
		Node_V * big;
		Node_V();
		Node_V(Node_V * l, size_t h, Node_V * b);
		Node_V(const Node_V& other);
		Node_V& operator=(const Node_V& other);
		~Node_V();
};

class PmergeMeV
{
	private:
		std::vector<size_t> _parsed;
		TYPE_V _original;
		std::vector<size_t> _result;
		int					parse(char **av);
		TYPE_V*				fordJhonson(TYPE_V& original);
		size_t				binarySearchIndex(const std::vector<size_t>& arr, size_t value, size_t end);
		void				jacobstalOrder(std::vector < std::vector<size_t> >& Iorder, size_t size);
		std::vector<size_t>	jacobsthal(size_t n);
		size_t				bynarysearch(size_t i, TYPE_V ret, size_t n);
	public:
		PmergeMeV();
		PmergeMeV(const PmergeMeV& other);
		PmergeMeV& operator=(const PmergeMeV& other);
		~PmergeMeV();

		std::vector<size_t> getRes() const;
		void	calculate(char **av);
};

std::ostream& operator<<(std::ostream& out, const PmergeMeV& pm);

//deque version

extern size_t compd;

#define TYPE_D std::deque< Node_D >

class Node_D
{
	public:
		Node_D * litt;
		size_t head;
		Node_D * big;
		Node_D();
		Node_D(Node_D * l, size_t h, Node_D * b);
		Node_D(const Node_D& other);
		Node_D& operator=(const Node_D& other);
		~Node_D();
};

class PmergeMeD
{
	private:
		std::deque<size_t> _parsed;
		TYPE_D _original;
		std::deque<size_t> _result;
		int					parse(char **av);
		TYPE_D*				fordJhonson(TYPE_D& original);
		size_t				binarySearchIndex(const std::deque<size_t>& arr, size_t value, size_t end);
		void				jacobstalOrder(std::deque < std::deque<size_t> >& Iorder, size_t size);
		std::deque<size_t>	jacobsthal(size_t n);
		size_t				bynarysearch(size_t i, TYPE_D ret, size_t n);
	public:
		PmergeMeD();
		PmergeMeD(const PmergeMeD& other);
		PmergeMeD& operator=(const PmergeMeD& other);
		~PmergeMeD();

		std::deque<size_t> getRes() const;
		void	calculate(char **av);
};

std::ostream& operator<<(std::ostream& out, const PmergeMeD& pm);
