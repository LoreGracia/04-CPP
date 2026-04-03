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

void	PmergeMe::jacobstalOrder(std::vector<int>& Iorder, std::vector< std::vector<int> >& new_pent)
{
	int a = log2((3 * new_pent.size()) + 1);
	size_t jacob = (pow(2, a) - (pow(-1, a))) / 3;
	std::vector<int> jb_sq;
	jb_sq.push_back(1);
	for (size_t i = 1; jb_sq.back() != (int)jacob; i++)
	{
		jb_sq.push_back((2 * jb_sq[i - 1]) + pow(-1, i));
	}
	Iorder[0] = 0;
	size_t top = 1;
	for (size_t i = 1; i < jb_sq.size(); i++)
	{
		for (size_t tmp = jb_sq[i]; tmp > top; tmp--){
			Iorder.push_back(tmp - 1);}
		top = jb_sq[i];
	}
	if (Iorder.size() != new_pent.size())
	{
		for (size_t i = jb_sq.back(); Iorder.size() != new_pent.size(); i++){
			Iorder.push_back(i);
		}
	}
	std::cout << "Order is ";
	for (std::vector<int>::iterator i = Iorder.begin(); i != Iorder.end(); i++)
		std::cout << *i + 1 << " ";
	std::cout << std::endl;
}

void	PmergeMe::getOrder(std::vector<int>& Iorder, std::vector< std::vector<int> >& pent, std::vector<int> mov)
{
	Iorder.push_back(0);
	if (pent.size() > 1)
	{
		//apply mov
		std::vector< std::vector<int> > new_pent;
		for (size_t i = 0; i < pent.size(); i++)
			new_pent.push_back(pent[i + mov[i]]);
		if (pent.size() > 2)
			jacobstalOrder(Iorder, new_pent);
		else
			Iorder.push_back(1);
		pent = new_pent;
		std::cout << "Sale de jacobstal" << std::endl;
	}
}

void	PmergeMe::execute(std::vector<int>& movPI)
{
	//Swap pairs and save swap movements
	std::vector<int> movS;
	swapPairs(movS);
	//Group big and small
	std::vector< std::vector<int> > pent;
	createPent(pent);
	//Recurivity
	std::vector<int> mov = sizedVector(_res.size());
	if (_res.size() > 1)
		execute(mov);
	std::cout << "vuelve" << std::endl;
	//INSERTION
	//order pent and get jacobstal order
	std::vector<int> Iorder;
	getOrder(Iorder, pent, mov);
	//binary search and save insert movements
	std::vector<int> cp_res = _res;
	std::vector<int>::iterator it = cp_res.begin();
	for (size_t i = 0; i < pent.size(); i++)
	{
		it = cp_res.insert(it, pent[i][0]);
		it += 2;
	}
	std::vector<int> movI = sizedVector(movS.size());
	for (size_t i = 0; i < Iorder.size(); i++)
	{
		int ins_diff = 0;//Iorder[i] + (i);
		int m = 1;
		std::cout << "MOVIMEINTOS " << movI[Iorder[i] + i*2] << std::endl;
		it = _res.begin() + Iorder[i] - movI[Iorder[i] + i*2];
		// std::cout << Iorder.size() << " | " << pent.size() << std::endl;
		// while (it != _res.end() - 1 && *it != pent[Iorder[i]][1])
		// {
		// 	it++;
		// 	ins_diff++;
		// }
		for (std::vector<int>::iterator i = _res.begin(); i != _res.end(); i++)
			std::cout << *i << " ";
		std::cout << std::endl;
		// std::cout << Iorder[i] << std::endl;
		std::cout << "insert " << pent[Iorder[i]][0] << " pair is " << pent[Iorder[i]][1] << std::endl;
		if (*it != pent[Iorder[i]][0])
			binarySearch(it, (Iorder[i] + 1 + ins_diff)/2, pent[Iorder[i]][0], m);
		std::cout << "inserting before " << *it << std::endl;
		std::cout << "CP paired original places" << std::endl;
		for (std::vector<int>::iterator i = cp_res.begin(); i != cp_res.end(); i++)
			std::cout << *i << " ";
		std::cout << std::endl;
		std::cout << "counted movements " << m - 1 << std::endl;
		_res.insert(it, pent[Iorder[i]][0]);
		for (size_t ij = i*2 - 1; i*2 && ij > -1; ij--)
			movI[ij]--;
		movI[i*2] += m - 1;
	}
	//add swap and insert movements for previus recursion
	// for (size_t i = 0; i < movPI.size(); i++)
	// 	std::cout << "Current movPI " << movPI[i] << std::endl;
	// for (size_t i = 0; i < movS.size(); i++)
	// 	movPI.push_back(movI[movS[i]] + movS[i]);
	for (size_t i = 0; i < movPI.size(); i++)
		movPI[i] = movS[i] + movI[i];
}

void	PmergeMe::binarySearch(std::vector<int>::iterator& it, int half, int insert, int& m)
{
	it -= half;
	m -= half;
	if (*it >= insert)
		half = (half/2);
	else
		half = -(half/2);
	if (half > 0)
		binarySearch(it, half, insert, m);
	else
	{
		if (*it < insert)
			it++;
		// std::cout << &(*it) << " | " << &(*(_res.end() - 1)) << std::endl;
		// std::cout << &(*it) << " | " << &(*(_res.begin())) << std::endl;
		if (it != _res.begin() && *(it - 1) > insert)
			it--;
		else if (it != (_res.end() - 1) && *(it + 1) < insert)
			it++;
		while (*it == insert && it != (_res.end() - 1))
		{
			it++;
			m++;
		}
	}
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
