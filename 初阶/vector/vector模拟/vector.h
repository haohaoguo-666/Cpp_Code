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

		//Iterators����������
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
		//���캯��
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{

		}

		//��������
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		
		vector(size_t n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{	//const T& val = T()���Ǵ�����һ����������ͨ�����캯����Ȼ��������
			//����������������ֻ�ڵ�ǰһ�У���Ϊ����֮���û�˻�������
			//const���û��ӳ�����������������ڵ����ö������������Ϊ���þ�������������������������
			//�����������ʱ������г���
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
		{	//const T& val = T()���Ǵ�����һ����������ͨ�����캯����Ȼ��������
			//����������������ֻ�ڵ�ǰһ�У���Ϊ����֮���û�˻�������
			//const���û��ӳ�����������������ڵ����ö������������Ϊ���þ�������������������������
			//�����������ʱ������г���
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}

		}

		//[first, last)
		template <class InputIterator>//������ĳ�Ա�������Ǻ���ģ��
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


		//capacity��������
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//��ǰ��¼size
				size_t sz = size();
				T* tmp = new T[n];
				//���¿ռ�
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());
					//����������
					delete[] _start;
				}
				_start = tmp;
				_finish = tmp + sz;
				_end_of_storage = tmp + n;

			}
		}

		void resize(size_t n, T val = T())//�������Ͷ���Ĭ�Ϲ��캯��
		{
			if (n < size())
			{
				//ɾ������
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

		//Modifiers���޸�����
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{//����
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
		{//���������������뿽������ʱ������Ϊ����г���
			assert(pos <= _finish);
			assert(pos >= _start);

			if (_finish == _end_of_storage)
			{//����
				size_t  len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);

				//���ݺ���£����posʧЧ����
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

			//insert�Ժ�������ΪposʧЧ�ˣ�������ʹ��
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
			//erase�Ժ�������ΪposʧЧ�ˣ�������ʹ��
		}


		//Element access��Ԫ�ش�ȡ��

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
		T x = T();//����Ĭ�Ϲ���
		cout << x << endl;
	}

	void test_vector2()
	{
		//����������û�й��캯��
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
		//vs��std��posʧЧ�ˣ����ܷ��ʲ��ҽ���ǿ�Ƽ��

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

		// Ҫ��ɾ�����е�ż��
		yyf::vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			if (*it % 2 == 0)
			{
				it = v1.erase(it);//std��erase��ָ��ɾ�����ݵĺ�һ�����ݵ�λ��
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