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
			std::cout << (*(d.litt)).head << "<";
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
			std::cout << (*(v[i].litt)).head << "<";
		std::cout << (v[i].head) << " ";
	}
	std::cout << std::endl;
}

//Node chanonical

Node::Node() {}
Node::Node(Node* l, size_t h, Node* b) : litt(l), head(h), big(b) {}
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

void	PmergeMe::jacobstalOrder(std::vector < std::vector<size_t> >& Iorder, size_t size)
{
	size_t a = log2((3 * size) + 1);
	size_t jacob = (pow(2, a) - (pow(-1, a))) / 3;
	std::vector<size_t> jb_sq;
	jb_sq.push_back(1);
	std::vector<size_t> tmp;
	tmp.push_back(0);
	Iorder.push_back(tmp);
	for (size_t i = 1; jb_sq.back() != jacob; i++)
		jb_sq.push_back((2 * jb_sq[i - 1]) + pow(-1, i));
	for (size_t i = 2; i < jb_sq.size(); i++)
	{
		tmp.clear();
		tmp.push_back(jb_sq[i] - 1);
		Iorder.push_back(tmp);
	}
	for (size_t i = 1; i < Iorder.size(); i++)
	{
		size_t top = Iorder[i - 1][0];
		for (size_t temp = Iorder[i][0] - 1; temp > top; temp--)
			Iorder[i].push_back(temp);
	}
	tmp.clear();
	if (Iorder.back()[0] < size)
	{
		for (size_t i = Iorder.back()[0] + 1; i != size; i++){
			tmp.push_back(i);
			Iorder.push_back(tmp);
			tmp.clear();
		}
	}
}

size_t bynarysearch(size_t i, TYPE ret, size_t n)
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
}

TYPE* PmergeMe::fordJhonson(TYPE& original)
{
	TYPE *main_p = new TYPE(original);
	Node* odd = NULL;
	if ((*main_p).size() % 2)
	{
		odd = new Node(original.back());
		(*main_p).erase((*main_p).end() - 1);
	}
	size_t size = (original.size() - (odd != NULL))/2;
	for (size_t i = 0; i < size; i++)
	{
		if (((*main_p)[i].head) > ((*main_p)[i + 1].head))
		{
			(*main_p)[i].litt = (&original[i * 2 + 1]);
			(*main_p).erase((*main_p).begin() + i + 1);
		}
		else
		{
			(*main_p)[i + 1].litt = (&original[i * 2]);
			(*main_p).erase((*main_p).begin() + i);
		}
	}
	TYPE *ret_p;
	if ((*main_p).size() > 1)
	{
		TYPE *recursion = new TYPE;
		for (size_t i = 0; i < (*main_p).size(); i++)
			(*recursion).push_back(Node(0, (*main_p)[i].head, (&(*main_p)[i])));
		ret_p = fordJhonson(*recursion);
		delete recursion;
	}
	else
		ret_p = new TYPE((*main_p));
	delete main_p;
	// std::cout << "VUELVE" << std::endl << std::endl;
	// print_v((*ret_p), "	ret_p");
	std::vector < std::vector<size_t> > Iorder;
	jacobstalOrder(Iorder, (*ret_p).size());
	// std::cout << "zero Iorder: ";
	// for (size_t i = 0; i < Iorder.size(); i++){
	// 	std::cout << " " << Iorder[i][0] << ":";
	// 	for (size_t j = 1; j < Iorder[i].size(); j++)
	// 		std::cout << Iorder[i][j] << "_";
	// }
	// std::cout << std::endl;
	// std::cout << std::endl;
	size_t iLitt = 0;
	for (size_t i = 0; i < Iorder.size(); iLitt++)
	{
		// print_v((*ret_p), "A	Round");
		// std::cout << "A [" << i << "][" << iLitt << "]"<< Iorder[i][iLitt] << " " << ((*ret_p)[Iorder[i][iLitt]]).head << std::endl;
		if (((*ret_p)[Iorder[i][iLitt]]).litt)
		{
			size_t it = bynarysearch(Iorder[i][iLitt], *ret_p, (*((*ret_p)[Iorder[i][iLitt]].litt)).head);
			(*ret_p).insert((*ret_p).begin() + it, *((*ret_p)[Iorder[i][iLitt]].litt));
			if (((*ret_p)[it]).big)
				(*ret_p)[it] = *((*ret_p)[it].big);
			size_t limit = Iorder[i][iLitt] - it + 1 + iLitt;
			for (size_t j = iLitt; j < limit && j < Iorder[i].size(); j++)
				Iorder[i][j]++;
			for (size_t j = i + 1; j < Iorder.size(); j++)
			{
				for (size_t jLitt = 0; jLitt <= Iorder[i].size(); jLitt++){
					Iorder[j][jLitt]++;
					// std::cout << Iorder[j][jLitt] << std::endl;
					// std::cout << jLitt << " < " << Iorder[i].size() << std::endl;
				}
			}
		}
		// std::cout << "B [" << i << "]" << Iorder[i][iLitt] << " " << ((*ret_p)[Iorder[i][iLitt]]).head << std::endl;
		if ((*ret_p)[Iorder[i][iLitt]].big)
			(*ret_p)[Iorder[i][iLitt]] = *(Node*)((*ret_p)[Iorder[i][iLitt]].big);
		else
			(*ret_p)[Iorder[i][iLitt]].litt = 0;
		// print_v((*ret_p), "B	Round");
		// std::cout << std::endl;
		if (iLitt == Iorder[i].size() - 1)
		{ 
			// std::cout << "pasa" << std::endl;
			i++;
			iLitt = -1;
		}
	}
	// print_v((*ret_p), "Unpairs out");
	if (odd)
	{
		size_t it = bynarysearch((*ret_p).size(), *ret_p, (*odd).head);
		if ((*odd).big)
			(*ret_p).insert((*ret_p).begin() + it, *((*odd).big));
		else
			(*ret_p).insert((*ret_p).begin() + it, (*odd));
		}
		delete odd;
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

std::vector<size_t> PmergeMe::getRes() const { return _result; }

std::ostream &operator<<(std::ostream &out, const PmergeMe &pm)
{
	std::vector<size_t> res = pm.getRes();
	for (size_t i = 0; i < res.size(); i++)
		out << res[i] << " ";
	return out;
}
