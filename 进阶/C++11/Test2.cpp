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
//		//�ƶ�����
//		string(string&& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(string&& s) -- �ƶ�����" << endl;
//			swap(s);
//		}
//		//������ֵ�������ִ�д����
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(const string& s) -- ���" << endl;
//
//			string tmp(s); //��s�������������tmp
//			swap(tmp); //��������������
//			return *this; //������ֵ��֧��������ֵ��
//		}
//		//�ƶ���ֵ
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
//			swap(s);
//			return *this;
//		}
//		//��������
//		~string()
//		{
//			//delete[] _str;  //�ͷ�_strָ��Ŀռ�
//			_str = nullptr; //��ʱ�ÿգ���ֹ�Ƿ�����
//			_size = 0;      //��С��0
//			_capacity = 0;  //������0
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
//	//���캯��
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{}
//	////�������캯��
//	//Person(const Person& p)
//	//	:_name(p._name)
//	//	, _age(p._age)
//	//{}
//	////������ֵ����
//	//Person& operator=(const Person& p)
//	//{
//	//	if (this != &p)
//	//	{
//	//		_name = p._name;
//	//		_age = p._age;
//	//	}
//	//	return *this;
//	//}
//	//��������
//	//~Person()
//	//{}
//private:
//	cl::string _name; //����
//	int _age;         //����
//};
//
//int main()
//{
//	Person s1("����", 21);
//	Person s2 = s1;
//	Person s3 = std::move(s1); //��Ҫ����PersonĬ�����ɵ��ƶ�����
//
//	return 0;
//}
