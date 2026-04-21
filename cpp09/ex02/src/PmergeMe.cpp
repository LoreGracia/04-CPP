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
		else
			std::cout << "|" << *(int*)(v[i][1]);
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
	std::vector< std::vector<void*> > res;
	for (size_t i = 0; i < _res.size(); i++)
	{
		std::vector<void*> tmp;
		tmp.push_back(NULL);
		tmp.push_back(&_res[i]);
		tmp.push_back(NULL);
		_result.push_back(tmp);
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
		if (*(int *)(main[i][1]) > *(int *)(main[i + 1][1]))
		{
			main[i][0] = main[i + 1][1];
			main.erase(main.begin() + i + 1);
		}
		else
		{
			main[i + 1][0] = main[i][1];
			main.erase(main.begin() + i);
		}
	}
	print_v_p(main, "	Pairs");
	std::vector< std::vector<void*> > n_main;
	for (size_t i = 0; i < main.size(); i++)
	{
		std::vector<void*> tmp;
		tmp.push_back(main[i][0]);
		std::cout << *(int*)(tmp[0]) << std::endl;
		tmp.push_back(NULL);
		tmp.push_back(&(main[i]));
		// std::cout << "inserted direction " << &(main[i]) << " == ";
		// std::cout << ((TYPE*)(tmp[2])) << std::endl;
		// std::cout << "next is same? " << (*(TYPEV*)&(main[i]))[1] << " ";
		// std::cout << (*(TYPEV*)(tmp[2]))[1] << " ";
		// std::cout << std::endl;
		// std::cout << "n is same? " << *(int*)(*(TYPEV*)&(main[i]))[1] << " ";
		// std::cout << *(int*)((*(TYPEV*)(tmp[2]))[1]) << " ";
		// std::cout << std::endl;
		n_main.push_back(tmp);
		tmp.clear();
	}
	std::cout << "ENTRA" << std::endl;
	// if (n_main.size() > 1)
	// 	fordJhonson(n_main);
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
		std::vector<void*> tmp;
		// std::cout << "big " << n_main[i][0] << " ";
		// std::cout << *(int*)(n_main[i][0]) << std::endl;
		// std::cout << "little " << (int *)((*(TYPEV*)(n_main[i][2]))[1]) << " ";
		// std::cout << *(int *)((*(TYPEV*)(n_main[i][2]))[1]) << std::endl;
		tmp.push_back((*(TYPEV*)(n_main[i][2]))[0]);
		tmp.push_back(NULL);//arreglar esto
		ret.push_back(tmp);
		tmp.clear();
		tmp.push_back((*(TYPEV*)(n_main[i][2]))[1]);
		tmp.push_back(NULL);//arreglar esto
		// if ((*(TYPEV*)(n_main[i][2]))[2])
		// {
			std::cout << (*(TYPEV*)(n_main[i][2]))[2] << std::endl;
			tmp.push_back((*(TYPEV*)(n_main[i][2]))[2]);
		// }
		ret.push_back(tmp);
		// tmp.clear();
		print_v_p(ret, "	Pairs out");
	}
	main = ret;
	// print_v_p(ret, "Return");
}

// public

void PmergeMe::calculate(char **av)
{
	if (parse(av))
		throw std::logic_error("invalid input");
	if (_result.size() > 1)
		fordJhonson(_result);
}

TYPE PmergeMe::getRes() const { return _result; }

std::ostream &operator<<(std::ostream &out, const PmergeMe &pm)
{
	TYPE res = pm.getRes();
	for (size_t i = 0; i < res.size(); i++)
		out << *(int*)(res[i][1]) << " ";
	return out;
}
