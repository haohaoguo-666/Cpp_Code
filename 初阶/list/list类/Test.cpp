#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
using namespace std;

void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}

	cout << endl;

	
	list<int>::iterator pos = find(lt.begin(), lt.end(), 3);
	if (pos != lt.end())
	{
		lt.insert(pos, 30);
	}

	for (auto e : lt)
	{
		cout << e << " ";
	}

	cout << endl;
	
}


int main()
{
	test_list1();
	return 0;
}