#pragma once
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

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
		//��������
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

			//�������ӳ���0.7������
			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
			{
				//1.��Ϊ�գ�������ȥ

				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newht;
				newht._tables.resize(newsize);
				//�����ɱ�����ӳ�䵽�¶���
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

			// ����̽��
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

		//��������
		HashData<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			size_t hashi = key % _tables.size();

			//����̽��
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

				//����Ѿ�����һȦ����ô˵��ȫ�Ǵ���+ɾ��
				if (index == hashi)
				{
					break;
				}
			}


		}

		//ɾ������
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
		size_t _n = 0; //�洢���ݵĸ���
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
	template<class K, class V>
	struct HashNode
	{
		HashNode<K, V>* _next;
		pair<K, V> _kv;

		HashNode(const pair<K, V>& kv)
		
			:_next(nullptr)
			,_kv(kv)
		
		{}
	};

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

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:

		//��������
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

		//��������
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}

			Hash hash;

			//�������� == 1ʱ����
			if (_n == _tables.size())
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;

				vector<Node*> newtables(newsize, nullptr);
				for (auto& cur : _tables)
				{
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = hash(cur->_kv.first) % newtables.size();

						//ͷ��
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;
						cur = next;
					}
				}

				_tables.swap(newtables);
			}


			size_t hashi = hash(kv.first) % _tables.size();
			//ͷ��
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return true;
		}

		//��������
		Node* Find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;
			
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}

				cur = cur->_next;
			}

			return nullptr;
		}

		//ɾ������
		bool Erase(const K& key)
		{
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (cur->_kv.first == key)
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

		//�������������
		void MaxBucketSize()
		{
			size_t max = 0;
			for (size_t i = 0;i < _tables.size();++i)
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
		vector<Node*> _tables;//ָ������

		size_t _n = 0;//�洢��Ч���ݵĸ���
	};



	void TestHashTable1()
	{
		int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
		
		ht.Insert(make_pair(15, 15));
		ht.Insert(make_pair(25, 25));
		ht.Insert(make_pair(35, 35));
		ht.Insert(make_pair(45, 45));

	}

	void TestHashTable2()
	{
		int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Erase(12);
		ht.Erase(3);

	}

	void TestHashTable3()
	{
	
		HashTable<string, string> ht;
		ht.Insert(make_pair("sort", "����"));
		ht.Insert(make_pair("left", "���"));
		ht.Insert(make_pair("right", "�ұ�"));
		HashFunc<string> hashstr;
		cout << hashstr("abcd") << endl;
		cout << hashstr("dcba") << endl;
		cout << hashstr("aadd") << endl;
		cout << hashstr("eat") << endl;
		cout << hashstr("ate") << endl;

	}

	void TestHashTable4()
	{
		size_t N = 20000;
		HashTable<int, int> ht;
		srand(time(0));
		for (size_t i = 0; i < N; ++i)
		{
			size_t x = rand();
			ht.Insert(make_pair(x, x));
		}

		ht.MaxBucketSize();
	}
}