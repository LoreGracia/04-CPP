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

// ---------------- Jacobsthal ----------------
std::vector<size_t> PmergeMe::jacobsthalSequence(size_t n)
{
	std::vector<size_t> j;
	j.push_back(0);
	if (n == 0)
		return j;

	j.push_back(1);
	while (j.back() < n)
	{
		size_t s = j.size();
		j.push_back(j[s - 1] + 2 * j[s - 2]);
	}
	return j;
}

// ---------------- Binary insert con índice límite ----------------
size_t PmergeMe::binarySearchIndex(const std::vector<int> &arr, int value, size_t end)
{
	size_t left = 0;
	size_t right = end;

	while (left < right)
	{
		size_t mid = (left + right) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

// ---------------- Ford-Johnson ----------------
std::vector<int> PmergeMe::fordJohnson(std::vector<int> input)
{
	// if (input.size() <= 1)
	// 	return input;
	// --- pairs
	std::vector< std::pair<int, int> > pairs;

	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		if (input[i] > input[i + 1])
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
		else
			pairs.push_back(std::make_pair(input[i + 1], input[i]));
	}

	// odd number
	int odd = 0;
	bool isOdd = input.size() % 2;
	if (isOdd)
		odd = input.back();

	// --- main
	std::vector<int> main;
	for (size_t i = 0; i < pairs.size(); ++i)
		main.push_back(pairs[i].first);

	if (input.size() > 1)
		main = fordJohnson(main);
	std::cout << std::endl << "OUT" << std::endl;
	// --- update first result
	std::vector<int> result = main;

	// 🔑 positions of main (index)
	std::vector<size_t> mainPos(pairs.size());

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		for (size_t j = 0; j < result.size(); ++j)
		{
			if (result[j] == pairs[i].first)
			{
				mainPos[i] = j;
				break;
			}
		}
	}

	// --- pent
	std::vector<int> pent;
	for (size_t i = 0; i < pairs.size(); ++i)
		pent.push_back(pairs[i].second);

	std::vector<size_t> jac = jacobsthalSequence(pent.size());
	std::vector<bool> inserted(pent.size(), false);
	// insertion
	for (size_t i = 1; i < jac.size(); ++i)
	{
		std::cout << "		ROUND " << i;
		print_v(result, "");
		size_t idx = jac[i];
		if (idx >= pent.size())
			break ;
		std::cout << "Index " << idx << std::endl;
		if (!inserted[idx])
		{
			std::cout << "primero";
			size_t pos = binarySearchIndex(result, pent[idx], mainPos[idx]);

			result.insert(result.begin() + pos, pent[idx]);

			// update postions
			for (size_t k = pos; k < mainPos.size(); ++k)
					mainPos[k]++;

			inserted[idx] = true;
			print_v(result, " ");
		}
		std::cout << "Index " << idx << std::endl;

		for (int j = (int)idx - 1; j >= 0; --j)
		{
			std::cout << "segundo ";
			if (!inserted[j])
			{
				std::cout << "yes ";
				size_t pos = binarySearchIndex(result, pent[j], mainPos[j]);

				result.insert(result.begin() + pos, pent[j]);

				for (size_t k = pos; k < mainPos.size(); ++k)
						mainPos[k]++;

				inserted[j] = true;
				print_v(result, "");
			}
			 std::cout << std::endl;
		}
		print_v(result, "		Round current");
	}

	// lefts out
	for (size_t i = 0; i < pent.size(); ++i)
	{
		if (!inserted[i])
		{
			size_t pos = binarySearchIndex(result, pent[i], mainPos[i]);

			result.insert(result.begin() + pos, pent[i]);

			for (size_t k = pos; k < mainPos.size(); ++k)
					mainPos[k]++;
		}
	}

	// odd
	if (isOdd)
	{
		size_t pos = binarySearchIndex(result, odd, result.size());
		result.insert(result.begin() + pos, odd);
	}

	return result;
}

// public

void PmergeMe::calculate(char **av)
{
	if (parse(av))
		throw std::logic_error("invalid input");
	if (_res.size() > 1)
		_res = fordJohnson(_res);
}

std::vector<int> PmergeMe::getRes() const { return _res; }

std::ostream &operator<<(std::ostream &out, const PmergeMe &pm)
{
	std::vector<int> res = pm.getRes();
	for (std::vector<int>::iterator i = res.begin(); i != res.end(); i++)
		out << *i << " ";
	return out;
}
