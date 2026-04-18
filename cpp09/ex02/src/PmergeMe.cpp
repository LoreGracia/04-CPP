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

void print_v_t(std::vector<size_t> v, std::string str)
{
	std::cout << str << ": ";
	for (std::vector<size_t>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
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
size_t PmergeMe::binarySearchIndex(const std::vector<int>& arr, int value, size_t end)
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
    if (input.size() <= 1)
        return input;
    // --- pairs
    std::vector< std::pair<int,int> > pairs;

    for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
        if (input[i] > input[i + 1])
            pairs.push_back(std::make_pair(input[i], input[i + 1]));
        else
            pairs.push_back(std::make_pair(input[i + 1], input[i]));
    }

	//odd number 
    int odd = 0;
    bool isOdd = input.size() % 2;
    if (isOdd)
        odd = input.back();

    // --- winners
    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);

    winners = fordJohnson(winners);

    // --- update first result
    std::vector<int> result = winners;

    // 🔑 positions of winners (index)
    std::vector<size_t> winnerPos(pairs.size());

    for (size_t i = 0; i < pairs.size(); ++i)
	{
        for (size_t j = 0; j < result.size(); ++j)
		{
            if (result[j] == pairs[i].first)
			{
                winnerPos[i] = j;
                break;
            }
        }
    }

    // --- losers
    std::vector<int> losers;
    for (size_t i = 0; i < pairs.size(); ++i)
        losers.push_back(pairs[i].second);

    std::vector<size_t> jac = jacobsthalSequence(losers.size());
    std::vector<bool> inserted(losers.size(), false);
    // insertion
    for (size_t i = 1; i < jac.size(); ++i)
	{
        size_t idx = jac[i];
		std::cout << idx << std::endl;
        if (idx >= losers.size())
            continue;

        if (!inserted[idx])
		{
            size_t pos = binarySearchIndex(result, losers[idx], winnerPos[idx]);

            result.insert(result.begin() + pos, losers[idx]);

            // update postions
            for (size_t k = 0; k < winnerPos.size(); ++k)
                if (winnerPos[k] >= pos)
                    winnerPos[k]++;

            inserted[idx] = true;
        }

        for (int j = (int)idx - 1; j >= 0; --j)
		{
            if (!inserted[j])
			{
                size_t pos = binarySearchIndex(result, losers[j], winnerPos[j]);

                result.insert(result.begin() + pos, losers[j]);

                for (size_t k = 0; k < winnerPos.size(); ++k)
                    if (winnerPos[k] >= pos)
                        winnerPos[k]++;

                inserted[j] = true;
            }
        }
    }

    // lefts out
    for (size_t i = 0; i < losers.size(); ++i)
	{
        if (!inserted[i])
		{
            size_t pos = binarySearchIndex(result, losers[i], winnerPos[i]);

            result.insert(result.begin() + pos, losers[i]);

            for (size_t k = 0; k < winnerPos.size(); ++k)
                if (winnerPos[k] >= pos)
                    winnerPos[k]++;
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

//public

void	PmergeMe::calculate(char **av)
{
	if (parse(av))
		throw std::logic_error("invalid input");
	if (_res.size() > 1)
		_res = fordJohnson(_res);
}

std::vector<int> PmergeMe::getRes() const { return _res; }

std::ostream& operator<<(std::ostream& out, const PmergeMe& pm)
{
	std::vector<int> res = pm.getRes();
	for (std::vector<int>::iterator i = res.begin(); i != res.end(); i++)
		out << *i << " ";
	return out;
}
