#include "PmergeMe.hpp"

std::vector<int>	sizedVector(size_t it)
{
	std::vector<int> new_v;
	for (size_t i = it; i; i--)
		new_v.push_back(0);
	return new_v;
}

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other)  { _res = other._res; return *this; }
PmergeMe::~PmergeMe() {}

int	PmergeMe::parse(char **av)
{
	if (!av || !av[0] || !av[0][0])
		throw std::logic_error("empty input");
	for (size_t i = 0; av[i]; i++)
	{
		for (size_t j = 0; av[i][j]; j++)
		{
			if (!std::isdigit(av[i][j]))
				return (_res.clear(), 1);
			else
				_res.push_back(std::atoi(av[i]));
		}
	}
	return 0;
}

void	PmergeMe::execute(std::vector<int>& movPI)
{
	std::vector<int> movS;
	for (size_t i = 0; _res[i] && _res[i + 1]; i += 2)
	{
		if (_res[i] > _res[i + 1])
		{
			int tmp = _res[i];
			_res[i] = _res[i + 1];
			_res[i + 1] = tmp;
			movS.push_back(1);
			movS.push_back(-1);
		}
		else
		{
			movS.push_back(0);
			movS.push_back(0);
		}
	}
	if (_res.size() % 2)
			movS.push_back(0);
	std::vector<int> pent;
	for (std::vector<int>::iterator it = _res.begin(); it != _res.end() && (it + 1) != _res.end(); it++)
	{
		pent.push_back(*it);
		it = _res.erase(it);
	}
	// std::vector< std::vector<int> > pent;
	// std::vector<int> tmp;
	// for (std::vector<int>::iterator it = _res.begin(); it != _res.end() && (it + 1) != _res.end(); it++)
	// {
	// 	tmp.push_back(*it);
	// 	it = _res.erase(it);
	// 	tmp.push_back(*it);
	// 	pent.push_back(tmp);
	// 	tmp.clear();
	// }
	std::vector<int> movI = sizedVector(_res.size());
	if (_res.size() > 1)
		execute(movI);
	//INSERTION
	// Get Order
	std::vector<int> Iorder;
	Iorder.push_back(1);
	if (pent.size() > 1)
	{
		std::vector<int> mov;
		for (size_t i = 0; i < movS.size(); i++)
			mov.push_back(movI[movS[i]] + movS[i]);
		std::vector<int> new_pent;
		for (size_t i = 0; i < mov.size(); i++)
			new_pent.push_back(pent[i + mov[i]]);
			// new_pent.push_back(pent[i + mov[i]][0]);
		if (pent.size() > 2)
		{
			size_t jacob = (pow(2, new_pent.size()) - (pow(-1, new_pent.size()))) / 3;
			std::vector<int> jb_sq;
			jb_sq.push_back(1), jb_sq.push_back(3), jb_sq.push_back(2);
			for (size_t i = 2; jb_sq.back() != (int)jacob; i++)
				jb_sq.push_back((2 * jb_sq[i - 2]) + jb_sq[i - 1]);
			int top;
			for (size_t i = 1; jb_sq.size() != jacob; i++)
			{
				top = jb_sq[i];
				for (int tmp = jb_sq[i]; tmp || tmp == top; tmp--)
					Iorder.push_back(tmp);
			}
			if (Iorder.size() != new_pent.size())
			{
				for (size_t i = top + 1; jb_sq.size() != jacob; i++)
					Iorder.push_back(i);
			}
			for (std::vector<int>::iterator i = Iorder.begin(); i != Iorder.end(); i++)
				std::cout << *i << " ";
			std::cout << std::endl;
			pent = new_pent;
		}
		else
			Iorder.push_back(2);
	}
	//Insert
	_res.insert(_res.begin(), pent[0]);
	for (size_t i = 1; i != Iorder.size(); i++)
	{
		// _res.size()/2;
		pent[Iorder[i]];
	}
	(void)movPI;
}

void	PmergeMe::calculate(int ac, char **av)
{
	if (parse(av))
		throw std::logic_error("invalid input");
	std::vector<int> tmp = sizedVector(ac);
	execute(tmp);
}

std::vector<int> PmergeMe::getRes() const { return _res; }

std::ostream& operator<<(std::ostream& out, const PmergeMe& pm)
{
	std::vector<int> res = pm.getRes();
	for (std::vector<int>::iterator i = res.begin(); i != res.end(); i++)
		out << *i << " ";
	return out;
}
