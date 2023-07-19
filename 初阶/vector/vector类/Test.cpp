#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

void test_vector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto ch : v)
	{
		cout << ch << " ";
	}
	cout << endl;


	vector<int> copy_v(v);
	for (auto ch : copy_v)
	{
		cout << ch << " ";
	}
	cout << endl;
}

void test_vector2()
{
	vector<int> v1(10, 1);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v2(v1.begin(), v1.end());
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	string s1("hello world");
	vector<int> s2(s1.begin(), s1.end());
	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_vector3()
{
	vector<int> v;
	//vector<int> ::reverse_iterator rit = v.rbegin();
	auto rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void test_vector4()
{
	vector<char> v;
	cout << v.max_size() << endl;
}

void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

// 如果已经确定vector中要存储元素大概个数，可以提前将空间设置足够
// 就可以避免边插入边扩容导致效率低下的问题了
void TestVectorExpandOP()
{
	vector<int> v;
	size_t sz = v.capacity();
	v.reserve(100); // 提前将容量设置好，可以避免一遍插入一遍扩容
	cout << "making bar grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_vector5()
{
	vector<int> v;
	v.resize(10, 0);

	vector<int> v2(10, 0);
}

void test_vector6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	if (pos != v.end())
	{
		v.insert(pos, 20);
	}

	for (auto ch : v)
	{
		cout << ch << " ";
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 3);

	v.erase(pos);

	for (auto ch : v)
	{
		cout << ch << " ";
	}
	cout << endl;
}

void test_vector7()
{
	vector<int>array;

	array.push_back(100);

	array.push_back(300);

	array.push_back(300);

	array.push_back(300);

	array.push_back(300);

	array.push_back(500);

	vector<int>::iterator itor;

	for (itor = array.begin(); itor != array.end(); itor++)

	{

		if (*itor == 300)

		{

			itor = array.erase(itor);

		}

	}

	for (itor = array.begin(); itor != array.end(); itor++)

	{

		cout << *itor << " ";

	}

}

//int main()
//{
//	test_vector7();
//	return 0;
//} 
