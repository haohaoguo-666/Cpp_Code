//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <list>
//#include <map>
//#include <assert.h>
//#include <algorithm>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <functional>
//
//using namespace std;
//
//int Func(int a, int b)
//{
//	return a + b;
//}
//
//struct Functor
//{
//public:
//	int operator()(int a, int b)
//	{
//		return a + b;
//	}
//
//};
//
//int main()
//{
//	function<int(int, int)> f1 = Func;
//	function<int(int, int)> f2 = Functor();
//	function<int(int, int)> f3 = [](int a, int b) {
//		return a + b; 
//	};
//	cout << f1(1, 2) << endl;
//	cout << f2(1, 2) << endl;
//
//
//	map<string, function<int(int, int)>> opFuncMap;
//
//	opFuncMap["º¯ÊýÖ¸Õë"] = Func;
//	opFuncMap["·Âº¯Êý"] = Functor();
//	opFuncMap["lambda"] = [](int a, int b) {
//		return a + b;
//	};
//
//}