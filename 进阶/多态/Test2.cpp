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
//// �ó����ӡ���
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
//	// �����ʲô�׶����ɵģ�          -- ����
//	// ���������ָ��ʲôʱ���ʼ���ģ� -- ���캯���ĳ�ʼ���б�
//	// ���������                  -- ����Σ���������
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
//	printf("ջ����%p\n", &x);
//	printf("�Ѷ���%p\n", z);
//	printf("��̬������%p\n", &y);
//	printf("����������%p\n", p);
//	printf("b�������%p\n", *((int*)&b));
//	printf("d�������%p\n", *((int*)&d));
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
//// �ó����ӡ���
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
	//�麯���ļ̳���һ�ֽӿڼ̳�
	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};
int main(int argc, char* argv[])
{
	B* p = new B;
	p->test();
	//ע�⣺������д������麯��ʱ��ֻ�ǽ��麯����ʵ�ַ�����д��
	//�����������䣨����virtual��������������������˳��ȱʡֵ��������ı���һ�£�
	//�൱�ڣ�
	/*void func(int val = 1) { std::cout << "B->" << val << std::endl; }*/
	return 0;
}