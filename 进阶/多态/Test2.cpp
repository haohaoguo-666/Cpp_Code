#include<iostream>
using namespace std;

//class Base
//{
//public:
//	Base()
//		:_b(10)
//	{
//		++_b;
//	}
//
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//
//	virtual void Func4()
//	{
//		cout << "Derive::Func4()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//// 用程序打印虚表
//typedef void(*VF_PTR)();
//
////void PrintVFTable(VF_PTR table[])
//void PrintVFTable(VF_PTR* table)
//{
//	for (int i = 0; table[i] != nullptr; ++i)
//	{
//		printf("[%d]:%p->", i, table[i]);
//		VF_PTR f = table[i];
//		f();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	PrintVFTable((VF_PTR*)(*(int*)&b));
//	PrintVFTable((VF_PTR*)(*(int*)&d));
//
//	// 虚表是什么阶段生成的？          -- 编译
//	// 对象中虚表指针什么时候初始化的？ -- 构造函数的初始化列表
//	// 虚表存在哪里？                  -- 代码段（常量区）
// 
//	/*PrintVFTable((VF_PTR*)(*(long long*)&b));
//	PrintVFTable((VF_PTR*)(*(long long*)&d));*/
//
//	//PrintVFTable((*(VF_PTR**)&b));
//	//PrintVFTable((*(VF_PTR**)&d));
//
//	return 0;
//}

//int main()
//{
//	Base b;
//	Derive d;
//
//	int x = 0;
//	static int y = 0;
//	int* z = new int;
//	const char* p = "xxxxxxxxxxxxxxxxxx";
//
//	printf("栈对象：%p\n", &x);
//	printf("堆对象：%p\n", z);
//	printf("静态区对象：%p\n", &y);
//	printf("常量区对象：%p\n", p);
//	printf("b对象虚表：%p\n", *((int*)&b));
//	printf("d对象虚表：%p\n", *((int*)&d));
//	return 0;
//}

//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//	int bb;
//};
//
//class Derive : public Base2, public Base1 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//
//// 用程序打印虚表
//typedef void(*VF_PTR)();
//
////void PrintVFTable(VF_PTR table[])
//void PrintVFTable(VF_PTR* table)
//{
//	for (int i = 0; table[i] != nullptr; ++i)
//	{
//		printf("[%d]:%p->", i, table[i]);
//		VF_PTR f = table[i];
//		f();
//	}
//	cout << endl;
//}

//int main()
//{
//	Derive d;
//	PrintVFTable((VF_PTR*)(*(int*)&d));
//	//PrintVFTable((VF_PTR*)(*(int*)((char*)&d+sizeof(Base1))));
//	Base2* ptr2 = &d;
//	PrintVFTable((VF_PTR*)(*(int*)(ptr2)));
//
//	return 0;
//}

//int main()
//{
//	Derive d;
//	Base1* ptr1 = &d;
//	Base2* ptr2 = &d;
//	ptr1->func1();
// 
//	ptr2->func1();
//	return 0;
//}

//class A
//{
//public:
//	virtual void func1()
//	{}
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	virtual void func1()
//	{}
//
//	virtual void func2()
//	{}
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	virtual void func1()
//	{}
//
//	virtual void func3()
//	{}
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	virtual void func1()
//	{
//
//	}
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	return 0;
//}

class A
{
public:
	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
	virtual void test() { func(); }
};
class B : public A
{
public:
	//虚函数的继承是一种接口继承
	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};
int main(int argc, char* argv[])
{
	B* p = new B;
	p->test();
	//注意：子类重写父类的虚函数时，只是将虚函数的实现方法重写，
	//函数声明不变（包括virtual、函数名、参数、参数顺序、缺省值都跟父类的保持一致）
	//相当于：
	/*void func(int val = 1) { std::cout << "B->" << val << std::endl; }*/
	return 0;
}