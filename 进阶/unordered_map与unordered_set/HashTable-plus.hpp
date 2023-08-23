#pragma once
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

//提取key(整型）
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

template<>
struct HashFunc<string>
{
	//BKDR
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
			hash *= 31;
		}
		return hash;
	}
};

namespace openAddress
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K, class V>
	class HashTable
	{
	public:
		//插入数据
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

			//负载因子超过0.7就扩容
			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
			{
				//1.表为空，扩不上去

				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newht;
				newht._tables.resize(newsize);
				//遍历旧表，重新映射到新对象
				for (auto& data : _tables)
				{
					if (data._state == EXIST)
					{
						newht.Insert(data._kv);
					}
				}

				_tables.swap(newht._tables);
			}
			size_t hashi = kv.first % _tables.size();

			// 线性探测
			size_t i = 1;
			size_t index = hashi;
			while (_tables[index]._state == EXIST)
			{
				index = hashi + i;
				index %= _tables.size();
				++i;
			}
			_tables[index]._kv = kv;
			_tables[index]._state = EXIST;
			_n++;

			return true;
		}

		//查找数据
		HashData<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			size_t hashi = key % _tables.size();

			//线性探测
			size_t i = 1;
			size_t index = hashi;
			while (_tables[index]._state != EMPTY)
			{
				if (_tables[index]._state == EXIST && _tables[index]._kv.first == key)
				{
					return &_tables[index];
				}
				index = hashi + i;
				index %= _tables.size();
				++i;

				//如果已经查找一圈，那么说明全是存在+删除
				if (index == hashi)
				{
					break;
				}
			}


		}

		//删除数据
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0; //存储数据的个数
	};

	void TestHashTable1()
	{
		int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
	}
}

namespace HashBucket
{
	//哈希表节点
	template<class T>
	struct HashNode
	{
		HashNode<T>* _next;
		T _data;

		HashNode(const T& data)

			:_next(nullptr)
			,_data(data)

		{}
	};

	
	//前置说明
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	//迭代器
	template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
	struct __HashIterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef __HashIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self;
		typedef __HashIterator<K, T, T&, T*, KeyOfT, Hash> Iterator;

		Node* _node;
		const HT* _ht;

		//构造
		__HashIterator(Node* node, const HT* ht)
			:_node(node)
			,_ht(ht)
		{}

		//拷贝构造
		__HashIterator(const Iterator& it)
			:_node(it._node)
			,_ht(it._ht)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
		
		//++it
		Self& operator++()
		{	
			//若不处于当前桶的结尾位置，则继续寻找当前位置的下一个位置
			if (_node->_next != nullptr)
			{
				_node = _node->_next;
			}
			else
			{
				//找下一个不为空的桶
				KeyOfT kot;
				Hash hash;
				//算出我当前的桶的位置
				size_t hashi = hash(kot(_node->_data)) % _ht->_tables.size();
				++hashi;
				while (hashi < _ht->_tables.size())
				{
					if (_ht->_tables[hashi])
					{
						_node = _ht->_tables[hashi];
						break;
					}
					else
					{
						++hashi;
					}
				}

				if (hashi == _ht->_tables.size())
				{
					_node = nullptr;
				}

			}

			return *this;
		}
	};

	//哈希表
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
		template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
		friend struct __HashIterator;

		typedef HashNode<T> Node;

	public:

		//迭代器
		typedef __HashIterator<K, T, T&, T*, KeyOfT, Hash> iterator;
		typedef __HashIterator<K, T, const T&, const T*, KeyOfT, Hash> const_iterator;


		iterator begin()
		{
			Node* cur = nullptr;
			for(size_t i = 0; i < _tables.size(); ++i)
			{
				cur = _tables[i];
				if (cur)
				{
					break;
				}
			}
			return iterator(cur, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		const_iterator begin() const
		{
			Node* cur = nullptr;
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				cur = _tables[i];
				if (cur)
				{
					break;
				}
			}
			return const_iterator(cur, this);
		}

		const_iterator end() const
		{
			return const_iterator(nullptr, this);
		}

		//析构函数
		~HashTable()
		{
			for (auto cur : _tables)
			{
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				cur = nullptr;
			}
		}

		//插入数据
		pair<iterator,bool> Insert(const T& data)
		{
			KeyOfT kot;
			iterator it = Find(kot(data));
			if(it != end()) 
			{
				return make_pair(it, false);
			}

			Hash hash;

			//负载因子 == 1时扩容
			if (_n == _tables.size())
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;

				vector<Node*> newtables(newsize, nullptr);
				for (auto& cur : _tables)
				{
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = hash(kot(cur->_data)) % newtables.size();

						//头插到新表
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;
						cur = next;
					}
				}

				_tables.swap(newtables);
			}


			size_t hashi = hash(kot(data)) % _tables.size();
			//头插
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return make_pair(iterator(newnode, this), false);
		}

		//查找数据
		iterator Find(const K& key)
		{
			if (_tables.size() == 0)
				return end();

			KeyOfT kot; 
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur, this);
				}

				cur = cur->_next;
			}

			return end();
		}

		//删除数据
		bool Erase(const K& key)
		{
			Hash hash;
			KeyOfT kot;
			size_t hashi = hash(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;

					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
		}

		void MaxBucketSize()
		{
			size_t max = 0;
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				auto cur = _tables[i];
				size_t size = 0;
				while (cur)
				{
					++size;
					cur = cur->_next;
				}

				printf("[%d]->%d\n", i, size);

				if (max < size)
				{
					max = size;
				}
			}

			printf("%d", max);
		}

	private:
		vector<Node*> _tables;//指针数组

		size_t _n = 0;//存储有效数据的个数
	};

}