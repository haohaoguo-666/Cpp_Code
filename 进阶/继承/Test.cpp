#include<iostream>
#include<string>
using namespace std;


class A
{
public:
	int _a;
};
// class B : public A
class B : virtual public A
{
public:
	int _b;
};
// class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	

	B b = d;
	C c = d;


	return 0;
}

// //����/����
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////protected:   // ������ɼ���(������) ֻ�ܷ�����
//private:  // �������ǲ��ɼ�(������)  ���������Է����˻����Է�����
//	string _name = "peter"; // ����
//	int _age = 18;  // ����
//};
//
//class Student : public Person
//{
//public:
//	void func()
//	{
//		// ���ɼ�
//		//cout <<_name << endl;
//		//cout << _age << endl;
//		cout << "void func()" << endl;
//	}
//protected:
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//
//int main()
//{
//	//Student s;
//	////s.Print();
//	//s.func();
//
//	//double d = 1.1;
//	//int i = d;  // ��ʽ����ת��
//	//const int& ri = d;
//
//	Student s;
//	Person p = s;
//	Person& rp = s;
//	Person* ptrp = &s;
//
//
//	return 0;
//}

//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; 		// ���֤��
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << Person::_num << endl;
//		cout << _num << endl;
//	}
//
//protected:
//	// ����͸�������ͬ����Ա�������Ա�����θ����ͬ����Ա��ֱ�ӷ��ʣ�������������أ�Ҳ���ض��塣
//	int _num = 999; // ѧ��
//};
//
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//// A������fun���ɺ�������
//// B������fun��������
//// C�����뱨��
//// D������˵��������
//void Test()
//{
//	/*B b;
//	b.fun(10);*/
//	B b;
//	b.fun(10);
//	b.A::fun();
//};
//
//int main()
//{
//	/*Student s;
//	s.Print();*/
//
//	Test();
//
//	return 0;
//}



//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		:Person(name)
//		,_num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	Student(const Student& s)
//		:Person(s)
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//
//	}
//
//	// 20:35����
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_num = s._num;
//		}
//		cout << "Student& operator=(const Student& s)" << endl;
//
//
//		return *this;
//	}
//
//	// ���������ᱻ�����destructor
//	~Student()
//	{
//		//Person::~Person();
//
//		cout << "~Student()" << endl;
//	}
//	// ���������������ʱ�����Զ����ø���������������֤����������������
//protected:
//	int _num; //ѧ��
//};
//
//// 21:00����
//int main()
//{
//	Student s1("����", 18);
//	/*Student s2(s1);
//
//	Person p = s1;
//
//	s1 = s2;*/
//
//
//	return 0;
//}



//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}




//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	//cout << &(p._name) << endl;
//	//cout << &(s._name) << endl;
//
//	//cout << &(p._count) << endl;
//	//cout << &(s._count) << endl;
//
//	Graduate g1;
//	Graduate g2;
//
//	cout << Person::_count << endl;
//	cout << Graduate::_count << endl;
//
//	return 0;
//}




////ʵ��һ�����ܱ��̳е���
//class A
//{
//public:
//	static A CreateObj()
//	{
//		return A();
//	}
//
//
//private:
//	A()
//	{}
//};
//
//class B : public A
//{};
//
//int main()
//{
//	A::CreateObj();
//
//	//B bb;
//
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // ����
//	//int _age;
//	//int _tel;
//	//int _address;
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
//void main()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	a._name = "����";
//
//	// �������� �� ������
//	a.Student::_name = "С��";
//	a.Teacher::_name = "����";
//}

