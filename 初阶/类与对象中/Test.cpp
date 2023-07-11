#define _CRT_SECURE_NO_WARNINGS 1

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Init(2022, 7, 5);
//	d1.Print();
//	Date d2;
//	d2.Init(2022, 7, 6);
//	d2.Print();
//	return 0;
//}

//class Date
//{
//public:
//	// 1.无参构造函数
//	Date()
//	{}
//	// 2.带参构造函数
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
//void TestDate()
//{
//	Date d1; // 调用无参构造函数
//	Date d2(2015, 1, 1); // 调用带参的构造函数
//	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
//	// 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
//	// warning C4930: “Date d3(void)”: 未调用原型函数(是否是有意用变量定义的?)
//	Date d3();
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
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	// 将Date类中构造函数屏蔽后，代码可以通过编译，因为编译器生成了一个无参的默认构造函数
//		// 将Date类中构造函数放开，代码编译失败，因为一旦显式定义任何构造函数，编译器将不再生成
//		// 无参构造函数，放开后报错：error C2512: “Date”: 没有合适的默认构造函数可用
//		Date d1;
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year;
//	int _month;
//	int _day;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}

//class Date
//{
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	Date(int year = 1988, int month = 4, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	int get_year(){
//		return _year;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 以下测试函数能通过编译吗？
//int main()
//{
//	Date d1(1977);
//	
//	cout << d1.get_year() << endl;
//
//}

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	// 其他方法...
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//void TestStack()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);
//}

//class Time
//{
//public:
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}
////程序运行结束后输出：~Time()
////在main方法中根本没有直接创建Time类的对象，为什么最后会调用Time类的析构函数？
////因为：main方法中创建了Date对象d，而d中包含4个成员变量，其中_year, _month,_day三个是
////内置类型成员，销毁时不需要资源清理，最后系统直接将其内存回收即可；而_t是Time类对象，所以在
////d销毁时，要将其内部包含的Time类的_t对象销毁，所以要调用Time类的析构函数。但是：main函数
////中不能直接调用Time类的析构函数，实际要释放的是Date类对象，所以编译器会调用Date类的析构函
////数，而Date没有显式提供，则编译器会给Date类生成一个默认的析构函数，目的是在其内部调用Time
////类的析构函数，即当Date对象销毁时，要保证其内部每个自定义对象都可以正确销毁
////main函数中并没有直接调用Time类析构函数，而是显式调用编译器为Date类生成的默认析构函数
////注意：创建哪个类的对象则调用该类的析构函数，销毁那个类的对象则调用该类的析构函数


//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	 Date(const Date& d) // 正确写法
//	Date(const Date& d) // 错误写法：编译报错，会引发无穷递归
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1;
//	}
//	Time(const Time& t)
//	{
//		_hour = t._hour;
//		_minute = t._minute;
//		_second = t._second;
//		cout << "Time::Time(const Time&)" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	// 用已经存在的d1拷贝构造d2，此处会调用Date类的拷贝构造函数
//	// 但Date类并没有显式定义拷贝构造函数，则编译器会给Date类生成一个默认的拷贝构造函数
//	Date d2(d1);
//	return 0;
//}

// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2(s1);
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int minute, int day)
//	{
//		cout << "Date(int,int,int):" << this << endl;
//	}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d):" << this << endl;
//	}
//	~Date()
//	{
//		cout << "~Date():" << this << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//Date Test(Date d)
//{
//	Date temp(d);
//	return temp;
//}
//int main()
//{
//	Date d1(2022, 1, 13);
//	Test(d1);
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 2023, int month = 2, int day = 3)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "年";
//		cout << _month << "月";
//		cout << _day << "日";
//		cout << endl;
//	}
//	Date Add(int x)
//	{
//		Date ret = *this;
//		ret._day += x;
//		while (ret._day > GetMonthDay(ret._year, ret._month))
//		{
//			//进位
//			ret._day -= GetMonthDay(ret._year, ret._month);
//			++ret._month;
//			if (ret._month == 13)
//			{
//				ret._year++;
//				ret._month = 1;
//			}
//		}
//
//		return ret;
//	}
//
//	Date& AddEqual(int x)
//	{
//	
//		_day += x;
//		while (_day > GetMonthDay(_year, _month))
//		{
//			//进位
//			_day -= GetMonthDay(_year, _month);
//			++_month;
//			if (_month == 13)
//			{
//				_year++;
//				_month = 1;
//			}
//		}
//		
//		return *this;
//	}
//
//	
//	int GetMonthDay(int year, int month)
//	{
//		assert(month > 0 && month < 13);
//		int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		{
//			return 29;
//		}
//		else
//		{
//			return monthArray[month];
//		}
//		
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2023, 2, 3);
//	Date d2 = d1.Add(100);
//	Date d3 = d1.AddEqual(150);
//
//	d1.Print();
//	d2.Print();
//	d3.Print();
//
//
//};


//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		cout << "Stack(size_t capacity = 10)" << endl;
//
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			exit(-1);
//		}
//
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	Stack(const Stack& st)
//	{
//		cout << "Stack(const Stack& st)" << endl;
//		_array = (DataType*)malloc(sizeof(DataType)*st._capacity);
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			exit(-1);
//		}
//
//		memcpy(_array, st._array, sizeof(DataType)*st._size);
//		_size = st._size;
//		_capacity = st._capacity;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	DataType *_array;
//	size_t    _size;
//	size_t    _capacity;
//};
//
//class MyQueue
//{
//public:
//	// 默认生成构造
//	// 默认生成析构
//	// 默认生成拷贝构造
//
//private:
//	Stack _pushST;
//	Stack _popST;
//	int _size = 0;
//};
//
//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(4);
//
//	Stack st2(st1);
//	cout << "=============================" << endl;
//
//	MyQueue q1;
//	MyQueue q2(q1);
//
//
//	return 0;
//}

// 全局的operator==
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//    //private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 这里会发现运算符重载成全局的就需要成员变量是公有的，那么问题来了，封装性如何保证？
//// 这里其实可以用我们后面学习的友元解决，或者干脆重载成成员函数。
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//	// bool operator==(Date* this, const Date& d2)
//	// 这里需要注意的是，左操作数是this，
//	bool operator==(const Date& d2)
//	{
//		return _year == d2._year
//		&& _month == d2._month
//			&& _day == d2._day;
//	}
//
//	bool operator<(const Date& d2)
//	{
//		if (_year > d2._year)
//			return false;
//		else if (_year == d2._year && _month > d2._month)
//			return false;
//		else if (_year == d2._year && _month == d2._month && _day > d2._day)
//			return false;
//		else 
//			return true;
//	}
//
//	bool operator>(const Date& d2)
//	{
//		return !(*this < d2 && *this == d2);
//	}
//	
//	bool operator!=(const Date& d2)
//	{
//		return !(*this == d2);
//	}
//
//	// d3 = d2 = d1;
//	// 返回值为了支持连续赋值，保持运算符的特性
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			this->_year = d._year;
//			this->_month = d._month;
//			this->_day = d._day;
//		}
//		
//		return *this;
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	d1 = d2;
//	d1.Print();
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
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

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	int _year;
//	int _month;
//	int _day;
//};
//// 赋值运算符重载成全局函数，注意重载成全局函数时没有this指针了，需要给两个参数
//Date& operator=(Date& left, const Date& right)
//{
//	if (&left != &right)
//	{
//		left._year = right._year;
//		left._month = right._month;
//		left._day = right._day;
//	}
//	return left;
//}
//// 编译失败：
//// error C2801: “operator =”必须是非静态成员


//Date d1(2024, 2, 4);
//Date d2(2023, 3, 4);
//Date d3(2025, 3, 4);
//
//
//d3 = d2 = d1; // 赋值重载
//
//Date d5 = d1; // 拷贝构造
//Date d6(d1); // 拷贝构造 

//class Time
//{
//public:
//	Time()
//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1;
//	}
//	Time& operator=(const Time& t)
//	{
//		if (this != &t)
//		{
//			_hour = t._hour;
//			_minute = t._minute;
//			_second = t._second;
//		}
//		return *this;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	Date d2;
//	d1 = d2;
//	return 0;
//}

// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2;
//	s2 = s1;
//	return 0;
//}
#include "Date.h"


void TestDate1()
{
	Date d1(2023, 2, 20);
	Date d2 = d1 + 100;
	//d2 += 100;
	d1.Print();
	d2.Print();

}

int main()
{
	TestDate1();
}