#include "PmergeMe.hpp"

//VECTOR version
// debug utils

void print_vd(TYPE_V v, std::string str)
{
	std::cout << str << ":	";
	for (size_t i = 0; i < v.size(); i++)
	{
		if (!(v[0].big))
			continue ;
		Node_V d = (*(v[i].big));
		if (!d.litt)
			std::cout << "N";
		else
			std::cout << (*(d.litt)).head << "<";
		std::cout << (d.head) << " ";
	}
	std::cout << std::endl;
}

void print_v(TYPE_V v, std::string str)
{
	std::cout << str << ":	";
	for (size_t i = 0; i < v.size(); i++)
	{
		if (!v[i].litt)
			std::cout << "N";
		else
			std::cout << (*(v[i].litt)).head << "<";
		std::cout << (v[i].head) << " ";
	}
	std::cout << std::endl;
}

//Node_V chanonical

Node_V::Node_V() {}
Node_V::Node_V(Node_V* l, size_t h, Node_V* b) : litt(l), head(h), big(b) {}
Node_V::Node_V(const Node_V& other) { *this = other; }
Node_V& Node_V::operator=(const Node_V& other)
{
	head = other.head;
	big = other.big;
	litt = other.litt;
	return *this;
}
Node_V::~Node_V() {}

//PmergeMeV chanonical

PmergeMeV::PmergeMeV() {}
PmergeMeV::PmergeMeV(const PmergeMeV &other) { *this = other; }
PmergeMeV &PmergeMeV::operator=(const PmergeMeV &other)
{
	_parsed = other._parsed;
	_original = other._original;
	_result = other._result;
	return *this;
}
PmergeMeV::~PmergeMeV() {}

int PmergeMeV::parse(char **av)
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
	for (size_t i = 0; i < _parsed.size(); i++)
	{
		_original.push_back(Node_V(0, _parsed[i], 0));
	}
	return 0;
}

std::vector<size_t> PmergeMeV::jacobsthal(size_t n)
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

void	PmergeMeV::jacobstalOrder(std::vector < std::vector<size_t> >& Iorder, size_t size)
{
	size_t a = log2((3 * size) + 1);
	size_t jacob = (pow(2, a) - (pow(-1, a))) / 3;
	std::vector<size_t> jb_sq;
	jb_sq.push_back(1);
	std::vector<size_t> tmp;
	tmp.push_back(0);
	Iorder.push_back(tmp);
	for (size_t i = 1; jb_sq.back() != jacob; i++)
		jb_sq.push_back((2 * jb_sq[i - 1]) + pow(-1, i));
	for (size_t i = 2; i < jb_sq.size(); i++)
	{
		tmp.clear();
		tmp.push_back(jb_sq[i] - 1);
		Iorder.push_back(tmp);
	}
	for (size_t i = 1; i < Iorder.size(); i++)
	{
		size_t top = Iorder[i - 1][0];
		for (size_t temp = Iorder[i][0] - 1; temp > top; temp--)
			Iorder[i].push_back(temp);
	}
	tmp.clear();
	if (Iorder.back()[0] < size)
	{
		for (size_t i = Iorder.back()[0] + 1; i != size; i++)
		{
			tmp.push_back(i);
			Iorder.push_back(tmp);
			tmp.clear();
		}
	}
}

size_t PmergeMeV::bynarysearch(size_t i, TYPE_V ret, size_t n)
{
	int left = 0;
	int right = i;
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (ret[mid].head <= n)
			left = mid + 1;
		else
			right = mid;
		compv++;
	}
	return left;
}

TYPE_V* PmergeMeV::fordJhonson(TYPE_V& original)
{
	TYPE_V *main_p = new TYPE_V(original);
	Node_V* odd = NULL;
	if ((*main_p).size() % 2)
	{
		odd = new Node_V(original.back());
		(*main_p).erase((*main_p).end() - 1);
	}
	size_t size = (original.size() - (odd != NULL))/2;
	for (size_t i = 0; i < size; i++)
	{
		compv++;
		if (((*main_p)[i].head) > ((*main_p)[i + 1].head))
		{
			(*main_p)[i].litt = (&original[i * 2 + 1]);
			(*main_p).erase((*main_p).begin() + i + 1);
		}
		else
		{
			(*main_p)[i + 1].litt = (&original[i * 2]);
			(*main_p).erase((*main_p).begin() + i);
		}
	}
	TYPE_V *ret_p;
	if ((*main_p).size() > 1)
	{
		TYPE_V *recursion = new TYPE_V;
		for (size_t i = 0; i < (*main_p).size(); i++)
			(*recursion).push_back(Node_V(0, (*main_p)[i].head, (&(*main_p)[i])));
		ret_p = fordJhonson(*recursion);
		delete recursion;
	}
	else
		ret_p = new TYPE_V((*main_p));
	delete main_p;
	std::vector < std::vector<size_t> > Iorder;
	jacobstalOrder(Iorder, (*ret_p).size());
	size_t iLitt = 0;
	for (size_t i = 0; i < Iorder.size(); iLitt++)
	{
		if (((*ret_p)[Iorder[i][iLitt]]).litt)
		{
			size_t it = bynarysearch(Iorder[i][iLitt], *ret_p, (*((*ret_p)[Iorder[i][iLitt]].litt)).head);
			(*ret_p).insert((*ret_p).begin() + it, *((*ret_p)[Iorder[i][iLitt]].litt));
			if (((*ret_p)[it]).big)
				(*ret_p)[it] = *((*ret_p)[it].big);
			size_t limit = Iorder[i][iLitt] - it + 1 + iLitt;
			for (size_t j = iLitt; j < limit && j < Iorder[i].size(); j++){
				Iorder[i][j]++;
				if (j + 1 < Iorder[i].size())
					limit -= (Iorder[i][j] - 2) - Iorder[i][j + 1];
			}
			for (size_t j = i + 1; j < Iorder.size(); j++)
			{
				for (size_t jLitt = 0; jLitt < Iorder[j].size(); jLitt++)
					Iorder[j][jLitt]++;
			}
		}
		if ((*ret_p)[Iorder[i][iLitt]].big)
			(*ret_p)[Iorder[i][iLitt]] = *(Node_V*)((*ret_p)[Iorder[i][iLitt]].big);
		else
			(*ret_p)[Iorder[i][iLitt]].litt = 0;
		if (iLitt == Iorder[i].size() - 1)
		{
			i++;
			iLitt = -1;
		}
	}
	if (odd)
	{
		size_t it = bynarysearch((*ret_p).size(), *ret_p, (*odd).head);
		if ((*odd).big)
			(*ret_p).insert((*ret_p).begin() + it, *((*odd).big));
		else
			(*ret_p).insert((*ret_p).begin() + it, (*odd));
		}
		delete odd;
	return ret_p;
}

// public

void PmergeMeV::calculate(char **av)
{
	if (parse(av))
		throw std::logic_error("invalid input");
	TYPE_V* result = new TYPE_V(_original);
	if (_original.size() > 1)
		result = fordJhonson(_original);
	for (size_t i = 0; i < (*result).size(); i++)
		_result.push_back((*result)[i].head);
	delete result;
}

std::vector<size_t> PmergeMeV::getRes() const { return _result; }

std::ostream &operator<<(std::ostream &out, const PmergeMeV &pm)
{
	std::vector<size_t> res = pm.getRes();
	for (size_t i = 0; i < res.size(); i++)
		out << res[i] << " ";
	return out;
}
//DEQUE version
// debug utils

void print_vdD(TYPE_D v, std::string str)
{
	std::cout << str << ":	";
	for (size_t i = 0; i < v.size(); i++)
	{
		if (!(v[0].big))
			continue ;
		Node_D d = (*(v[i].big));
		if (!d.litt)
			std::cout << "N";
		else
			std::cout << (*(d.litt)).head << "<";
		std::cout << (d.head) << " ";
	}
	std::cout << std::endl;
}

void print_vD(TYPE_D v, std::string str)
{
	std::cout << str << ":	";
	for (size_t i = 0; i < v.size(); i++)
	{
		if (!v[i].litt)
			std::cout << "N";
		else
			std::cout << (*(v[i].litt)).head << "<";
		std::cout << (v[i].head) << " ";
	}
	std::cout << std::endl;
}

//Node_D chanonical

Node_D::Node_D() {}
Node_D::Node_D(Node_D* l, size_t h, Node_D* b) : litt(l), head(h), big(b) {}
Node_D::Node_D(const Node_D& other) { *this = other; }
Node_D& Node_D::operator=(const Node_D& other)
{
	head = other.head;
	big = other.big;
	litt = other.litt;
	return *this;
}
Node_D::~Node_D() {}

//PmergeMeD chanonical

PmergeMeD::PmergeMeD() {}
PmergeMeD::PmergeMeD(const PmergeMeD &other) { *this = other; }
PmergeMeD &PmergeMeD::operator=(const PmergeMeD &other)
{
	_parsed = other._parsed;
	_original = other._original;
	_result = other._result;
	return *this;
}
PmergeMeD::~PmergeMeD() {}

int PmergeMeD::parse(char **av)
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
	for (size_t i = 0; i < _parsed.size(); i++)
		_original.push_back(Node_D(0, _parsed[i], 0));
	return 0;
}

std::deque<size_t> PmergeMeD::jacobsthal(size_t n)
{
    std::deque<size_t> j;
    j.push_back(0);
    j.push_back(1);

    while (j.back() < n)
    {
        size_t sz = j.size();
        j.push_back(j[sz - 1] + 2 * j[sz - 2]);
    }
    return j;
}

void	PmergeMeD::jacobstalOrder(std::deque < std::deque<size_t> >& Iorder, size_t size)
{
	size_t a = log2((3 * size) + 1);
	size_t jacob = (pow(2, a) - (pow(-1, a))) / 3;
	std::deque<size_t> jb_sq;
	jb_sq.push_back(1);
	std::deque<size_t> tmp;
	tmp.push_back(0);
	Iorder.push_back(tmp);
	for (size_t i = 1; jb_sq.back() != jacob; i++)
		jb_sq.push_back((2 * jb_sq[i - 1]) + pow(-1, i));
	for (size_t i = 2; i < jb_sq.size(); i++)
	{
		tmp.clear();
		tmp.push_back(jb_sq[i] - 1);
		Iorder.push_back(tmp);
	}
	for (size_t i = 1; i < Iorder.size(); i++)
	{
		size_t top = Iorder[i - 1][0];
		for (size_t temp = Iorder[i][0] - 1; temp > top; temp--)
			Iorder[i].push_back(temp);
	}
	tmp.clear();
	if (Iorder.back()[0] < size)
	{
		for (size_t i = Iorder.back()[0] + 1; i != size; i++)
		{
			tmp.push_back(i);
			Iorder.push_back(tmp);
			tmp.clear();
		}
	}
}

size_t PmergeMeD::bynarysearch(size_t i, TYPE_D ret, size_t n)
{
	int left = 0;
	int right = i;
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (ret[mid].head <= n)
			left = mid + 1;
		else
			right = mid;
		compd++;
	}
	return left;
}

TYPE_D* PmergeMeD::fordJhonson(TYPE_D& original)
{
	TYPE_D *main_p = new TYPE_D(original);
	Node_D* odd = NULL;
	if ((*main_p).size() % 2)
	{
		odd = new Node_D(original.back());
		(*main_p).erase((*main_p).end() - 1);
	}
	size_t size = (original.size() - (odd != NULL))/2;
	for (size_t i = 0; i < size; i++)
	{
		compd++;
		if (((*main_p)[i].head) > ((*main_p)[i + 1].head))
		{
			(*main_p)[i].litt = (&original[i * 2 + 1]);
			(*main_p).erase((*main_p).begin() + i + 1);
		}
		else
		{
			(*main_p)[i + 1].litt = (&original[i * 2]);
			(*main_p).erase((*main_p).begin() + i);
		}
	}
	TYPE_D *ret_p;
	if ((*main_p).size() > 1)
	{
		TYPE_D *recursion = new TYPE_D;
		for (size_t i = 0; i < (*main_p).size(); i++)
			(*recursion).push_back(Node_D(0, (*main_p)[i].head, (&(*main_p)[i])));
		ret_p = fordJhonson(*recursion);
		delete recursion;
	}
	else
		ret_p = new TYPE_D((*main_p));
	delete main_p;
	std::deque < std::deque<size_t> > Iorder;
	jacobstalOrder(Iorder, (*ret_p).size());
	size_t iLitt = 0;
	for (size_t i = 0; i < Iorder.size(); iLitt++)
	{
		if (((*ret_p)[Iorder[i][iLitt]]).litt)
		{
			size_t it = bynarysearch(Iorder[i][iLitt], *ret_p, (*((*ret_p)[Iorder[i][iLitt]].litt)).head);
			(*ret_p).insert((*ret_p).begin() + it, *((*ret_p)[Iorder[i][iLitt]].litt));
			if (((*ret_p)[it]).big)
				(*ret_p)[it] = *((*ret_p)[it].big);
			size_t limit = Iorder[i][iLitt] - it + 1 + iLitt;
			for (size_t j = iLitt; j < limit && j < Iorder[i].size(); j++){
				Iorder[i][j]++;
				if (j + 1 < Iorder[i].size())
					limit -= (Iorder[i][j] - 2) - Iorder[i][j + 1];
			}
			for (size_t j = i + 1; j < Iorder.size(); j++)
			{
				for (size_t jLitt = 0; jLitt < Iorder[j].size(); jLitt++)
					Iorder[j][jLitt]++;
			}
		}
		if ((*ret_p)[Iorder[i][iLitt]].big)
			(*ret_p)[Iorder[i][iLitt]] = *(Node_D*)((*ret_p)[Iorder[i][iLitt]].big);
		else
			(*ret_p)[Iorder[i][iLitt]].litt = 0;
		if (iLitt == Iorder[i].size() - 1)
		{
			i++;
			iLitt = -1;
		}
	}
	if (odd)
	{
		size_t it = bynarysearch((*ret_p).size(), *ret_p, (*odd).head);
		if ((*odd).big)
			(*ret_p).insert((*ret_p).begin() + it, *((*odd).big));
		else
			(*ret_p).insert((*ret_p).begin() + it, (*odd));
		}
		delete odd;
	return ret_p;
}

// public

void PmergeMeD::calculate(char **av)
{
	if (parse(av))
		throw std::logic_error("invalid input");
	TYPE_D* result = new TYPE_D(_original);
	if (_original.size() > 1)
		result = fordJhonson(_original);
	for (size_t i = 0; i < (*result).size(); i++)
		_result.push_back((*result)[i].head);
	delete result;
}

std::deque<size_t> PmergeMeD::getRes() const { return _result; }

std::ostream &operator<<(std::ostream &out, const PmergeMeD &pm)
{
	std::deque<size_t> res = pm.getRes();
	for (size_t i = 0; i < res.size(); i++)
		out << res[i] << " ";
	return out;
}
