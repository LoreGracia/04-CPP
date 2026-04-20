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

void print_v_t(std::vector<size_t> v, std::string str)
{
	std::cout << str << ": ";
	for (std::vector<size_t>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
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

template<typename T>
void fordJhonson(std::vector<T>& main)
{
	T* odd = NULL;
	if (main.size() % 2)
	{
		odd = &main.back();
		main.erase(main.end() - 1);
	}
	std::vector< std::pair<T, T> > pairs;
	for (size_t i = main.size(); i < main.size(); i++)
	{
		if (main[i] < main[i + 1])
		{
			pairs.push_back(std::make_pair(main[i], main[i + 1]));
			main.erase(main.begin() + i);
		}
		else
		{
			pairs.push_back(std::make_pair(main[i + 1], main[i]));
			main.erase(main.begin() + i + 1);
		}
	}
	if (main.size() > 1)
		fordJhonson(pairs);
    std::vector<size_t> jac = jacobsthal(main.size());
	std::vector<T> new_main;
	typename std::vector<T>::iterator it;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		new_main.push_back(pairs[jac[i]].second);
		it = std::upper_bound(new_main.begin(), new_main.end(), pairs[jac[i]].first);
		new_main.insert(it, pairs[jac[i]].second);
	}
	main = new_main;
	if (odd == NULL)
		odd = NULL;
}

// public

void PmergeMe::calculate(char **av)
{
	if (parse(av))
		throw std::logic_error("invalid input");
	if (_res.size() > 1)
		fordJhonson(_res);
}

std::vector<int> PmergeMe::getRes() const { return _res; }

std::ostream &operator<<(std::ostream &out, const PmergeMe &pm)
{
	std::vector<int> res = pm.getRes();
	for (std::vector<int>::iterator i = res.begin(); i != res.end(); i++)
		out << *i << " ";
	return out;
}
