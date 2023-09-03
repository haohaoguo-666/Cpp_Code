//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <list>
//#include <map>
//#include <assert.h>
//
//using namespace std;
//
//namespace cl
//{
//	class string
//	{
//	public:
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
//		//移动构造
//		string(string&& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(string&& s) -- 移动构造" << endl;
//			swap(s);
//		}
//		//拷贝赋值函数（现代写法）
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(const string& s) -- 深拷贝" << endl;
//
//			string tmp(s); //用s拷贝构造出对象tmp
//			swap(tmp); //交换这两个对象
//			return *this; //返回左值（支持连续赋值）
//		}
//		//移动赋值
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
//			swap(s);
//			return *this;
//		}
//		//析构函数
//		~string()
//		{
//			//delete[] _str;  //释放_str指向的空间
//			_str = nullptr; //及时置空，防止非法访问
//			_size = 0;      //大小置0
//			_capacity = 0;  //容量置0
//			cout << "~string" << endl;
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//}
//
//class Person
//{
//public:
//	//构造函数
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{}
//	////拷贝构造函数
//	//Person(const Person& p)
//	//	:_name(p._name)
//	//	, _age(p._age)
//	//{}
//	////拷贝赋值函数
//	//Person& operator=(const Person& p)
//	//{
//	//	if (this != &p)
//	//	{
//	//		_name = p._name;
//	//		_age = p._age;
//	//	}
//	//	return *this;
//	//}
//	//析构函数
//	//~Person()
//	//{}
//private:
//	cl::string _name; //姓名
//	int _age;         //年龄
//};
//
//int main()
//{
//	Person s1("张三", 21);
//	Person s2 = s1;
//	Person s3 = std::move(s1); //想要调用Person默认生成的移动构造
//
//	return 0;
//}
