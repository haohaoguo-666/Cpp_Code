#define _CRT_SECURE_NO_WARNINGS 1

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Init(2022, 7, 5);
//	d1.Print();
//	Date d2;
//	d2.Init(2022, 7, 6);
//	d2.Print();
//	return 0;
//}

//class Date
//{
//public:
//	// 1.�޲ι��캯��
//	Date()
//	{}
//	// 2.���ι��캯��
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestDate()
//{
//	Date d1; // �����޲ι��캯��
//	Date d2(2015, 1, 1); // ���ô��εĹ��캯��
//	// ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
//	// ���´���ĺ�����������d3�������ú����޲Σ�����һ���������͵Ķ���
//	// warning C4930: ��Date d3(void)��: δ����ԭ�ͺ���(�Ƿ��������ñ��������?)
//	Date d3();
//}

//class Date
//{
//public:
//	/*
//	// ����û���ʽ�����˹��캯��������������������
//	Date(int year, int month, int day)
//	{
//	_year = year;
//	_month = month;
//	_day = day;
//	}
//	*/
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	// ��Date���й��캯�����κ󣬴������ͨ�����룬��Ϊ������������һ���޲ε�Ĭ�Ϲ��캯��
//		// ��Date���й��캯���ſ����������ʧ�ܣ���Ϊһ����ʽ�����κι��캯��������������������
//		// �޲ι��캯�����ſ��󱨴�error C2512: ��Date��: û�к��ʵ�Ĭ�Ϲ��캯������
//		Date d1;
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// ��������(��������)
//	int _year;
//	int _month;
//	int _day;
//	// �Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// ��������(��������)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// �Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}

//class Date
//{
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	Date(int year = 1988, int month = 4, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	int get_year(){
//		return _year;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// ���²��Ժ�����ͨ��������
//int main()
//{
//	Date d1(1977);
//	
//	cout << d1.get_year() << endl;
//
//}

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	// ��������...
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//void TestStack()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);
//}

//class Time
//{
//public:
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// ��������(��������)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// �Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}
////�������н����������~Time()
////��main�����и���û��ֱ�Ӵ���Time��Ķ���Ϊʲô�������Time�������������
////��Ϊ��main�����д�����Date����d����d�а���4����Ա����������_year, _month,_day������
////�������ͳ�Ա������ʱ����Ҫ��Դ�������ϵͳֱ�ӽ����ڴ���ռ��ɣ���_t��Time�����������
////d����ʱ��Ҫ�����ڲ�������Time���_t�������٣�����Ҫ����Time����������������ǣ�main����
////�в���ֱ�ӵ���Time�������������ʵ��Ҫ�ͷŵ���Date��������Ա����������Date���������
////������Dateû����ʽ�ṩ������������Date������һ��Ĭ�ϵ�����������Ŀ���������ڲ�����Time
////�����������������Date��������ʱ��Ҫ��֤���ڲ�ÿ���Զ�����󶼿�����ȷ����
////main�����в�û��ֱ�ӵ���Time������������������ʽ���ñ�����ΪDate�����ɵ�Ĭ����������
////ע�⣺�����ĸ���Ķ�������ø�������������������Ǹ���Ķ�������ø������������


//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	 Date(const Date& d) // ��ȷд��
//	Date(const Date& d) // ����д�������뱨������������ݹ�
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1;
//	}
//	Time(const Time& t)
//	{
//		_hour = t._hour;
//		_minute = t._minute;
//		_second = t._second;
//		cout << "Time::Time(const Time&)" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// ��������(��������)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// �Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	// ���Ѿ����ڵ�d1��������d2���˴������Date��Ŀ������캯��
//	// ��Date�ಢû����ʽ���忽�����캯��������������Date������һ��Ĭ�ϵĿ������캯��
//	Date d2(d1);
//	return 0;
//}

// ����ᷢ������ĳ������������������Ҫ�����Ժ󽲵����ȥ�����
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc����ռ�ʧ��");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2(s1);
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int minute, int day)
//	{
//		cout << "Date(int,int,int):" << this << endl;
//	}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d):" << this << endl;
//	}
//	~Date()
//	{
//		cout << "~Date():" << this << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//Date Test(Date d)
//{
//	Date temp(d);
//	return temp;
//}
//int main()
//{
//	Date d1(2022, 1, 13);
//	Test(d1);
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 2023, int month = 2, int day = 3)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "��";
//		cout << _month << "��";
//		cout << _day << "��";
//		cout << endl;
//	}
//	Date Add(int x)
//	{
//		Date ret = *this;
//		ret._day += x;
//		while (ret._day > GetMonthDay(ret._year, ret._month))
//		{
//			//��λ
//			ret._day -= GetMonthDay(ret._year, ret._month);
//			++ret._month;
//			if (ret._month == 13)
//			{
//				ret._year++;
//				ret._month = 1;
//			}
//		}
//
//		return ret;
//	}
//
//	Date& AddEqual(int x)
//	{
//	
//		_day += x;
//		while (_day > GetMonthDay(_year, _month))
//		{
//			//��λ
//			_day -= GetMonthDay(_year, _month);
//			++_month;
//			if (_month == 13)
//			{
//				_year++;
//				_month = 1;
//			}
//		}
//		
//		return *this;
//	}
//
//	
//	int GetMonthDay(int year, int month)
//	{
//		assert(month > 0 && month < 13);
//		int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		{
//			return 29;
//		}
//		else
//		{
//			return monthArray[month];
//		}
//		
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2023, 2, 3);
//	Date d2 = d1.Add(100);
//	Date d3 = d1.AddEqual(150);
//
//	d1.Print();
//	d2.Print();
//	d3.Print();
//
//
//};


//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		cout << "Stack(size_t capacity = 10)" << endl;
//
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc����ռ�ʧ��");
//			exit(-1);
//		}
//
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	Stack(const Stack& st)
//	{
//		cout << "Stack(const Stack& st)" << endl;
//		_array = (DataType*)malloc(sizeof(DataType)*st._capacity);
//		if (nullptr == _array)
//		{
//			perror("malloc����ռ�ʧ��");
//			exit(-1);
//		}
//
//		memcpy(_array, st._array, sizeof(DataType)*st._size);
//		_size = st._size;
//		_capacity = st._capacity;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	DataType *_array;
//	size_t    _size;
//	size_t    _capacity;
//};
//
//class MyQueue
//{
//public:
//	// Ĭ�����ɹ���
//	// Ĭ����������
//	// Ĭ�����ɿ�������
//
//private:
//	Stack _pushST;
//	Stack _popST;
//	int _size = 0;
//};
//
//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(4);
//
//	Stack st2(st1);
//	cout << "=============================" << endl;
//
//	MyQueue q1;
//	MyQueue q2(q1);
//
//
//	return 0;
//}

// ȫ�ֵ�operator==
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//    //private:
//	int _year;
//	int _month;
//	int _day;
//};
//// ����ᷢ����������س�ȫ�ֵľ���Ҫ��Ա�����ǹ��еģ���ô�������ˣ���װ����α�֤��
//// ������ʵ���������Ǻ���ѧϰ����Ԫ��������߸ɴ����سɳ�Ա������
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "��" << _month << "��" << _day << "��" << endl;
//	}
//	// bool operator==(Date* this, const Date& d2)
//	// ������Ҫע����ǣ����������this��
//	bool operator==(const Date& d2)
//	{
//		return _year == d2._year
//		&& _month == d2._month
//			&& _day == d2._day;
//	}
//
//	bool operator<(const Date& d2)
//	{
//		if (_year > d2._year)
//			return false;
//		else if (_year == d2._year && _month > d2._month)
//			return false;
//		else if (_year == d2._year && _month == d2._month && _day > d2._day)
//			return false;
//		else 
//			return true;
//	}
//
//	bool operator>(const Date& d2)
//	{
//		return !(*this < d2 && *this == d2);
//	}
//	
//	bool operator!=(const Date& d2)
//	{
//		return !(*this == d2);
//	}
//
//	// d3 = d2 = d1;
//	// ����ֵΪ��֧��������ֵ�����������������
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			this->_year = d._year;
//			this->_month = d._month;
//			this->_day = d._day;
//		}
//		
//		return *this;
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	d1 = d2;
//	d1.Print();
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	int _year;
//	int _month;
//	int _day;
//};
//// ��ֵ��������س�ȫ�ֺ�����ע�����س�ȫ�ֺ���ʱû��thisָ���ˣ���Ҫ����������
//Date& operator=(Date& left, const Date& right)
//{
//	if (&left != &right)
//	{
//		left._year = right._year;
//		left._month = right._month;
//		left._day = right._day;
//	}
//	return left;
//}
//// ����ʧ�ܣ�
//// error C2801: ��operator =�������ǷǾ�̬��Ա


//Date d1(2024, 2, 4);
//Date d2(2023, 3, 4);
//Date d3(2025, 3, 4);
//
//
//d3 = d2 = d1; // ��ֵ����
//
//Date d5 = d1; // ��������
//Date d6(d1); // �������� 

//class Time
//{
//public:
//	Time()
//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1;
//	}
//	Time& operator=(const Time& t)
//	{
//		if (this != &t)
//		{
//			_hour = t._hour;
//			_minute = t._minute;
//			_second = t._second;
//		}
//		return *this;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// ��������(��������)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// �Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	Date d2;
//	d1 = d2;
//	return 0;
//}

// ����ᷢ������ĳ������������������Ҫ�����Ժ󽲵����ȥ�����
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc����ռ�ʧ��");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2;
//	s2 = s1;
//	return 0;
//}
#include "Date.h"


void TestDate1()
{
	Date d1(2023, 2, 20);
	Date d2 = d1 + 100;
	//d2 += 100;
	d1.Print();
	d2.Print();

}

int main()
{
	TestDate1();
}