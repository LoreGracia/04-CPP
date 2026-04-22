#include "PmergeMe.hpp"

// debug utils

void print_v(TYPE& v, std::string str)
{
	std::cout << str << ": ";
	for (size_t i = 0; i < v.size(); i++)
	{
		if ((v[i].litt) == NULL)
			std::cout << "N";
		else
			std::cout << *(*(t_list*)(v[i].litt)).head << "|";
		std::cout << *(v[i].head) << " ";
	}
	std::cout << std::endl;
}

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
	std::vector< std::vector<void*> > res;
	for (size_t i = 0; i < _parsed.size(); i++)
	{
		t_list tmp;
		tmp.litt = NULL;
		tmp.head = &_parsed[i];
		tmp.big = NULL;
		_original.push_back(tmp);
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

void PmergeMe::fordJhonson(TYPE& original)
{
	print_v(original, "	Original");
	TYPE main = original;
	t_list* odd = NULL;
	if (main.size() % 2)
	{
		odd = &original.back();
		main.erase(main.end() - 1);
	}
	for (size_t i = 0; i < original.size()/2; i++)
	{
		if (*(main[i].head) > *(main[i + 1].head))
		{
			t_list tmp = original[i * 2 + 1];
			main[i].litt = &tmp;
			main.erase(main.begin() + i + 1);
		}
		else
		{
			t_list tmp = original[i * 2];
			main[i + 1].litt = &tmp;
			main.erase(main.begin() + i);
			// std::cout << "new litt " <<  *((*(t_list*)(main[i].litt)).head) << std::endl;
		}
	}
	print_v(main, "	Swap");
	std::cout << "ENTRA" << std::endl;
	if (main.size() > 1)
	{
		TYPE recursion;
		for (size_t i = 0; i < main.size(); i++)
		{
			t_list tmp;
			tmp.litt = NULL;
			tmp.head = main[i].head;
			tmp.big = &main[i];
			recursion.push_back(tmp);
		}
		fordJhonson(recursion);
		main = recursion;
	}
	std::cout << "VUELVE" << std::endl;
	print_v(main, "	Swap");
	TYPE ret = main;//AAAAAAAAAAAAAAAAAAA
	print_v(main, "	Swap");
	print_v(ret, "	ret");
	size_t size = ret.size();
	for (size_t i = 0; i < size; i++)
	{
		// if (ret[i].litt)
		// {
		// 	ret.insert(ret.begin() + i, *(t_list*)(ret[i].litt));
		// 	i++;
		// }
		// if (ret[i].big)
		// 	ret[i] = *(t_list*)(ret[i].big);
		std::cout << "pasa 0 " << std::endl;
	}
	// print_v(ret, "	Unpairs out");
	std::cout << "pasa 1 " << std::endl;
	if (odd)
		ret.push_back(*odd);
	print_v(ret, "	Unpairs out");
	original = ret;
	print_v(ret, "Return");
}

// public

void PmergeMe::calculate(char **av)
{
	if (parse(av))
		throw std::logic_error("invalid input");
	_result = _original;
	if (_original.size() > 1)
		fordJhonson(_result);
}

TYPE PmergeMe::getRes() const { return _result; }

std::ostream &operator<<(std::ostream &out, const PmergeMe &pm)
{
	TYPE res = pm.getRes();
	for (size_t i = 0; i < res.size(); i++)
		out << *(res[i].head) << " ";
	return out;
}
