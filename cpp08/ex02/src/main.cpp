#include "MutantStack.hpp"
#include <list>
#include <vector>

int main()
{
	{
		std::cout << "\033[30m	My tests\033[0m" << std::endl;
		std::cout << "\033[30m		Const_iterator\033[0m" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();
		std::cout << "iteartor  at begin is = " << *it << std::endl;
		std::cout << "top is = " << mstack.top() << std::endl;
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::cout << "\033[30m		Iterator modification\033[0m" << std::endl;
		MutantStack<int> s(mstack);
		MutantStack<int>::iterator i = s.begin();
		std::cout << *i << std::endl;
		*i = 42;
		std::cout << *i << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "\033[30m	Default\033[0m" << std::endl;
		std::cout << "\033[30m		MutantStack\033[0m" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}
	{
		std::cout << "\033[30m		Vector\033[0m" << std::endl;
		std::vector<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::vector<int> s(mstack);
	}
	{
		std::cout << "\033[30m		List\033[0m" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::list<int> s(mstack);
	}
	return 0;
}
