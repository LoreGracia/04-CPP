#include "PmergeMe.hpp"

//debug utils

void print_pent(std::vector< std::vector <int> > pent)
{
	std::cout << "PENT: ";
	for (std::vector< std::vector <int> >::iterator it = pent.begin(); it != pent.end(); it++)
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

//program

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
		}
		_res.push_back(std::atoi(av[i]));
	}
	return 0;
}

void	PmergeMe::swapPairs(std::vector<int>& movS)
{
	for (size_t i = 0; i + 1 < _res.size(); i += 2)
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
}

void	PmergeMe::createPent(std::vector< std::vector<int> >& pent)
{
	std::vector<int> tmp;
	for (std::vector<int>::iterator it = _res.begin(); it != _res.end() && (it + 1) != _res.end(); it++)
	{
		tmp.push_back(*it);
		it = _res.erase(it);
		tmp.push_back(*it);
		pent.push_back(tmp);
		tmp.clear();
	}
}

std::vector< std::vector<int> >	PmergeMe::applyMov(std::vector<int> mov, std::vector< std::vector<int> > pent)
{
	std::vector<int> tmp = sizedVector(pent.size());
	for (size_t i = 0; i < mov.size(); i++)
		tmp[i + mov[i]] = i;
	print_v(tmp, "Apply swap tmp");
	std::vector< std::vector<int> > new_pent;
	for (size_t i = 0; i < tmp.size(); i++)
		new_pent.push_back(pent[tmp[i]]);
	print_pent(new_pent);
	return new_pent;
}

void	PmergeMe::jacobstalOrder(std::vector<int>& Iorder, std::vector< std::vector<int> > pent)
{
	int a = log2((3 * pent.size()) + 1);
	size_t jacob = (pow(2, a) - (pow(-1, a))) / 3;
	std::vector<int> jb_sq;
	jb_sq.push_back(1);
	for (size_t i = 1; jb_sq.back() != (int)jacob; i++)
		jb_sq.push_back((2 * jb_sq[i - 1]) + pow(-1, i));
	Iorder[0] = 0;
	size_t top = 1;
	for (size_t i = 1; i < jb_sq.size(); i++)
	{
		for (size_t tmp = jb_sq[i]; tmp > top; tmp--){
			Iorder.push_back(tmp - 1);}
		top = jb_sq[i];
	}
	if (Iorder.size() != pent.size())
	{
		for (size_t i = jb_sq.back(); Iorder.size() != pent.size(); i++)
			Iorder.push_back(i);
	}
	print_v(Iorder, "Insertion order");
}

void	PmergeMe::insertion(std::vector< std::vector <int> > pent, std::vector<int> movI)
{
	std::vector<int> Iorder;
	jacobstalOrder(Iorder, pent);
	std::vector<int>::iterator it;
	for (size_t i = 0; i < Iorder.size(); i++)
	{
		int m = 0;
		int diff = Iorder[i] + movI[Iorder[i] * 2];
		it = _res.begin() + diff;
		std::cout << "inserting " << pent[Iorder[i]][0] << " Pair: " << pent[Iorder[i]][1] << " Found: " << *it << std::endl;
		binarySearch(it, diff/2, pent[Iorder[i]][0], m);
		std::cout << "counted movements " << m << std::endl;
		_res.insert(it, pent[Iorder[i]][0]);
		movI[Iorder[i] * 2] = m;
		for (size_t i = -m; m && i; i--)
			movI[movI.size() - 1 - i]++;
	}
	print_v(movI, "MovI");
}

void	PmergeMe::binarySearch(std::vector<int>::iterator& it, int half, int insert, int& m)
{
	it -= half;
	m -= half;
	if (*it > insert)
		half /= 2;
	else if (*it < insert)
		half = -(half/2);
	if (half != 0)
		binarySearch(it, half, insert, m);
}

std::vector<int> PmergeMe::addMovs(std::vector<int> mov, std::vector<int> movS, std::vector<int> movI)
{
	std::vector<int> n_mov = sizedVector(mov.size());
	for (size_t i = 0; i < n_mov.size(); i++)
	{
		n_mov[i] = mov[i] * 2;
		n_mov[i + 1] = n_mov[i];
	}
	std::vector<int> movP = sizedVector(n_mov.size());
	for (size_t i = 0; i < movP.size(); i++)
		movP[i] = mov[i] + movS[i] + movI[mov[i] + i];
	print_v(movP, "			FOR NEXT");
	return movP;
}

void	PmergeMe::execute(std::vector<int>& movPI)
{
	(void)movPI;
	std::vector<int> movS;
	swapPairs(movS);
	print_v(movS, "Mov Swap");
	std::vector< std::vector <int> > pent;
	createPent(pent);
	print_pent(pent);
	std::vector<int> mov;
	if (_res.size() > 1)
		execute(mov);
	applyMov(mov, pent);
	std::vector<int> movI = sizedVector(movS.size());
	insertion(pent, movI);
	movPI = addMovs(mov, movS, movI);
}

void	PmergeMe::calculate(int ac, char **av)
{
	if (parse(av))
		throw std::logic_error("invalid input");
	if (_res.size() > 1)
	{
		int odd  = -1;
		if (ac % 2)
		{
			odd = *(_res.end() - 1);
			_res.erase(_res.end() - 1);
		}
		std::vector<int> tmp = sizedVector(_res.size());
		execute(tmp);
		if (odd != -1)
		{
			;
		}
	}
}

std::vector<int> PmergeMe::getRes() const { return _res; }

std::ostream& operator<<(std::ostream& out, const PmergeMe& pm)
{
	std::vector<int> res = pm.getRes();
	for (std::vector<int>::iterator i = res.begin(); i != res.end(); i++)
		out << *i << " ";
	return out;
}
