#include "PmergeMe.hpp"

// debug utils

void print_pent(std::vector< std::vector<int> > pent)
{
	std::cout << "PENT: ";
	for (std::vector< std::vector<int> >::iterator it = pent.begin(); it != pent.end(); it++)
		std::cout << (*it)[0] << " ";
	std::cout << std::endl;
}

void print_v(std::vector<int> v, std::string str)
{
	std::cout << str << ": ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void print_v_p(std::vector< std::vector<void*> >& v, std::string str)
{
	std::cout << str << ": ";
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << *(int*)(v[i][0]);
		if ((v[i][1]) == NULL)
			std::cout << "N";
		// else
		// 	std::cout << "|" << *(int*)(v[i][1]);
		std::cout << " ";
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	_res = other._res;
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
				return (_res.clear(), 1);
		}
		_res.push_back(std::atoi(av[i]));
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

void fordJhonson(TYPE& main)
{
	std::vector<void*> odd;
	odd.push_back(NULL);
	if (main.size() % 2)
	{
		odd[0] = &main.back();
		main.erase(main.end() - 1);
	}
	for (size_t i = 0; i < main.size(); i++)
	{
		if (*(int *)(main[i][0]) > *(int *)(main[i + 1][0]))
		{
			main[i][1] = main[i + 1][0];
			main.erase(main.begin() + i + 1);
		}
		else
		{
			main[i + 1][1] = main[i][0];
			main.erase(main.begin() + i);
		}
	}
	print_v_p(main, "Pairs");
	std::vector< std::vector<void*> > n_main;
	for (size_t i = 0; i < main.size(); i++)
	{
		std::vector<void*> tmp;
		tmp.push_back(main[i][0]);
		tmp.push_back(NULL);
		tmp.push_back(&main[i]);
		n_main.push_back(tmp);
	}
	if (main.size() > 1)
		fordJhonson(main);
	std::cout << "VUELVE" << std::endl;
	// bajar nivel de punteros | Insertion | odd
    // std::vector<size_t> jac = jacobsthal(main.size());
	// std::vector<T> new_main;
	// typename std::vector<T>::iterator it;
	// for (size_t i = 0; i < pairs.size(); i++)
	// {
	// 	new_main.push_back(pairs[jac[i]].second);
	// 	it = std::upper_bound(new_main.begin(), new_main.end(), pairs[jac[i]].first);
	// 	new_main.insert(it, pairs[jac[i]].second);
	// }
	// main = new_main;
	// if (odd == NULL)
	// 	odd = NULL;
	std::vector< std::vector<void*> > ret;
	for (size_t i = 0; i < main.size(); i++)
	{
		std::cout << "1 pasa" << std::endl;
		std::vector<void*> tmp;
		std::cout << (*(TYPE*)(n_main[i][2]))[0][1] << std::endl;
		tmp.push_back((*(TYPE*)(n_main[i][2]))[0][1]);
		tmp.push_back(n_main[i][0]);
		tmp.push_back((*(TYPE*)(n_main[i][2]))[0][2]);
		ret.push_back(tmp);
		std::cout << "3 pasa" << std::endl;
	}
	std::cout << "1 pasa" << std::endl;
	// print_v_p(ret, "Return");
	std::cout << "2 pasa" << std::endl;
}

// public

void PmergeMe::calculate(char **av)
{
	if (parse(av))
		throw std::logic_error("invalid input");
	std::vector< std::vector<void*> > res;
	for (size_t i = 0; i < _res.size(); i++)
	{
		std::vector<void*> tmp;
		tmp.push_back(&_res[i]);
		tmp.push_back(NULL);
		tmp.push_back(NULL);
		res.push_back(tmp);
	}
	if (_res.size() > 1)
		fordJhonson(res);
}

std::vector<int> PmergeMe::getRes() const { return _res; }

std::ostream &operator<<(std::ostream &out, const PmergeMe &pm)
{
	std::vector<int> res = pm.getRes();
	for (std::vector<int>::iterator i = res.begin(); i != res.end(); i++)
		out << *i << " ";
	return out;
}
