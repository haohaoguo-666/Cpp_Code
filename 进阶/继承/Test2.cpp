#include<iostream>
using namespace std;

//class Person
//{
//public:
//	string _name; // ����
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//void Test()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	a._name = "peter";
//
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}

//class A
//{
//public:
//	int _a;
//};
//
////class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
////class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	/*Test();*/
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	B b;
//	b._a = 10;
//	b._b = 20;
//
//	B* ptrb = &d;
//	ptrb->_a++;
//
//	ptrb = &b;
//	ptrb->_a++;
//
//	D d1, d2;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A{
//public:
//	A(char *s) { cout << s << endl; }
//	~A(){}
//};
//
//class B :virtual public A
//{
//public:
//	B(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//
//class C :virtual public A
//{
//public:
//	C(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//
//class D : public C, public B
//{
//public:
//	D(char *s1, char *s2, char *s3, char *s4) :B(s1, s2), C(s1, s3), A(s1)
//	{
//		cout << s4 << endl;
//	}
//};
//
//int main() {
//	D *p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}

//// ���м̳� -- is-a
//class A
//{
//public:
//	void func(){}
//protected:
//	int _a1;
//	int _a2;
//};
//
//class B : public A
//{};
//
//// ���    -- has-a
//class C
//{
//public:
//	void func(){}
//protected:
//	int _c1;
//	int _c2;
//};
//
//class D
//{
//private:
//	C _cc;
//};
//
//int main()
//{
//
//	return 0;
//}

//class Person 
//{
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person
//{
//public:
//	// ��д/����
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
//void Func(Person p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//
//
//	return 0;
//}

//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//
//int main()
//{
//	Person* ptr1 = new Person;
//	Person* ptr2 = new Student;
//
//	delete ptr1;
//	delete ptr2;
//
//	return 0;
//}