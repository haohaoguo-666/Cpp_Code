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
//
//////递归终止函数
////void ShowList()
////{
////	cout << endl;
////}
//////展开函数
////template<class T, class ...Args>
////void ShowList(T value, Args... args)
////{
////	cout << value << " "; //打印分离出的第一个参数
////	ShowList(args...);    //递归调用，将参数包继续向下传
////}
////
////int main()
////{
////	ShowList();
////	ShowList(1);
////	ShowList(1, 2);
////	ShowList(1, 2, 3);
////	return 0;
////}
//
//namespace yyf
//{
//	class string
//	{
//	public:
//		//构造函数
//		string(const char* str = "")
//		{
//			cout << "string(const char* str) -- 构造函数" << endl;
//
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
//			cout << "string(const string& s) -- 拷贝构造" << endl;
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
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//}
//
////int main()
////{
////	list<pair<int, yyf::string>> mylist;
////
////	pair<int, yyf::string> kv(1, "one");
////	mylist.emplace_back(kv);                              //传左值
////	cout << endl;
////	mylist.emplace_back(pair<int, yyf::string>(2, "two")); //传右值
////	cout << endl;
////	mylist.emplace_back(3, "three");                      //传参数包
////	return 0;
////}
//
//int main()
//{
//	list<pair<int, yyf::string>> mylist;
//
//	pair<int, yyf::string> kv(1, "one");
//	mylist.push_back(kv);                              //传左值
//	cout << endl;
//	mylist.push_back(pair<int, yyf::string>(2, "two")); //传右值
//	cout << endl;
//	mylist.push_back({ 3, "three" });                  //列表初始化
//	return 0;
//}
