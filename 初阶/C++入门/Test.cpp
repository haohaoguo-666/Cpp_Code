#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
using namespace std;


//int main()
//{
//	cout << "hello world" << endl;
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int rand = 10;
//// C����û�취�������������������ͻ���⣬����C++�����namespace�����
//int main()
//{
//	printf("%d\n", rand);
//	return 0;
//}
//// �����󱨴�error C2365: ��rand��: �ض��壻��ǰ�Ķ����ǡ�������

//int a = 2;
//
//void f1()
//{
//	int a = 0;
//	printf("%d\n", a);// �ھֲ�������a
//	printf("%d\n", ::a);// ::���޶�������ȫ��������a
//
//}

//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Func(); // û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	Func(10); // ����ʱ��ʹ��ָ����ʵ��
//	return 0;
//}

//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}

//void Func(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}

//#include<iostream>
//using namespace std;
//// 1���������Ͳ�ͬ
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//// 2������������ͬ
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3����������˳��ͬ
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//int main()
//{
//	Add(10, 20);
//	Add(10.1, 20.2);
//	f();
//	f(10);
//	f(10, 'a');
//	f('a', 10);
//	return 0;
//}

//void TestRef()
//{
//	int a = 10;
//	int& ra = a;//<====������������
//	printf("%p\n", &a);
//	printf("%p\n", &ra);
//}

//void TestRef()
//{
//	int a = 10;
//	 int& ra; // ����������ʱ�����
//	int& ra = a;
//	int& rra = a;
//	printf("%p %p %p\n", &a, &ra, &rra);
//}

//void TestConstRef()
//{
//	const int a = 10;
//	//int& ra = a; // ��������ʱ�����aΪ����
//	const int& ra = a;
//	// int& b = 10; // ��������ʱ�����bΪ����
//	const int& b = 10;
//	double d = 12.34;
//	//int& rd = d; // ��������ʱ��������Ͳ�ͬ
//	const int& rd = d;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}

//int& Count()
//{
//	static int n = 0;
//	n++;
//	// ...
//	return n;
//}

//#define N 10
//typedef struct Array
//{
//	int a[N];
//	int size;
//}AY;
//
//int& PostAy(AY& ay, int i)
//{
//	assert(i < N);
//	return ay.a[i];
//}
//
//int main()
//{
//	AY p;
//	for (int i = 0; i < N; i++)
//	{
//		PostAy(p, i) = i * 10;
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << p.a[i] << " ";
//	}
//
//	cout << endl;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}

//#include <time.h>
//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}

//#include <time.h>
//struct A { int a[10000]; };
//A a;
//// ֵ����
//A TestFunc1() { return a; }
//// ���÷���
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// �������������������֮���ʱ��
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}

//int Count()
//{
//	int c = 0;
//	return c;
//}
//
//int main()
//{
//
//	int i = 0;
//	const double& rd = i;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	cout << "&a = " << &a << endl;
//	cout << "&ra = " << &ra << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	ra = 20;
//	int* pa = &a;
//	*pa = 20;
//	return 0;
//}

//#define ADD(x, y) ((x) + (y))

//// F.h
//#include <iostream>
//using namespace std;
//inline void f(int i);
//// F.cpp
//#include "F.h"
//void f(int i)
//{
//	cout << i << endl;
//}
//// main.cpp
//#include "F.h"
//int main()
//{
//	f(10);
//	return 0;
//}
//// ���Ӵ���main.obj : error LNK2019: �޷��������ⲿ���� "void __cdeclf(int)" (?f@@YAXH@Z)���÷����ں��� _main �б�����

//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
//	return 0;
//}

//typedef char* pstring;
//int main()
//{
//	const pstring p1; // ����ɹ�����ʧ�ܣ�
//	const pstring* p2; // ����ɹ�����ʧ�ܣ�
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	*a = 20;
//	*b = 30;
//	c = 40;
//	return 0;
//}

//void TestAuto()
//{
//	auto a = 1, b = 2;
//	auto c = 3, d = 4.0; // ���д�������ʧ�ܣ���Ϊc��d�ĳ�ʼ�����ʽ���Ͳ�ͬ
//}

//// �˴��������ʧ�ܣ�auto������Ϊ�β����ͣ���Ϊ�������޷���a��ʵ�����ͽ����Ƶ�
//void TestAuto(auto a)
//{}

//void TestAuto()
//{
//	int a[] = { 1,2,3 };
//	auto b[] = { 4��5��6 };
//}

//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		array[i] *= 2;
//	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
//		cout << *p << endl;
//}

//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//
//	for (auto& e : array)
//		e *= 2;
//	for (auto e : array)
//		cout << e << " ";
//	
//}

//void TestFor(int array[])
//{
//	for (auto& e : array)
//		cout << e << endl;
//}

//void TestPtr()
//{
//	int* p1 = NULL;
//	int* p2 = 0;
//	// ����
//}

//#ifndef NULL
//#ifdef __cplusplus
//#define NULL 0
//#else
//#define NULL ((void *)0)
//#endif
//#endif

//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);
//	f(NULL);
//	f((int*)NULL);
//	return 0;
//}