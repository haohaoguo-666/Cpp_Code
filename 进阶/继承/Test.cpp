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

// //基类/父类
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////protected:   // 在子类可见的(不能用) 只能防外面
//private:  // 在子类是不可见(不能用)  不仅仅可以放外人还可以防儿子
//	string _name = "peter"; // 姓名
//	int _age = 18;  // 年龄
//};
//
//class Student : public Person
//{
//public:
//	void func()
//	{
//		// 不可见
//		//cout <<_name << endl;
//		//cout << _age << endl;
//		cout << "void func()" << endl;
//	}
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//
//int main()
//{
//	//Student s;
//	////s.Print();
//	//s.func();
//
//	//double d = 1.1;
//	//int i = d;  // 隐式类型转换
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
//	string _name = "小李子"; // 姓名
//	int _num = 111; 		// 身份证号
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
//	// 子类和父类中有同名成员，子类成员将屏蔽父类对同名成员的直接访问，这种情况叫隐藏，也叫重定义。
//	int _num = 999; // 学号
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
//// A：两个fun构成函数重载
//// B：两个fun构成隐藏
//// C：编译报错
//// D：以上说法都不对
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
//	string _name; // 姓名
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
//	// 20:35继续
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
//	// 析构函数会被处理成destructor
//	~Student()
//	{
//		//Person::~Person();
//
//		cout << "~Student()" << endl;
//	}
//	// 子类析构函数完成时，会自定调用父类析构函数，保证先析构子再析构父
//protected:
//	int _num; //学号
//};
//
//// 21:00继续
//int main()
//{
//	Student s1("张三", 18);
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
//	string _name; // 姓名
//};
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
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
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
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




////实现一个不能被继承的类
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
//	string _name; // 姓名
//	//int _age;
//	//int _tel;
//	//int _address;
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//void main()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	a._name = "张三";
//
//	// 数据冗余 和 二义性
//	a.Student::_name = "小张";
//	a.Teacher::_name = "老张";
//}

