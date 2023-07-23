#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace yyf
{

	//�ڵ���
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;

		//���캯��
		list_node(const T& x = T())
			:_next(nullptr)
			,_prev(nullptr)
			,_data(x)
		{

		}
	};

	//������
	//������Ҫô��ԭ��ָ�룬Ҫô�����Զ������Ͷ�ԭ��ָ��ķ�װ��ģ��ָ�����Ϊ
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{//��������װnode*
		typedef list_node<T> node;
		typedef _list_iterator<T,Ref,Ptr> self;
		node* _node;

		//���캯��
		_list_iterator(node* n)
			:_node(n)
		{

		}
		
		//Iterator
		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{//it->->_a1 => it->_a1
			return &_node->_data;
		}

		self& operator++()
		{
			_node = _node->_next;

			return *this;
		}

		self& operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;

			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;

			return *this;
		}

		self& operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;

			return tmp;
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}
		
		bool operator==(const self& s)
		{
			return _node == s._node;
		}

	};

	//template<class T>
	//struct _list_const_iterator
	//{//��������װnode*
	//	typedef list_node<T> node;
	//	typedef _list_const_iterator<T> self;
	//	node* _node;

	//	//���캯��
	//	_list_const_iterator(node* n)
	//		:_node(n)
	//	{

	//	}

	//	//Iterator
	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}

	//	self& operator++()
	//	{
	//		_node = _node->_next;

	//		return *this;
	//	}

	//	self& operator++(int)
	//	{
	//		self tmp(*this);
	//		_node = _node->_next;

	//		return tmp;
	//	}

	//	self& operator--()
	//	{
	//		_node = _node->_prev;

	//		return *this;
	//	}

	//	self& operator--(int)
	//	{
	//		self tmp(*this);
	//		_node = _node->_prev;

	//		return tmp;
	//	}

	//	bool operator!=(const self& s)
	//	{
	//		return _node != s._node;
	//	}

	//	bool operator==(const self& s)
	//	{
	//		return _node == s._node;
	//	}

	//};
	 
	template<class T>
	class list
	{
		typedef list_node<T> node;

	public:
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;

		//typedef _list_const_iterator<T> const_iterator;

		//Iterator
		iterator begin()
		{
			//iterator it(_head->next);
			//return it;
			return iterator(_head->_next);
		}

		const_iterator begin() const
		{
			//iterator it(_head->next);
			//return it;
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			//iterator it(_head);
			//return it;
			return iterator(_head);
		}

		const_iterator end() const
		{
			//iterator it(_head);
			//return it;
			return const_iterator(_head);
		}

		void empty_init()
		{//�ճ�ʼ��
			//����ͷ�ڵ�
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		//���캯��
		list()
		{
			empty_init();
		}

		//��������
		~list()
		{
			clear();
			//�ͷ�ͷ�ڵ�
			delete _head;
			_head = nullptr;
		}

		//���乹�캯��  
		template <class Iterator>
		list(Iterator first, Iterator last)
		{

			empty_init();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//��������
		
		//��ͳд��
		//list(const list<T>& lt)
		//{
		//	empty_init();
		//	for (auto e : lt)
		//	{
		//		push_back(e);
		//	}
		//}

		//�ִ�д��
		void swap(list<T>& tmp)
		{
			std::swap(_head, tmp._head);
		}


		list(const list<T>& lt)
		{
			empty_init();
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}
		
		//��ֵ����
		//list<T>& operator=(list<T> tmp)
		//{
		//	swap(tmp);
		//	return *this;
		//}




		//Modifiers
		void push_back(const T& x)
		{
			//node* tail = _head->_prev;
			//node* new_node = new node(x);

			//tail->_next = new_node;
			//new_node->_prev = tail;
			//new_node->_next = _head;
			//_head->_prev = new_node;
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;

			node* new_node = new node(x);

			prev->_next = new_node;
			new_node->_prev = prev;
			new_node->_next = cur;
			cur->_prev = new_node; 
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			//ͷ�ڵ㲻��ɾ��
			node* prev = pos._node->_prev;
			node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node;

			//ɾ���ڵ㣬���غ�һ���ڵ������
			return  iterator(next);
		}

		void clear()
		{
			iterator it = begin();
				while(it != end())
				{
					erase(it++);
					//it = erase(it);
				}
		}


		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

	private:
		node* _head;
	};

	void print_list(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//(*it) *= 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list1()
	{

		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;


		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		print_list(lt);
	}

	struct AA
	{
		int _a1;
		int _a2;

		AA(int a1 = 0, int a2 = 0)
			:_a1(a1)
			, _a2(a2)
		{}
	};

	void test_list2()
	{
		list<AA> lt;
		lt.push_back(AA(1, 1));
		lt.push_back(AA(2, 2));
		lt.push_back(AA(3, 3));

		// AA* ptr
		list<AA>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._a1 << ":" << (*it)._a2 << endl;		
			cout << it->_a1 << ":" << it->_a2 << endl;
			cout << it.operator->()->_a1 << ":" << it.operator->()->_a1 << endl;
			++it;
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		auto pos = lt.begin();
		++pos;
		lt.insert(pos, 20);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.push_back(100);
		lt.push_front(1000);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.pop_back();
		lt.pop_front();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.clear();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}


	void test_list5()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt2(lt);

		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt3;
		lt3.push_back(10);
		lt3.push_back(20);
		lt3.push_back(30);

		for (auto e : lt3)
		{
			cout << e << " ";
		}
		cout << endl;

		lt2 = lt3;

		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : lt3)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
