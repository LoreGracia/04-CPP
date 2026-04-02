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

void	binarySearch(std::vector<int>::iterator& it, std::vector<int>::iterator& itI, size_t half, int insert, int& m)
{
	it -= half;
	itI -= half;
	std::cout << "it = " << *it << std::endl;
	// std::cout << "m-= half " << m << " " << half << std::endl;
	m -= half;
	// std::cout << "m = " << m << std::endl;
	std::cout << "half = " << half << std::endl;
	if (!half)
	{
		binarySearch(it, itI, half, insert, m);//AAAAAAAAAAAAAAAAAA
		return;
	}
	if (*it > insert)
		half = (half/2);
	else
		half = -(half/2);
	// if (!half && *it < insert)
	// {
	// 	it++;
	// 	itI++;
	// }
	std::cout << "half = " << half << std::endl;
	if (half/2 > 0)
		binarySearch(it, itI, half, insert, m);
}

void	PmergeMe::swapPairs(std::vector<int>& movS)
{
	for (size_t i = 0; i < _res.size() && _res[i + 1]; i += 2)
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
		for (size_t i = 0; i < mov.size(); i++){
			new_pent.push_back(pent[i + mov[i]]);
		}
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
	std::vector<int> Iorder;
	getOrder(Iorder, pent, mov);
	//Insert and save insert movements
	size_t j = 1;
	for (size_t i = 0; i < Iorder.size(); i++)
	{
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
		// o += movI[Iorder[i]];
		std::cout << "init " << pent[Iorder[i]][1] << " " << *it  << " | " << pent[Iorder[i]][0] << std::endl;
		for (std::vector<int>::iterator i = _res.begin(); i != _res.end(); i++)
			std::cout << *i << " ";
		std::cout << std::endl;
		binarySearch(it, itI, (Iorder[i] + ins_diff)/2, pent[Iorder[i]][0], m);
		std::cout << "ins_diff " << ins_diff << std::endl;
		// std::cout << "o+m " << o + m << std::endl;
		std::cout << "m " << m << std::endl;
		_res.insert(it, pent[Iorder[i]][0]);
		for (size_t i = 0; (itI + i) != movI.end(); i++)
			(*(itI + i))--;
		// movS[j] + (ins_diff + m)// m esta mal
		//
		movI.insert(itI, m);
		j += 2;
	}
	//add swap and insert movements for previus recursion
	// for (size_t i = 0; i < movS.size(); i++)
	// 	std::cout << "Current movS " << movS[i] << std::endl;
	// for (size_t i = 0; i < movS.size(); i++)
	// 	movPI.push_back(movI[movS[i]] + movS[i]);
	// j = 1; movS[j]; j += 2
	// for (size_t i = 0; i < mov.size(); i++)
	// 	std::cout << "Current mov " << mov[i] << std::endl;
	movPI = movS;
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
