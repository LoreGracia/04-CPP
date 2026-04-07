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
	// std::cout << "Order is ";
	// for (std::vector<int>::iterator i = Iorder.begin(); i != Iorder.end(); i++)
	// 	std::cout << *i + 1 << " ";
	// std::cout << std::endl;
}

void	PmergeMe::getOrder(std::vector<int>& Iorder, std::vector< std::vector<int> >& pent, std::vector<int>& mov, int odd)
{
	Iorder.push_back(0);
	if (pent.size() > 1)
	{
		//apply mov
		std::vector< std::vector<int> > new_pent;
		std::vector<int> tmp = sizedVector(mov.size());
		// std::cout << "			PENT before new Pent" << std::endl;
		// for (std::vector< std::vector<int> >::iterator i = pent.begin(); i != pent.end(); i++)
		// 	std::cout << (*i)[0] << " ";
		// std::cout << std::endl;
		for (size_t i = 0; i < _res.size(); i++)
		{
			// std::cout << "OOOOOODD " << (odd == -1 || i < (size_t)odd) << std::endl;
			// std::cout << "[i] " << i;
			// std::cout << "		mov[i] " << mov[i];
			// std::cout << "		mov[i] + i " << mov[i] + i << std::endl;
			if (odd != -1 && i == (size_t)odd)
				i++;
			if (odd == -1 || i < (size_t)odd)
				tmp[i] = mov[i] + i;
			else if (i > (size_t)odd)
				tmp[i] = mov[i - 1] + i;
			// if (odd == -1 || i < (size_t)odd)
			// 	tmp[mov[i] + i] = i;
			// else if (i > (size_t)odd)
			// 	tmp[mov[i - 1] + i] = i;
			// std::cout << "TMP[i] = " <<  tmp[i] << std::endl;
		}
		// std::cout << "			BBBBB" << std::endl;
		for (size_t i = 0; i < pent.size(); i++){
			// std::cout << "Pent before new " << pent[i][0] << std::endl;
			// std::cout << tmp[i] << std::endl;
			new_pent.push_back(pent[tmp[i]]);}
		// std::cout << "			NewPENT" << std::endl;
		// for (std::vector< std::vector<int> >::iterator i = new_pent.begin(); i != new_pent.end(); i++)
		// 	std::cout << (*i)[0] << " ";
		// std::cout << std::endl;
		if (pent.size() > 2)
			jacobstalOrder(Iorder, new_pent);
		else
			Iorder.push_back(1);
		pent = new_pent;
		std::cout << "Sale de jacobstal" << std::endl;
	}
}

void	PmergeMe::execute(std::vector<int>& movPI, int& oddP)
{
	//Swap pairs and save swap movements
	std::vector<int> movS;
	swapPairs(movS);
	//Group big and small
	std::vector< std::vector<int> > pent;
	createPent(pent);
	//Recurivity
	int odd  = -1;
	std::vector<int> mov = sizedVector(_res.size());
	if (_res.size() > 1)
		execute(mov, odd);
	std::cout << "			vuelve" << std::endl;
	for (std::vector<int>::iterator i = mov.begin(); i != mov.end(); i++)
		std::cout << (*i) << " ";
	std::cout << std::endl;
	//INSERTION
	//order pent, double mov and get jacobstal order
	std::vector<int> Iorder;
	if (odd != -1 && pent.size() == _res.size())
	{
		std::cout << " A B A DASDFASDF " << mov.size() << " " << pent.size() << " " << _res.size() << std::endl;
		odd = -1;
	}
	getOrder(Iorder, pent, mov, odd);
	std::cout << "			HHHHHHHHHHHHHHHH" << std::endl;
	for (std::vector<int>::iterator i = mov.begin(); i != mov.end(); i++)
		std::cout << (*i) << " ";
	std::cout << std::endl;
	//binary search and save insert movements
	// std::vector<int> cp_res = _res;
	// std::vector<int>::iterator it = cp_res.begin();
	// for (size_t i = 0; i < pent.size(); i++)
	// {
	// 	it = cp_res.insert(it, pent[i][0]);
	// 	it += 2;
	// }
	std::vector<int>::iterator it;
	std::vector<int> movI = sizedVector(movS.size());
	// std::cout << "MOOOOOOOOOOOve " << mov[0] << std::endl;
	if (pent.size() == 1 && pent.size() < _res.size())
	{
		odd = 1 + mov[1];
		// mov.erase(mov.begin() + 1);
		// if (mov[0])
		// {
		// 	for (size_t i = 1; i < mov.size(); i++)
		// 		mov[i] += 1;
			// flag = 1;
		// }
	}
	for (size_t i = 0; i < Iorder.size(); i++)
	{
		// int ins_diff = 0;//Iorder[i] + (i);
		int m = 0;
		int diff = Iorder[i] - movI[Iorder[i] * 2] + i;
		// std::cout << "MOVIMEINTOS " << movI[Iorder[i] * 2] << " de _CP = " << _res[Iorder[i] * 2] << std::endl;
		it = _res.begin() + diff;
		// std::cout << "IT " << *it << std::endl;
		// std::cout << "Pent " << pent[Iorder[i]][0] << " Iorder " << Iorder[i] << " i " << i << std::endl;
		// for (std::vector< std::vector<int> >::iterator i = pent.begin(); i != pent.end(); i++)
		// 	std::cout << (*i)[0] << " ";
		// std::cout << std::endl;
		if (odd != -1 && it >= _res.begin() + odd)
		{
			std::cout << "PAAAAASO ODD " << odd << std::endl;
			it++;
			diff++;
		}
		// std::cout << "IT " << *it << std::endl;
		std::cout << "_RES befor insertion ";
		for (std::vector<int>::iterator i = _res.begin(); i != _res.end(); i++)
			std::cout << *i << " ";
		std::cout << std::endl;
		// std::cout << Iorder[i] << std::endl;
		std::cout << "diff is " << diff  << " from " << Iorder[i] << " - " << movI[Iorder[i] * 2] << " + " << i<< std::endl;
		std::cout << "\033[31minsert " << pent[Iorder[i]][0] << " pair is " << pent[Iorder[i]][1] << "\033[0m" << std::endl;
		std::cout << "pareja " << *it << std::endl;
		if (*it != pent[Iorder[i]][0])
			binarySearch(it, diff, pent[Iorder[i]][0], m);
		std::cout << "inserting before " << *it << std::endl;
		// std::cout << "CP paired original places ";
		// for (std::vector<int>::iterator i = cp_res.begin(); i != cp_res.end(); i++)
		// 	std::cout << *i << " ";
		// std::cout << std::endl;
		std::cout << "counted movements " << m << std::endl;
		_res.insert(it, pent[Iorder[i]][0]);
		movI[Iorder[i] * 2] += m;//ESTO DUPLICA CUANDO AUN NO ESTAN LAS PROXIMAS INSERCIONES?!
		// for (size_t im = 0; im + i + 1 < Iorder.size() && Iorder[im + i] > Iorder[im + i + 1]; im++)
		// 	movI[Iorder[i] * 2]++;
		std::cout << "counted movements " << movI[Iorder[i] * 2] << std::endl;
		if (Iorder[i])
		{
			int tmp = m * -1;
			for (int ij = Iorder[i]*2 - 1; tmp && ij > -1; ij--)
			{
				movI[ij]++;
				tmp--;
			}
		}
		std::cout << "			movI is now ";
		for (std::vector<int>::iterator i = movI.begin(); i != movI.end(); i++)
			std::cout << (*i) << " ";
		std::cout << std::endl;
	}
	for (std::vector<int>::iterator it = mov.begin(); it < mov.end(); it++)
	{
		// std::cout << "F WHAT  " << odd << std::endl;
		if (odd != -1 && it == mov.begin() + odd)
		{
			*it *= 2;
			// std::cout << "odd MOV IT MOV IT " << *it << std::endl;
			continue ;
		}
		*it *= 2;
		if (*it && it > mov.begin() + odd)
			*it += 1;
		it = mov.insert(it, *it);
		it++;
	}
	if (odd != -1 && mov.begin() + odd != movI.begin() + odd)
	odd -= movI[odd];
	for (size_t i = 0; i < movPI.size(); i++){
		// std::cout << movI[i] << std::endl;
		movPI[i] = mov[i] + movS[i + mov[i]] + movI[i + mov[i]];//tmp[i + mov[i]];
	}
	std::cout << "			FOR NEXT ";
	for (std::vector<int>::iterator i = movPI.begin(); i != movPI.end(); i++)
		std::cout << (*i) << " ";
	std::cout << std::endl;
	oddP = odd;
		// std::cout << std::endl;
}

void	PmergeMe::binarySearch(std::vector<int>::iterator& it, int half, int insert, int& m)
{
	std::cout << "first half " << half << std::endl;
	if (!half)
		return ;
	if (*it > insert && half != 3)
		half = (half/2);
	else if (half != 3)
		half = -(half/2);
	if (half == 3)
		half = 2;
	std::cout << " half " << half << std::endl;
	std::cout << " it " << *it << std::endl;
	it -= half;
	std::cout << " M a " << m << std::endl;
	m -= half;
	std::cout << " M b " << m << std::endl;
	std::cout << " it " << *it << std::endl;
	if (half > 0)
		binarySearch(it, half, insert, m);
	else
	{
		std::cout << " it " << *it << std::endl;
		if (*it <= insert)
		{
			it++;
			m++;
		}
		// std::cout << &(*it) << " | " << &(*(_res.end() - 1)) << std::endl;
		// std::cout << &(*it) << " | " << &(*(_res.begin())) << std::endl;
		std::cout << " it " << *it << std::endl;
		if (it != _res.begin() && *(it - 1) > insert)
		{
			it--;
			m--;
		}
		else if (it != (_res.end() - 1) && *(it + 1) < insert)
		{
			it++;
			m++;
		}
		std::cout << " it " << *it << std::endl;
	}
}

void	PmergeMe::calculate(int ac, char **av)
{
	if (parse(av))
		throw std::logic_error("invalid input");
	if (_res.size() > 1)
	{
		int odd;
		std::vector<int> tmp = sizedVector(ac);
		execute(tmp, odd);
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
