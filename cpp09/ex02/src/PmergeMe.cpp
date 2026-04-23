#include "PmergeMe.hpp"

// debug utils

void print_vd(TYPE v, std::string str)
{
	std::cout << str << ":	";
	for (size_t i = 0; i < v.size(); i++)
	{
		if (!(v[0].big))
			continue ;
		Node d = (*(v[i].big));
		if (!d.litt)
			std::cout << "N";
		else
			std::cout << (*(d.litt)).head << "|";
		std::cout << (d.head) << " ";
	}
	std::cout << std::endl;
}

void print_v(TYPE v, std::string str)
{
	std::cout << str << ":	";
	for (size_t i = 0; i < v.size(); i++)
	{
		if (!v[i].litt)
			std::cout << "N";
		else
			std::cout << (*(v[i].litt)).head << "|";
		std::cout << (v[i].head) << " ";
	}
	std::cout << std::endl;
}

//Node chanonical

Node::Node() {}
Node::Node(Node* l, int h, Node* b) : litt(l), head(h), big(b) {}
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
		_original.push_back(Node(0, _parsed[i], 0));
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

void	PmergeMe::jacobstalOrder(std::vector<int>& Iorder, size_t size)
{
	int a = log2((3 * size) + 1);
	size_t jacob = (pow(2, a) - (pow(-1, a))) / 3;
	std::vector<int> jb_sq;
	jb_sq.push_back(1);
	for (size_t i = 1; jb_sq.back() != (int)jacob; i++)
		jb_sq.push_back((2 * jb_sq[i - 1]) + pow(-1, i));
	Iorder.push_back(0);
	size_t top = 1;
	for (size_t i = 1; i < jb_sq.size(); i++)
	{
		for (size_t tmp = jb_sq[i]; tmp > top; tmp--){
			Iorder.push_back(tmp - 1);}
		top = jb_sq[i];
	}
	if (Iorder.size() != size)
	{
		for (size_t i = jb_sq.back(); Iorder.size() != size; i++)
			Iorder.push_back(i);
	}
}

size_t bynarysearch(size_t i, TYPE ret, int n)
{
	int left = 0;
	int right = i;
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (ret[mid].head <= n)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
	return i;
}

TYPE* PmergeMe::fordJhonson(TYPE& original)
{
	TYPE *main_p = new TYPE(original);
	TYPE main = *main_p;
	Node* odd = 0;
	if (main.size() % 2)
	{
		odd = new Node(original.back());
		main.erase(main.end() - 1);
	}
	for (size_t i = 0; i < original.size()/2; i++)
	{
		if ((main[i].head) > (main[i + 1].head))
		{
			main[i].litt = (&original[i * 2 + 1]);
			main.erase(main.begin() + i + 1);
		}
		else
		{
			main[i + 1].litt = (&original[i * 2]);
			main.erase(main.begin() + i);
		}
	}
	TYPE *ret_p;
	if (main.size() > 1)
	{
		TYPE *recursion = new TYPE;
		for (size_t i = 0; i < main.size(); i++)
			(*recursion).push_back(Node(0, main[i].head, (&main[i])));
		ret_p = fordJhonson(*recursion);
		delete recursion;
	}
	else
		ret_p = new TYPE(main);
	delete main_p;
	std::cout << "VUELVE" << std::endl << std::endl;
	// print_v((*ret_p), "	ret_p");
	std::vector <int> Iorder;
	jacobstalOrder(Iorder, (*ret_p).size());
	// std::cout << "zero Iorder: ";
	// for (size_t i = 0; i < Iorder.size(); i++)
	// 	std::cout << "[" << i << "]" << Iorder[i] << " ";
	// std::cout << std::endl;
	// std::cout << std::endl;
	for (size_t i = 0; i < Iorder.size(); i++)
	{
		if ((*ret_p)[Iorder[i]].litt)
		{
			int it = bynarysearch(Iorder[i], *ret_p, (*((*ret_p)[Iorder[i]].litt)).head);
			(*ret_p).insert((*ret_p).begin() + it, *((*ret_p)[Iorder[i]].litt));
			if ((*ret_p)[Iorder[Iorder[i]]].big)
				(*ret_p)[Iorder[Iorder[i]]] = *((*ret_p)[Iorder[i]].big);
			std::cout << "A [" << i << "]" << Iorder[i] << " " << ((*ret_p)[Iorder[i]]).head << std::endl;
			std::cout << "J " << it - i << std::endl;
			for (size_t j = it; j < Iorder.size(); j++){
				// if (Iorder[j] >= Iorder[it])
					Iorder[j]++;
			std::cout << "Iorder: ";
			for (size_t i = 0; i < Iorder.size(); i++)
				std::cout << "[" << i << "]" << Iorder[i] << " ";
			std::cout << std::endl;}
		}
		std::cout << "B [" << i << "]" << Iorder[i] << " " << ((*ret_p)[Iorder[i]]).head << std::endl;
		if ((*ret_p)[Iorder[i]].big)
			(*ret_p)[Iorder[i]] = *(Node*)((*ret_p)[Iorder[i]].big);
		else
			(*ret_p)[Iorder[i]].litt = 0;
		print_v((*ret_p), "	Round");
	}
	print_v((*ret_p), "Unpairs out");
	if (odd)
	{
		int it = bynarysearch((*ret_p).size(), *ret_p, (*odd).head);
		if ((*odd).big)
			(*ret_p).insert((*ret_p).begin() + it, *((*odd).big));
		else
			(*ret_p).insert((*ret_p).begin() + it, (*odd));
		}
	// print_v((*ret_p), "return");
	return ret_p;
}

// public

void PmergeMe::calculate(char **av)
{
	if (parse(av))
		throw std::logic_error("invalid input");
	TYPE* result;
	if (_original.size() > 1)
		result = fordJhonson(_original);
	for (size_t i = 0; i < (*result).size(); i++)
		_result.push_back((*result)[i].head);
	delete result;
}

std::vector<int> PmergeMe::getRes() const { return _result; }

std::ostream &operator<<(std::ostream &out, const PmergeMe &pm)
{
	std::vector<int> res = pm.getRes();
	for (size_t i = 0; i < res.size(); i++)
		out << res[i] << " ";
	return out;
}
