#pragma once
#include <string.h>
#include <iostream>
#include <assert.h>
using namespace std;

namespace yyf
{
	class string
	{
	public:
		//迭代器
		typedef char* iterator;
		typedef const char* const_iterator;


		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		/*string()
			:_str(new char[1])
			, _size(0)
			, _capacity(0)
		{
			_str[0] = '\0'; 
		}*/

		//string(const char* str = nullptr)
		//string(const char* str = '\0')
		//string(const char* str = "\0")
		string(const char* str = "")
			//string类全缺省构造函数
			:_size(strlen(str))
		{
			_capacity = _size == 0 ? 3 : _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s)
			//拷贝构造函数
			:_size(s._size)
			,_capacity(s._capacity)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
		}
		
		string& operator=(const string& s)
		{//赋值重载

			if (this != &s)
			{//避免自己给自己赋值

				char* tmp = new char(s._capacity + 1);
				strcpy(tmp, s._str);

				delete[] _str;

				_size = s._size;
				_capacity = s._capacity;
				_str = tmp;
				
			}
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];

		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];

		}



		size_t size() const
		{
			return _size;
		}

		const char* c_str()
		{
			return _str;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		//不修改成员变量数据的函数，最好都加上const
		bool operator>(const string& s) const
		{
			return strcmp(_str, s._str) > 0;
		}

		bool operator==(const string& s) const 
		{
			return strcmp(_str, s._str) == 0;
		}
		
		bool operator>=(const string& s) const
		{
			return *this > s || *this == s;
		}
		 
		bool operator<=(const string& s) const
		{
			return !(*this > s);
		}

		bool operator<(const string& s) const
		{
			return !(*this >= s);
		}

		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}

		void resize(size_t n, char ch = '\0')
		{//开空间+初始化
			if (n < _size)
			{
				//删除数据--保留前n个
				_size = n;
				_str[_size] = '\0';
			}
			else if(n > _size)
			{
				if (n > _capacity)
				{//容量不够扩容
					reserve(n);
				}
				//扩大字符串大小，往后填入ch
				size_t i = _size;
				while (i < n)
				{
					_str[i] = ch;
					++i;
				}
				_size = n;
				_str[_size] = '\0';

			}
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{//防止缩容
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
			
		}

		void push_back(char ch)
		{
			/*if (_size + 1>= _capacity)
			{
				reserve(_capacity * 2);
			}
			
			_str[_size] = ch;
			
			++_size;

			_str[_size] = '\0';*/

			insert(_size, ch);
		}



		void append(const char* str)
		{
			//size_t len = strlen(str);
			//if (_size + len > _capacity)
			//{
			//	reserve(_size + len);
			//}
			////strcat(_str, str);//自己找'\0'费时间
			//strcpy(_str + _size, str);
			//_size += len;
			insert(_size, str);
		}

		string& operator += (char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator += (const char* str)
		{
			append(str);
			return *this;
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if(_size + 1 > _capacity)
			{
				reserve(2 * _capacity);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);

			size_t len = strlen(str);
			
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size + len;
			while (end > pos + len - 1)
			{//挪动数据
				_str[end] = _str[end - len];
				--end;
			}
			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}

		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)
			{//len == npos 防止溢出
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len); \
				_size -= len;
			}

			return *this;
		}
		//swap(s1, s2);
		//s1.swap(s2);
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}
		
		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size);

			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);

			//
			char* p = strstr(_str + pos, str);
			if (p == nullptr)
			{
				return npos;
			}
			else
			{
				//除了后一个指针元素外有几个元素，两个地址在内存中间隔多少个指针类型的字节倍数
				return p - _str;
			}
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		
		//static const size_t npos;
		static const size_t npos = -1;
	};

	//const size_t string::npos = -1;

	void Print(const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;

		/*for (auto ch : s)
		{
			cout << ch << " ";
		}
		cout << endl;*/
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	} 

	istream& operator>>(istream& in, string& s)
	{//缓冲区里会放入空格和换行，但是cin/scanf流提取会忽略

		s.clear();
		char ch = in.get();
		char buff[128];
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{//数据满了127个就返回
				buff[127] = '\0';
				s += buff;
				i = 0;
 			}
			ch = in.get();
		}

		if (i != 0)
		{//剩余数据添加
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}



	void test_string1()
	{
		string s1;
		string s2("hello world");
		//cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		string s3(s2);
		cout << s3.c_str() << endl;

		s2[0]++;
		
		//cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;

		s1 = s3;

		cout << s1.c_str() << endl;
		cout << s1.c_str() << endl;
	}

	void test_string3()
	{
		string s1("hello world");
		Print(s1);

		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		for (auto ch : s1)
		{//支持了迭代器，就支持了范围for,相当于把*it 赋值给了ch
			cout << ch << " ";
		}
		cout << endl;
	}

	void test_string4()
	{
		string s1("hello world");
		string s2("hello world");
		string s3("xx");

		cout << (s1 < s2) << endl;
		cout << (s1 == s2) << endl;
		cout << (s1 >= s3) << endl;
	}

	void test_string5()
	{
		string s1("hello");
		string s2("world");

		//s1.push_back(' ');
		s1 += ' ';
		cout << s1.c_str() << endl;
		s1.resize(50);
		//s1.append(s2.c_str());
		s1 += s2.c_str();
		cout << s1.c_str() << endl;

	}

	void test_string6()
	{
		string s1("1111111");
		s1.insert(0, 'x');
		s1.insert(0, "hhhhh");
		cout << s1.c_str() << endl;
	}

	void test_string7()
	{
		string s1("1111111");
		//s1.erase(0, 2);
		//cout << s1.c_str() << endl;
		s1.erase(0);
		cout << s1.c_str() << endl;
	}

	//流插入重载必须实现友元函数？ No
	void test_string8()
	{
		string s1("yyyyyyy");
		s1 += '\0';
		s1 += "xxxxxx";
		cout << s1 << endl;
		cout << s1.c_str() << endl;
	}

	void test_string9()
	{
		string s2;
		cin >> s2;
		cout << s2 << endl;
		cin >> s2;
		cout << s2 << endl;
	}
}