#include <iostream>
#include "list.h"
#include <list>

void main()
{
	////////////////////////////////////////////////////
	// CUSTOM LIST
	//
	////////////////////////////////////////////////////
	std::cout << "< MY LIST >" << std::endl;
	mylib::list<int> lst;
	lst.push_front(5);
	lst.push_front(3);
	lst.push_front(11);
	lst.push_front(4);
	lst.push_front(2);
	lst.push_back(1);

	// iterator cycle test
	std::cout << "origin	:  ";
	for (mylib::list<int>::iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}

	std::cout << std::endl;

	// sort test
	std::cout << "sort	:  ";
	lst.sort();
	for (mylib::list<int>::iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}

	std::cout << std::endl;

	// clear, pop_front, isempty test
	///lst.clear();

	if (lst.empty())
		std::cout << "is empty!" << std::endl;


	// erase,pop_back test
	lst.pop_back();
	auto iter = lst.begin();
	++iter;
	++iter;
	std::cout << "erase(1): "<< *lst.erase(iter) << std::endl;
	std::cout << "erase(3):  ";
	for (mylib::list<int>::iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}

	std::cout << std::endl << std::endl;




	////////////////////////////////////////////////////
	// STL LIST
	//
	////////////////////////////////////////////////////
	std::cout << "< STL LIST >" << std::endl;
	std::list<int> lst2;
	lst2.push_front(5);
	lst2.push_front(3);
	lst2.push_front(11);
	lst2.push_front(4);
	lst2.push_front(2);
	lst2.push_back(1);

	// iterator cycle test
	std::cout << "origin	:  ";
	for (std::list<int>::iterator iter = lst2.begin(); iter != lst2.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}

	std::cout << std::endl;

	// sort test
	std::cout << "sort	:  ";
	lst2.sort();
	for (std::list<int>::iterator iter = lst2.begin(); iter != lst2.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}

	std::cout << std::endl;

	// clear, pop_front, isempty test
	///lst2.clear();

	if (lst2.empty())
		std::cout << "is empty!" << std::endl;


	// erase,pop_back test
	lst2.pop_back();
	auto iter_test = lst2.begin();
	++iter_test;
	++iter_test;
	std::cout << "erase(1): " << *lst2.erase(iter_test) << std::endl;
	std::cout << "erase(3):  ";
	for (std::list<int>::iterator iter = lst2.begin(); iter != lst2.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}

	std::cout << std::endl << std::endl;
}