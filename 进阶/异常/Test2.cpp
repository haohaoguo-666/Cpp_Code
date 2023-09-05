//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <thread>
//using namespace std;
//
//
//class Exception
//{
//public:
//	Exception(const string& errmsg, int errid)
//		:_errid(errid)
//		, _errmsg(errmsg)
//	{}
//
//	virtual string what() const
//	{
//		return _errmsg;
//	}
//
//	const int GetErrid() const
//	{
//		return _errid;
//	}
//protected:
//	int _errid;		// 错误码
//	string _errmsg; // 错误描述
//};
//
//class SqlException : public Exception
//{
//public:
//	SqlException(const string& errmsg, int errid, const string& sql)
//		:Exception(errmsg, errid)
//		,_sql(sql)
//	{}
//
//	virtual string what() const
//	{
//		string msg = "SqlException";
//		msg += _errmsg;
//		msg += "->";
//		msg += _sql;
//
//		return msg;
//	}
//
//protected:
//	string _sql;
//};
//
//
//class CacheException : public Exception
//{
//public:
//	CacheException(const string& errmsg, int errid)
//		:Exception(errmsg, errid)
//	{}
//
//	virtual string what() const
//	{
//		string msg = "SqlException";
//		msg += _errmsg;
//
//		return msg;
//	}
//};
//
//class HttpServerException : public Exception
//{
//public:
//	HttpServerException(const string& errmsg, int errid, const string& type)
//		:Exception(errmsg, errid)
//		, _type(type)
//	{}
//	virtual string what() const
//	{
//		string msg = "HttpServerException:";
//		msg += _errmsg;
//		msg += ":";
//		msg += _type;
//		
//		return msg;
//	}
//private:
//	const string _type;
//};
//
//void SQLMgr()
//{
//	srand(time(0));
//	if (rand() % 7 == 0)
//	{
//		throw SqlException("权限不足", 100, "select * from name = '张三'");
//	}
//	
//	cout << "调用成功" << endl;
//}
//void CacheMgr()
//{
//	srand(time(0));
//	if (rand() % 5 == 0)
//	{
//		throw CacheException("权限不足", 100);
//	}
//	else if (rand() % 6 == 0)
//	{
//		throw CacheException("数据不存在", 101);
//	}
//	SQLMgr();
//}
//void HttpServer()
//{
//	// ...
//	srand(time(0));
//	if (rand() % 3 == 0)
//	{
//		throw HttpServerException("请求资源不存在", 100, "get");
//	}
//	else if (rand() % 4 == 0)
//	{
//		throw HttpServerException("权限不足", 101, "post");
//	}
//	CacheMgr();
//}
//int main()
//{
//	while (1)
//	{
//		this_thread::sleep_for(chrono::seconds(1));
//		try {
//			HttpServer();
//		}
//		catch (const Exception& e) // 这里捕获父类对象就可以
//		{
//			// 多态
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//	return 0;
//}