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
//	string _name;  //����
//	double _price; //�۸�
//	int _num;      //����
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
////	vector<Goods> v = { { "ƻ��", 2.1, 300 }, { "�㽶", 3.3, 100 }, { "����", 2.2, 1000 }, { "����", 1.5, 1 } };
////	sort(v.begin(), v.end(), ComparePriceLess());    //���۸���������
////	sort(v.begin(), v.end(), ComparePriceGreater()); //���۸�������
////	sort(v.begin(), v.end(), CompareNumLess());      //��������������
////	sort(v.begin(), v.end(), CompareNumGreater());   //��������������
////	return 0;
////}
//
//
//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 300 }, { "�㽶", 3.3, 100 }, { "����", 2.2, 1000 }, { "����", 1.5, 1 } };
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{
//			return g1._price < g2._price;
//		}); //���۸���������
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{
//			return g1._price > g2._price;
//		}); //���۸�������
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{
//			return g1._num < g2._num;
//		}); //��������������
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{
//			return g1._num > g2._num;
//		}); //��������������
//	return 0;
//}

