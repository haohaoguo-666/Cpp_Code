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
//	//�ô��������������б���������г�ʼ��
//	vector<int> v = { 1, 2, 3, 4, 5 };
//	list<int> l = { 10, 20, 30, 40, 50 };
//	vector<Date> vd = { Date(2022, 8, 29), Date{ 2022, 8, 30 }, { 2022, 8, 31 } };
//	map<string, string> m{ make_pair("sort", "����"), { "insert", "����" } };
//
//	//�ô��������������б��������ֵ
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
//	map<string, string> dict = { { "sort", "����" }, { "insert", "����" } };
//	//map<string, string>::iterator it = dict.begin();
//	auto it = dict.begin();  //�򻯴���
//
//	return 0;
//}

//void* GetMemory(size_t size)
//{
//	return malloc(size);
//}
//int main()
//{
//	//���û�д��������Ƶ�����������
//	cout << typeid(decltype(GetMemory)).name() << endl;
//	//����������б��Ƶ����Ǻ�������ֵ�����ͣ�ע�⣺�˴�ֻ�����ݣ�����ִ�к���
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
//			return _str; //�����ַ����е�һ���ַ��ĵ�ַ
//		}
//		iterator end()
//		{
//			return _str + _size; //�����ַ��������һ���ַ��ĺ�һ���ַ��ĵ�ַ
//		}
//		//���캯��
//		string(const char* str = "")
//		{
//			_size = strlen(str); //��ʼʱ���ַ�����С����Ϊ�ַ�������
//			_capacity = _size; //��ʼʱ���ַ�����������Ϊ�ַ�������
//			_str = new char[_capacity + 1]; //Ϊ�洢�ַ������ٿռ䣨�࿪һ�����ڴ��'\0'��
//			strcpy(_str, str); //��C�ַ����������ѿ��õĿռ�
//		}
//		//�����������������
//		void swap(string& s)
//		{
//			//���ÿ����swap
//			::swap(_str, s._str); //�������������C�ַ���
//			::swap(_size, s._size); //������������Ĵ�С
//			::swap(_capacity, s._capacity); //�����������������
//		}
//		//�������캯�����ִ�д����
//		string(const string& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(const string& s) -- ���" << endl;
//
//			string tmp(s._str); //���ù��캯���������һ��C�ַ���Ϊs._str�Ķ���
//			swap(tmp); //��������������
//		}
//
//		//�ƶ�����
//		string(string&& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(string&& s) -- �ƶ�����" << endl;
//			swap(s);
//		}
//	
//		//��ֵ��������أ��ִ�д����
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(const string& s) -- ���" << endl;
//
//			string tmp(s); //��s�������������tmp
//			swap(tmp); //��������������
//			return *this; //������ֵ��֧��������ֵ��
//		}
//
//		//�ƶ���ֵ
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
//			swap(s);
//			return *this;
//		}
//
//		//��������
//		~string()
//		{
//			delete[] _str;  //�ͷ�_strָ��Ŀռ�
//			_str = nullptr; //��ʱ�ÿգ���ֹ�Ƿ�����
//			_size = 0;      //��С��0
//			_capacity = 0;  //������0
//		}
//		//[]���������
//		char& operator[](size_t i)
//		{
//			assert(i < _size); //����±�ĺϷ���
//			return _str[i]; //���ض�Ӧ�ַ�
//		}
//		//�ı���������С����
//		void reserve(size_t n)
//		{
//			if (n > _capacity) //��n���ڶ���ǰ����ʱ����ִ�в���
//			{
//				char* tmp = new char[n + 1]; //�࿪һ���ռ����ڴ��'\0'
//				strncpy(tmp, _str, _size + 1); //������ԭ����C�ַ�����������������'\0'��
//				delete[] _str; //�ͷŶ���ԭ���Ŀռ�
//				_str = tmp; //���¿��ٵĿռ佻��_str
//				_capacity = n; //�������Ÿı�
//			}
//		}
//		//β���ַ�
//		void push_back(char ch)
//		{
//			if (_size == _capacity) //�ж��Ƿ���Ҫ����
//			{
//				reserve(_capacity == 0 ? 4 : _capacity * 2); //����������Ϊԭ��������
//			}
//			_str[_size] = ch; //���ַ�β�嵽�ַ���
//			_str[_size + 1] = '\0'; //�ַ����������'\0'
//			_size++; //�ַ����Ĵ�С��һ
//		}
//		//+=���������
//		string& operator+=(char ch)
//		{
//			push_back(ch); //β���ַ���
//			return *this; //������ֵ��֧������+=��
//		}
//		//����C���͵��ַ���
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
//	lt.push_back(s); //����string�Ŀ�������
//
//	s = cl::to_string(1234);
//
//	lt.push_back("2222");             //����string���ƶ�����
//	lt.push_back(cl::string("3333")); //����string���ƶ�����
//	lt.push_back(std::move(s));       //����string���ƶ�����
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
