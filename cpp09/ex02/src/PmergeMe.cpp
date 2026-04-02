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
	if (_res.size() % 2)
			movS.push_back(0);
}

void	PmergeMe::createPent(std::vector< std::vector<int> >& pent, std::vector<int>& movI)
{
	std::vector<int> tmp;
	std::vector<int>::iterator itI = movI.begin();
	for (std::vector<int>::iterator it = _res.begin(); it != _res.end() && (it + 1) != _res.end(); it++)
	{
		tmp.push_back(*it);
		itI = movI.erase(itI);
		it = _res.erase(it);
		tmp.push_back(*it);
		pent.push_back(tmp);
		tmp.clear();
		itI++;
	}
	if (itI != movI.end())
		movI.erase(itI);
}

void	PmergeMe::jacobstalOrder(std::vector<int>& Iorder, std::vector< std::vector<int> >& new_pent)
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
			Iorder.push_back(i - 1);
	}
	std::cout << "Order is ";
	for (std::vector<int>::iterator i = Iorder.begin(); i != Iorder.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

void	PmergeMe::getOrder(std::vector<int>& Iorder, std::vector< std::vector<int> >& pent, std::vector<int> mov)
{
	Iorder.push_back(0);
	if (pent.size() > 1)
	{
		//apply mov
		std::vector< std::vector<int> > new_pent;
		std::cout << "1pasa" << std::endl;
		for (size_t i = 0; i < pent.size(); i++)
			new_pent.push_back(pent[i + mov[i]]);
		std::cout << "2pasa" << std::endl;
		if (pent.size() > 2)
			jacobstalOrder(Iorder, new_pent);
		else
			Iorder.push_back(1);
		pent = new_pent;
	}
}

void	PmergeMe::execute(std::vector<int>& movPI)
{
	//Swap pairs and save swap movements
	std::vector<int> movS;
	swapPairs(movS);
	//Group big and small
	std::vector< std::vector<int> > pent;
	std::vector<int> movI = movS;
	createPent(pent, movI);
	//Recurivity
	std::vector<int> mov = sizedVector(_res.size());
	if (_res.size() > 1)
		execute(mov);
	//INSERTION
	//order pent and get jacobstal order
	std::vector<int> Iorder;
	getOrder(Iorder, pent, mov);
	//Insert and save insert movements
	for (size_t i = 0; i < Iorder.size(); i++)
	{
		std::cout << "I " <<  i << std::endl;
		int ins_diff = 0;//Iorder[i] + (i);
		int m = 1;
		std::vector<int>::iterator it = _res.begin() + Iorder[i];
		std::vector<int>::iterator itI = movI.begin() + Iorder[i];
		while (it != _res.end() && *it != pent[Iorder[i]][1])
		{
			it++;
			itI++;
			ins_diff++;
		}
		for (std::vector<int>::iterator i = _res.begin(); i != _res.end(); i++)
			std::cout << *i << " ";
		std::cout << std::endl;
		std::cout << "insert " << pent[Iorder[i]][0] << std::endl;
		binarySearch(it, itI, (Iorder[i] + ins_diff)/2, pent[Iorder[i]][0], m);
		_res.insert(it, pent[Iorder[i]][0]);
		// for (size_t i = 0; (itI + i) != movI.end(); i++)
		// 	(*(itI + i))--;
		// movI.insert(itI, m);
	}
	//add swap and insert movements for previus recursion
	// for (size_t i = 0; i < movPI.size(); i++)
	// 	std::cout << "Current movPI " << movPI[i] << std::endl;
	// for (size_t i = 0; i < movS.size(); i++)
	// 	movPI.push_back(movI[movS[i]] + movS[i]);
	movPI = movS;
}

void	PmergeMe::binarySearch(std::vector<int>::iterator& it, std::vector<int>::iterator& itI, size_t half, int insert, int& m)
{
	std::cout << "Binary in " << *it << " | ";
	it -= half;
	itI -= half;
	m -= half;
	if (*it > insert)
		half = (half/2);
	else
		half = -(half/2);
	if (half > 0)
		binarySearch(it, itI, half, insert, m);
	else
	{
		std::cout << "Binary mid a " << *it << " | ";
		if (*it < insert)
			it++;
		if (it != _res.begin() && *(it - 1) > insert)
			it--;
		else if (it != (_res.end() - 1) && *(it + 1) < insert)
			it++;
		std::cout << "Binary mid b " << *it << " | ";
	}
	std::cout << "Binary out " << *it << std::endl;
}

void	PmergeMe::calculate(int ac, char **av)
{
	if (parse(av))
		throw std::logic_error("invalid input");
	if (_res.size() > 1)
	{
		std::vector<int> tmp = sizedVector(ac);
		execute(tmp);
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
