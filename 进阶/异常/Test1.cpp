//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//
//using namespace std;
//
//
//class Exception
//{
//public:
//	Exception(int errid, const string& errmsg)
//		:_errid(errid)
//		,_errmsg(errmsg)
//	{}
//
//	const string& GetMsg() const
//	{
//		return _errmsg;
//	}
//
//	const int GetErrid() const
//	{
//		return _errid;
//	}
//private:
//	int _errid;		// ������
//	string _errmsg; // ��������
//};
//
//double Division(int a, int b)
//{
//	//��b == 0ʱ�׳��쳣
//	if (b == 0)
//	{
//		/*Exception error(1, "��0����");
//		throw error;*/
//		throw Exception(1, "��0����");
//	}
//	else
//	{
//		return (double)a / b;
//	}
//}
//
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//	cout << "Division" << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const Exception& e)
//	{
//		cout << e.GetErrid() << ":" << e.GetMsg() << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪�쳣" << endl;
//	}
//
//	return 0;
//}
//
//  