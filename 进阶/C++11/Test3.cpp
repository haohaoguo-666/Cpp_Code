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
//////�ݹ���ֹ����
////void ShowList()
////{
////	cout << endl;
////}
//////չ������
////template<class T, class ...Args>
////void ShowList(T value, Args... args)
////{
////	cout << value << " "; //��ӡ������ĵ�һ������
////	ShowList(args...);    //�ݹ���ã����������������´�
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
//		//���캯��
//		string(const char* str = "")
//		{
//			cout << "string(const char* str) -- ���캯��" << endl;
//
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
//			cout << "string(const string& s) -- ��������" << endl;
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
////	mylist.emplace_back(kv);                              //����ֵ
////	cout << endl;
////	mylist.emplace_back(pair<int, yyf::string>(2, "two")); //����ֵ
////	cout << endl;
////	mylist.emplace_back(3, "three");                      //��������
////	return 0;
////}
//
//int main()
//{
//	list<pair<int, yyf::string>> mylist;
//
//	pair<int, yyf::string> kv(1, "one");
//	mylist.push_back(kv);                              //����ֵ
//	cout << endl;
//	mylist.push_back(pair<int, yyf::string>(2, "two")); //����ֵ
//	cout << endl;
//	mylist.push_back({ 3, "three" });                  //�б��ʼ��
//	return 0;
//}
