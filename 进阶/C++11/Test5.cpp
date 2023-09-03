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
//
//using namespace std;
//
//void Func(int n, int nums)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		cout << nums << " : " << i << endl;
//	}
//}
//
//
//int main()
//{
//	//thread t1 = thread(Func, 5, 1);
//	//thread t2 = thread(Func, 10, 2);
//	
//	/*int n1, n2;
//	cin >> n1 >> n2;
//
//	thread t1([n1](int num)
//		{
//			for (int i = 0; i < n1; ++i)
//			{
//				cout << num << ":" << i << endl;
//			}
//			cout << endl;
//		}, 1);
//
//	thread t2([n2](int num)
//		{
//			for (int i = 0; i < n2; ++i)
//			{
//				cout << num << ":" << i << endl;
//			}
//			cout << endl;
//		}, 2);
//
//	t1.join();
//	t2.join();*/
//
//	size_t m;
//	cin >> m;
//	vector<thread> vthds(m);
//
//	//m个线程分别打印n
//	for (size_t i = 0; i < m; i++)
//	{
//		
//		size_t n = 10;
//		vthds[i] = thread([n]()
//			{
//				for (int j = 0; j < n; ++j)
//				{
//					cout << this_thread::get_id() << ":" << j << endl;
//					this_thread::sleep_for(chrono::seconds(1));
//				}
//				cout << endl;
//
//
//			});
//
//			
//	} 
//
//	for (auto &t : vthds)
//	{
//		t.join();
//	}
//}