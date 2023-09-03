//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <list>
//#include <map>
//#include <assert.h>
//#include <algorithm>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//using namespace std;
//
////int x = 0;
//
//mutex mtx;
//condition_variable cv;
//
////void Func(int n)
////{
////	lock_guard<mutex> lock(mtx);
////	for (int i = 0; i < n; i++)
////	{
////		++x;
////	}
////}
//
//int main()
//{
//	int n = 100;
//	//atomic<int> x = 0;
//
//	int x = 1;
//	bool flag = true;
//
//	//thread t1(Func, 1000);
//	//thread t2(Func, 1000);
//
//	thread t1([&, n]()
//	{
//			while (x < n)
//			{
//				unique_lock<mutex> ul(mtx);
//				if (x >= 100)
//				{
//					break;
//				}
//
//				/*if (x % 2 == 0)
//				{
//					cv.wait(ul);
//				}*/
//
//				cv.wait(ul, [&]() {return x % 2 == 1; });
//
//				cout << this_thread::get_id() << " : " << x << endl;
//				//unique_lock<mutex> ul(mtx);
//				++x;
//				flag = !flag;
//				cv.notify_one();
//			}
//			
//			
//	});
//
//	thread t2([&, n]()
//		{
//			while (x < n)
//			{
//				unique_lock<mutex> ul(mtx);
//				if (x > 100)
//				{
//					break;
//				}
//
//				/*if (x % 2 == 1)
//				{
//					cv.wait(ul);
//				}*/
//
//				cv.wait(ul, [&]() {return x % 2 == 0;});
//
//				cout << this_thread::get_id() << " : " << x << endl;
//				//unique_lock<mutex> ul(mtx);
//				++x;
//				flag = !flag;
//				cv.notify_one();
//			}
//			
//	});
//
//
//
//	t1.join();
//	t2.join();
//
//	return 0;
//
//
//}
