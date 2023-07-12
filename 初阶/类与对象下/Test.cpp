#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		this->Print1();
//		cout << "Print()" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//	void Print1() const
//	{
//
//		cout << "Print()const" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//void Test()
//{
//	Date d1(2022, 1, 13);
//	d1.Print();
//	/*const Date d2(2022, 1, 13);
//	d2.Print();*/
//}
//
//int main()
//{
//	Test();
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//class B
//{
//public:
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	A _aobj; // 没有默认构造函数
//	int& _ref; // 引用
//	const int _n; // const
//};

//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int day)
//	{}
//private:
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d(1);
//}

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() {
//	A aa(1);
//	aa.Print();
//} 
//A.输出1 1
//B.程序崩溃
//C.编译不通过
//D.输出1 随机值

//class Date
//{
//public:
//	// 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
//// explicit修饰构造函数，禁止类型转换---explicit去掉之后，代码可以通过编译
//	explicit Date(int year)
//		:_year(year)
//	{}
//	/*
//	// 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具
//	有类型转换作用
//	// explicit修饰构造函数，禁止类型转换
//	explicit Date(int year, int month = 1, int day = 1)
//	: _year(year)
//	, _month(month)
//	, _day(day)
//	{}
//	*/
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Test()
//{
//	Date d1(2022);
//	// 用一个整形变量给日期类型对象赋值
//	// 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
//	d1 = 2023;
//	// 将1屏蔽掉，2放开时则编译失败，因为explicit修饰构造函数，禁止了单参构造函数类型转换的作用
//}

//class A
//{
//public:
//	A()
//		:_a(3)
//	{}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	B(int a, int ref)
//		:_aobj()
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	A _aobj; // 没有默认构造函数
//	int& _ref; // 引用
//	const int _n; // const
//};
//
//int main()
//{
//	B bb(10, 12);
//}


//class Date
//{
//public:
//	/*
//	// 如果用户显式定义了构造函数，编译器将不再生成
//	Date(int year, int month, int day)
//	{
//	_year = year;
//	_month = month;
//	_day = day;
//	}
//	*/
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//
//	Date d1;
//	d1.Print();
//	return 0;
//}

//class A
//{
//public:
//	A()
//		:n(10)
//	{
//		_a1 = 1;
//		_a2 = 2;
//	}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a1;
//	int _a2;
//	const int n;
//};
//int main() {
//	A aa;
//	aa.Print();
//}