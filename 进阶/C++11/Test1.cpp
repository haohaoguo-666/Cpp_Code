#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <assert.h>

using namespace std;

//int main()
//{
//	int a{ 1 };
//
//	cout << a << endl;
//	int arr[] = {1, 2, 3};
//}

//int main()
//{
//	auto il = { 1, 2, 3, 4, 5 };
//	cout << typeid(il).name() << endl; //class std::initializer_list<int>
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	//用大括号括起来的列表对容器进行初始化
//	vector<int> v = { 1, 2, 3, 4, 5 };
//	list<int> l = { 10, 20, 30, 40, 50 };
//	vector<Date> vd = { Date(2022, 8, 29), Date{ 2022, 8, 30 }, { 2022, 8, 31 } };
//	map<string, string> m{ make_pair("sort", "排序"), { "insert", "插入" } };
//
//	//用大括号括起来的列表对容器赋值
//	v = { 5, 4, 3, 2, 1 };
//	return 0;
//}

//int main()
//{
//	int i = 10;
//	auto p = &i;
//	auto pf = strcpy;
//
//	cout << typeid(p).name() << endl;  //int *
//	cout << typeid(pf).name() << endl; //char * (__cdecl*)(char *,char const *)
//
//	map<string, string> dict = { { "sort", "排序" }, { "insert", "插入" } };
//	//map<string, string>::iterator it = dict.begin();
//	auto it = dict.begin();  //简化代码
//
//	return 0;
//}

//void* GetMemory(size_t size)
//{
//	return malloc(size);
//}
//int main()
//{
//	//如果没有带参数，推导函数的类型
//	cout << typeid(decltype(GetMemory)).name() << endl;
//	//如果带参数列表，推导的是函数返回值的类型，注意：此处只是推演，不会执行函数
//	cout << typeid(decltype(GetMemory(0))).name() << endl;
//	return 0;
//}

//namespace yyf
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//		iterator begin()
//		{
//			return _str; //返回字符串中第一个字符的地址
//		}
//		iterator end()
//		{
//			return _str + _size; //返回字符串中最后一个字符的后一个字符的地址
//		}
//		//构造函数
//		string(const char* str = "")
//		{
//			_size = strlen(str); //初始时，字符串大小设置为字符串长度
//			_capacity = _size; //初始时，字符串容量设置为字符串长度
//			_str = new char[_capacity + 1]; //为存储字符串开辟空间（多开一个用于存放'\0'）
//			strcpy(_str, str); //将C字符串拷贝到已开好的空间
//		}
//		//交换两个对象的数据
//		void swap(string& s)
//		{
//			//调用库里的swap
//			::swap(_str, s._str); //交换两个对象的C字符串
//			::swap(_size, s._size); //交换两个对象的大小
//			::swap(_capacity, s._capacity); //交换两个对象的容量
//		}
//		//拷贝构造函数（现代写法）
//		string(const string& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(const string& s) -- 深拷贝" << endl;
//
//			string tmp(s._str); //调用构造函数，构造出一个C字符串为s._str的对象
//			swap(tmp); //交换这两个对象
//		}
//
//		//移动构造
//		string(string&& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(string&& s) -- 移动构造" << endl;
//			swap(s);
//		}
//	
//		//赋值运算符重载（现代写法）
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(const string& s) -- 深拷贝" << endl;
//
//			string tmp(s); //用s拷贝构造出对象tmp
//			swap(tmp); //交换这两个对象
//			return *this; //返回左值（支持连续赋值）
//		}
//
//		//移动赋值
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
//			swap(s);
//			return *this;
//		}
//
//		//析构函数
//		~string()
//		{
//			delete[] _str;  //释放_str指向的空间
//			_str = nullptr; //及时置空，防止非法访问
//			_size = 0;      //大小置0
//			_capacity = 0;  //容量置0
//		}
//		//[]运算符重载
//		char& operator[](size_t i)
//		{
//			assert(i < _size); //检测下标的合法性
//			return _str[i]; //返回对应字符
//		}
//		//改变容量，大小不变
//		void reserve(size_t n)
//		{
//			if (n > _capacity) //当n大于对象当前容量时才需执行操作
//			{
//				char* tmp = new char[n + 1]; //多开一个空间用于存放'\0'
//				strncpy(tmp, _str, _size + 1); //将对象原本的C字符串拷贝过来（包括'\0'）
//				delete[] _str; //释放对象原本的空间
//				_str = tmp; //将新开辟的空间交给_str
//				_capacity = n; //容量跟着改变
//			}
//		}
//		//尾插字符
//		void push_back(char ch)
//		{
//			if (_size == _capacity) //判断是否需要增容
//			{
//				reserve(_capacity == 0 ? 4 : _capacity * 2); //将容量扩大为原来的两倍
//			}
//			_str[_size] = ch; //将字符尾插到字符串
//			_str[_size + 1] = '\0'; //字符串后面放上'\0'
//			_size++; //字符串的大小加一
//		}
//		//+=运算符重载
//		string& operator+=(char ch)
//		{
//			push_back(ch); //尾插字符串
//			return *this; //返回左值（支持连续+=）
//		}
//		//返回C类型的字符串
//		const char* c_str()const
//		{
//			return _str;
//		}
//
//		
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//
//	//to_string
//	yyf::string to_string(int value)
//	{
//		bool flag = true;
//		if (value < 0)
//		{
//			flag = false;
//			value = 0 - value;
//		}
//		yyf::string str;
//		while (value > 0)
//		{
//			int x = value % 10;
//			value /= 10;
//			str += (x + '0');
//		}
//		if (flag == false)
//		{
//			str += '-';
//		}
//		std::reverse(str.begin(), str.end());
//		return str;
//	}
//}


//int main()
//{
//	list<cl::string> lt;
//	cl::string s("1111");
//
//	lt.push_back(s); //调用string的拷贝构造
//
//	s = cl::to_string(1234);
//
//	lt.push_back("2222");             //调用string的移动构造
//	lt.push_back(cl::string("3333")); //调用string的移动构造
//	lt.push_back(std::move(s));       //调用string的移动构造
//	return 0;
//}

//int main()
//{
//	yyf::string("1111");
//
//	const yyf::string& ret = yyf::string("1111");
//
//	cout << ret.c_str() << endl;
//}
