#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;


void test_unordered_set1()
{
	unordered_set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(7);
	s.insert(2);

	unordered_set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_unordered_map1()
{
	string arr[] = { "Î÷¹Ï", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Ïã½¶", "Àæ" };

	unordered_map<string, int> countMap;
	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

//int main()
//{
//	//test_unordered_set1();
//	//cout << endl;
//	//test_unordered_map1();
//	return 0;
//}

#include "UnorderedMap.hpp"
#include "UnorderedSet.hpp"

//int main()
//{
//	TestHashTable1();
//	return 0;
//}

int main()
{
	yyf::test_unordered_set2();
	//yyf::test_unordered_map3();
	return 0;
}