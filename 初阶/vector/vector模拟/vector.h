#pragma once
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

namespace yyf
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		//Iterators（迭代器）
		iterator begin()
		{
			return _start;
		}

		const iterator begin() const
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const iterator end() const
		{
			return _finish;
		}
		
		//Member functions
		//构造函数
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{

		}

		//析构函数
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		
		vector(size_t n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{	//const T& val = T()就是创建了一个匿名对象，通过构造函数，然后再引用
			//匿名对象生命周期只在当前一行，因为这行之后就没人会用它了
			//const引用会延长匿名对象的生命周期到引用对象域结束，因为引用就是起别名，就是这个匿名对象
			//匿名对象和临时对象具有常性
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}

		}

		vector(int n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{	//const T& val = T()就是创建了一个匿名对象，通过构造函数，然后再引用
			//匿名对象生命周期只在当前一行，因为这行之后就没人会用它了
			//const引用会延长匿名对象的生命周期到引用对象域结束，因为引用就是起别名，就是这个匿名对象
			//匿名对象和临时对象具有常性
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}

		}

		//[first, last)
		template <class InputIterator>//允许类的成员函数再是函数模板
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}


		//capacity（容量）
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//提前记录size
				size_t sz = size();
				T* tmp = new T[n];
				//开新空间
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());
					//拷贝旧数据
					delete[] _start;
				}
				_start = tmp;
				_finish = tmp + sz;
				_end_of_storage = tmp + n;

			}
		}

		void resize(size_t n, T val = T())//任意类型都有默认构造函数
		{
			if (n < size())
			{
				//删除数据
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
					reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		bool empty()
		{
			return _start == _finish;
		}

		//Modifiers（修改器）
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{//扩容
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(empty());
			--_finish;
		}

		void insert(iterator pos, const T& val)
		{//不能用引用来传入拷贝的临时对象，因为其具有常性
			assert(pos <= _finish);
			assert(pos >= _start);

			if (_finish == _end_of_storage)
			{//扩容
				size_t  len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);

				//扩容后更新，解决pos失效问题
				pos = _start + len; 
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;

			//insert以后我们认为pos失效了，不能再使用
			//return pos;

		}

		iterator erase(iterator pos)
		{
			assert(pos <= _finish);
			assert(pos >= _start);

			iterator start = pos + 1;
			while(start != _finish)
			{
				*(start - 1) = *start;
				++start;
			}
			--_finish;


			return pos;
			//erase以后我们认为pos失效了，不能再使用
		}


		//Element access（元素存取）

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;

	};


	void test_vector1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);


		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();


		for (auto ch : v1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	template<class T>
	void f()
	{
		T x = T();//调用默认构造
		cout << x << endl;
	}

	void test_vector2()
	{
		//内置类型有没有构造函数
		int i = int();
		int j = int(1);
		
		//int* p = int* ();

		f<int>();
		f<int*>();
		f<double>();
	}

	void test_vector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		v1.resize(10);

		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;
		
		v1.resize(3);

		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

	}


	void test_vector4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v1.begin();
		v1.insert(it, 10);
		v1.insert(it + 6, 6);

		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		(*it)++;

		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;


	}

	void test_vector5()
	{
		std::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		auto pos = find(v1.begin(), v1.end(), 2);

		if (pos != v1.end())
		{
			v1.erase(pos);
		}
		(*pos)++;
		//vs下std的pos失效了，不能访问并且进行强制检查

		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

	}

	void test_vector6()
	{
		yyf::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		// 要求删除所有的偶数
		yyf::vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			if (*it % 2 == 0)
			{
				it = v1.erase(it);//std的erase会指向删除数据的后一个数据的位置
			}
			else
			{
				++it;
			}
		}

		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;
	}

	void test_vector6()
	{
		yyf::vector<int> v(10, 5);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}


}