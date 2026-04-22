#include "PmergeMe.hpp"

// debug utils

void print_vd(TYPE& v, std::string str)
{
	std::cout << str << ":	";
	for (size_t i = 0; i < v.size(); i++)
	{
		if (!(v[0].big))
			continue ;
		Node d = (*reinterpret_cast<Node*>(v[i].big));
		if (!d.litt)
			std::cout << "N";
		else
			std::cout << (*reinterpret_cast<Node*>(d.litt)).head << "|";
		std::cout << (d.head) << " ";
	}
	std::cout << std::endl;
}

void print_v(TYPE& v, std::string str)
{
	std::cout << str << ":	";
	for (size_t i = 0; i < v.size(); i++)
	{
		if (!v[i].litt)
			std::cout << "N";
		else
			std::cout << (*reinterpret_cast<Node*>(v[i].litt)).head << "|";
		std::cout << (v[i].head) << " ";
	}
	std::cout << std::endl;
}

//Node chanonical

Node::Node() {}
Node::Node(uintptr_t l, int h, uintptr_t b) : litt(l), head(h), big(b) {}
Node::Node(const Node& other) { *this = other; }
Node& Node::operator=(const Node& other)
{
	head = other.head;
	big = other.big;
	litt = other.litt;
	return *this;
}
Node::~Node() {}

//PmergeMe chanonical

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	_parsed = other._parsed;
	_original = other._original;
	_result = other._result;
	return *this;
}
PmergeMe::~PmergeMe() {}

int PmergeMe::parse(char **av)
{
	if (!av || !av[0] || !av[0][0])
		throw std::logic_error("empty input");
	for (size_t i = 0; av[i]; i++)
	{
		for (size_t j = 0; av[i][j]; j++)
		{
			if (!std::isdigit(av[i][j]))
				return (_parsed.clear(), 1);
		}
		_parsed.push_back(std::atoi(av[i]));
	}
	for (size_t i = 0; i < _parsed.size(); i++)
	{
		_original.push_back(*new Node(0, _parsed[i], 0));
	}
	return 0;
}

std::vector<size_t> jacobsthal(size_t n)
{
    std::vector<size_t> j;
    j.push_back(0);
    j.push_back(1);

    while (j.back() < n)
    {
        size_t sz = j.size();
        j.push_back(j[sz - 1] + 2 * j[sz - 2]);
    }
    return j;
}

TYPE PmergeMe::fordJhonson(TYPE& original)
{
	print_v(original, "	Original");
	print_vd(original, "inside RECURSION down");
	TYPE main = *new TYPE(original);
	print_vd(main, "inside RECURSION down");
	Node* odd = 0;
	if (main.size() % 2)
	{
		odd = new Node(original.back());
		main.erase(main.end() - 1);
	}
	if (odd){
		std::cout << "								ODD" << " ";
		std::cout << (*odd).head << " "
		// << (*(reinterpret_cast<Node*>((*odd).litt))).head
		<< std::endl;
		}
	for (size_t i = 0; i < original.size()/2; i++)
	{
		if ((main[i].head) > (main[i + 1].head))
		{
			main[i].litt = reinterpret_cast<uintptr_t>(&original[i * 2 + 1]);
			main.erase(main.begin() + i + 1);
		}
		else
		{
			main[i + 1].litt = reinterpret_cast<uintptr_t>(&original[i * 2]);
			main.erase(main.begin() + i);
			// std::cout << "new litt " <<  *((*(Node*)(main[i].litt)).head) << std::endl;
		}
	}
	print_v(main, "	Swap");
	print_vd(main, "inside RECURSION down");
	if (main[0].litt){
		std::cout << (*reinterpret_cast<Node*>(main[0].litt)).head << " ";
		std::cout << (*reinterpret_cast<Node*>(main[0].litt)).litt << std::endl;}
	std::cout << "ENTRA" << std::endl;
	TYPE recursion = *new TYPE;
	TYPE ret;
	if (main.size() > 1)
	{
		for (size_t i = 0; i < main.size(); i++)
		{
			recursion.push_back(*new Node(0, main[i].head, reinterpret_cast<uintptr_t>(&main[i])));
		}
		print_v(main, "main upper");
		print_vd(recursion, "RECURSION down");
		ret = fordJhonson(recursion);
	}
	else
		ret = *new TYPE(main);//AAAAAAAAAAAAAAAAAAA
	std::cout << "VUELVE" << std::endl;
	// if (main[0].litt){
	// std::cout << (*reinterpret_cast<Node*>(ret[0].litt)).head << " ";
	// std::cout << (*reinterpret_cast<Node*>(ret[0].litt)).litt << std::endl;
	// 	std::cout << (*reinterpret_cast<Node*>(main[0].litt)).head << " ";
	// 	std::cout << (*reinterpret_cast<Node*>(main[0].litt)).litt << std::endl;}
	// print_v(main, "	Swap");
	print_v(ret, "	ret");
	for (size_t i = 0; i < ret.size(); i++)
	{
		if (ret[i].litt)
		{
				//binary
			// std::cout << " new little pair" << (*reinterpret_cast<Node*>(ret[i].litt)).head << " ";
			// std::cout << (*reinterpret_cast<Node*>((*reinterpret_cast<Node*>(ret[i].litt)).litt)).head << std::endl;
			// print_vd(ret, "INSERTIN");
			ret.insert(ret.begin() + i, *reinterpret_cast<Node*>(ret[i].litt));
			if (ret[i].big)
				ret[i] = *reinterpret_cast<Node*>(ret[i].big);
			i++;
		}
		if (ret[i].big)
			ret[i] = *(Node*)(ret[i].big);
		else
			ret[i].litt = 0;
	}
	// print_v(ret, "	Unpairs out");
	print_v(ret, "	Unpairs out");
	if (odd)
	{
		if ((*odd).big)
			ret.push_back(*reinterpret_cast<Node*>((*odd).big));
		else
			ret.push_back(*odd);
	}
	print_v(ret, "	Unpairs out");
	// original = *new TYPE(ret);
	print_v(ret, "Return");
	return ret;
}

// public

void PmergeMe::calculate(char **av)
{
	if (parse(av))
		throw std::logic_error("invalid input");
	if (_original.size() > 1)
		_result = fordJhonson(_original);
}

TYPE PmergeMe::getRes() const { return _result; }

std::ostream &operator<<(std::ostream &out, const PmergeMe &pm)
{
	TYPE res = pm.getRes();
	for (size_t i = 0; i < res.size(); i++)
		out << (res[i].head) << " ";
	return out;
}
