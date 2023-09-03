//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <list>
//#include <map>
//#include <assert.h>
//#include <algorithm>
//
//
//using namespace std;
//
//
//struct Goods
//{
//	string _name;  //名字
//	double _price; //价格
//	int _num;      //数量
//};
//
////struct ComparePriceLess
////{
////	bool operator()(const Goods& g1, const Goods& g2)
////	{
////		return g1._price < g2._price;
////	}
////};
////struct ComparePriceGreater
////{
////	bool operator()(const Goods& g1, const Goods& g2)
////	{
////		return g1._price > g2._price;
////	}
////};
////struct CompareNumLess
////{
////	bool operator()(const Goods& g1, const Goods& g2)
////	{
////		return g1._num < g2._num;
////	}
////};
////struct CompareNumGreater
////{
////	bool operator()(const Goods& g1, const Goods& g2)
////	{
////		return g1._num > g2._num;
////	}
////};
//
//
////int main()
////{
////	vector<Goods> v = { { "苹果", 2.1, 300 }, { "香蕉", 3.3, 100 }, { "橙子", 2.2, 1000 }, { "菠萝", 1.5, 1 } };
////	sort(v.begin(), v.end(), ComparePriceLess());    //按价格升序排序
////	sort(v.begin(), v.end(), ComparePriceGreater()); //按价格降序排序
////	sort(v.begin(), v.end(), CompareNumLess());      //按数量升序排序
////	sort(v.begin(), v.end(), CompareNumGreater());   //按数量降序排序
////	return 0;
////}
//
//
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 300 }, { "香蕉", 3.3, 100 }, { "橙子", 2.2, 1000 }, { "菠萝", 1.5, 1 } };
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{
//			return g1._price < g2._price;
//		}); //按价格升序排序
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{
//			return g1._price > g2._price;
//		}); //按价格降序排序
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{
//			return g1._num < g2._num;
//		}); //按数量升序排序
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{
//			return g1._num > g2._num;
//		}); //按数量降序排序
//	return 0;
//}

