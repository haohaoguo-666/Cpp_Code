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
//	int _errid;		// ´íÎóÂë
//	string _errmsg; // ´íÎóÃèÊö
//};
//
//double Division(int a, int b)
//{
//	//µ±b == 0Ê±Å×³öÒì³£
//	if (b == 0)
//	{
//		/*Exception error(1, "³ý0´íÎó");
//		throw error;*/
//		throw Exception(1, "³ý0´íÎó");
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
//		cout << "Î´ÖªÒì³£" << endl;
//	}
//
//	return 0;
//}
//
//  