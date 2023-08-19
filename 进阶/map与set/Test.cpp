#include <iostream>
#include <set>
#include <map>
//#include <string>
using namespace std;

// set -- key
// map -- key/value

void test1()
{
	set<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(2);
	s1.insert(4);
	s1.insert(3);
	s1.insert(5);

	/*set<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;*/

	multiset<int> s2;
	s2.insert(3);
	s2.insert(1);
	s2.insert(2);
	s2.insert(4);
	s2.insert(3);
	s2.insert(5);


	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;

	//int x;
	//while (cin >> x)
	//{
	//	if (s1.count(x))
	//	{
	//		cout << "ÔÚ" << endl;
	//	}
	//	else
	//	{
	//		cout << "²»ÔÚ" << endl;
	//	}
	//}

	cout << s2.count(3) << endl;
}

void test2()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("left", "×ó±ß"));
	dict.insert(pair<string, string>("right", "ÓÒ±ß"));
	dict.insert(make_pair("sort", "ÅÅĞò"));
	dict.insert(make_pair("string", "×Ö·û´®"));
	dict.insert(make_pair("count", "¼ÆÊı"));
	dict.insert(make_pair("count", "Êı×Ö"));

	
	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
}

void test3()
{
	string arr[] = { "Î÷¹Ï", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Ïã½¶", "Àæ" };

	map<string, int> countMap;
	for (auto& e : arr)
	{
		auto ret = countMap.find(e);
		if (ret == countMap.end())
		{
			countMap.insert(make_pair(e, 1));
		}
		else
		{
			ret->second++;
		}
	}

	for (auto e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void test4()
{
	string arr[] = { "Î÷¹Ï", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Ïã½¶", "Àæ" };

	map<string, int> countMap;
	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void test5()
{
	multimap<string, string> dict;
	dict.insert(pair<string, string>("left", "×ó±ß"));
	dict.insert(pair<string, string>("right", "ÓÒ±ß"));
	dict.insert(make_pair("sort", "ÅÅĞò"));
	dict.insert(make_pair("string", "×Ö·û´®"));
	dict.insert(make_pair("count", "¼ÆÊı"));
	dict.insert(make_pair("count", "Êı×Ö"));


	multimap<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
}

int main()
{
	test2();
}