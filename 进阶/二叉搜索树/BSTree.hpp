#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace yyf
{
	template <class K>
	struct BSTreeNode//�������ڵ�
	{
		BSTreeNode(const K& key)
			:left(nullptr)
			, right(nullptr)
			, _key(key)
		{}


		BSTreeNode<K>* left;
		BSTreeNode<K>* right;
		K _key;
	};


	template <class K>
	struct BSTree//����������
	{
		typedef BSTreeNode<K> Node;

		BSTree()
			:_root(nullptr)
		{}

		~BSTree()//����
		{
			Destroy(_root);
			_root = nullptr;
		}

		void Destroy(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}

		//����
		bool insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);

			}
			else
			{
				Node* parent = nullptr;
				Node* cur = _root;
				//cur->һֱ�ߣ��ߵ�Ҫ�����λ��
				while (cur)
				{
					parent = cur;
					if (cur->_key > key)
					{
						cur = cur->left;
					}
					else if (cur->_key < key)
					{
						cur = cur->right;
					}
					else
						return false;//˵�������ظ�������ʧ��
				}

				cur = new Node(key);
				//�жϽڵ����parent�ڵ������������������
				if (parent->_key < key)
				{
					parent->right = cur;
				}
				else
				{
					parent->left = cur;
				}

			}

			return true;
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (root->_key > key)
			{
				return _InsertR(root->left, key);
			}
			else if(root->_key < key)
			{
				return _InsertR(root->right, key);
			}
			else
				return false;

		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		//�������
		void _InOrder(const Node* _root)
		{
			if (_root == nullptr)
				return;
			_InOrder(_root->left);
			cout << _root->_key << " ";
			_InOrder(_root->right);

		}

		void InOrder()
		{
			_InOrder(_root);
		}

		//����
		bool Find(const K& key)
		{
			Node* cur = _root;
			if (cur == nullptr)
			{
				return false;
			}
			else if (cur->_key < key)
			{
				cur = cur->right;
			}
			else if (cur->_key > key)
			{
				cur = cur->left;
			}
			else
				return true;
		}

		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
				return nullptr;

			if (root->_key > key)
			{
				return _FindR(root->left, key);
			}
			else if (root->_key < key)
			{
				return _FindR(root->right, key);
			}
			else
				return root;
		}

		bool FindR(const K& key)
		{
			return _FindR(_root, key) == nullptr ? false : true;
		}

		//ɾ��
		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			
			while (cur)
			{//�ҵ�Ҫɾ���Ľڵ�
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->left;
				}
				else//˵���ҵ���Ҫɾ���Ľڵ���
				{
					if (cur->left == nullptr)
					{//��ɾ���ڵ�����Ϊ�գ��Һ��Ӳ�Ϊ��
						if (cur == _root)
						{
							_root = _root->right;
						}
						else
						{
							if (parent->left == cur)
							{
								parent->left = cur->right;
							}
							else
							{
								parent->right = cur->right;
							}	
						}
						delete cur;
					}
					else if (cur->right == nullptr)
					{//��ɾ���ڵ��Һ���Ϊ�գ����Ӳ�Ϊ��
						if (cur == _root)
						{
							_root = _root->left;
						}
						else
						{
							if (parent->left == cur)
							{
								parent->left = cur->left;
							}
							else
							{
								parent->right = cur->left;
							}
						}
						delete cur;
					}
					else
					{//��ɾ���Ľڵ����Һ��Ӿ���Ϊ��
						Node* rightMin = cur->right;
						Node* rightMinParent = cur;
						while (rightMin->left != nullptr)
						{
							rightMinParent = rightMin;
							rightMin = rightMin->left;
						}
						cur->_key = rightMin->_key;
						if (rightMinParent->left == rightMin)
							rightMinParent->left == rightMin->right;
						else if (rightMinParent->right == rightMin)
							rightMinParent->right == rightMin->right;
						delete rightMin;
					}

					return true;
				}
				
			}
			return false;
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key > key)
			{
				_EraseR(root->left, key);
			}
			else if (root->_key < key)
			{
				_EraseR(root->right, key);
			}
			else
			{
				Node* del = root;
				if (root->left == nullptr)
				{
					root = root->right;
				}
				else if (root->right == nullptr)
				{
					root = root->left;
				}
				else
				{
					Node* rightMin = root->right;
					while (rightMin->left != nullptr)
					{
						rightMin = rightMin->left;
					}
					root->_key = rightMin->_key;
					return _EraseR(root->right, rightMin->_key);
				}

				delete del;
				return true;
			}

		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:
		Node* _root;
	};

}

namespace _K_V
{
	template <class K, class V>
	struct BSTreeNode//�������ڵ�
	{
		BSTreeNode(const K& key, const V& value)
			:left(nullptr)
			, right(nullptr)
			, _key(key)
			, _value(value)
		{}


		BSTreeNode<K, V>* left;
		BSTreeNode<K, V>* right;
		K _key;
		V _value;
	};


	template <class K, class V>
	struct BSTree//���������� _K_V
	{
		typedef BSTreeNode<K, V> Node;

		BSTree()
			:_root(nullptr)
		{}

		//����
		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);

			}
			else
			{
				Node* parent = nullptr;
				Node* cur = _root;
				//cur->һֱ�ߣ��ߵ�Ҫ�����λ��
				while (cur)
				{
					parent = cur;
					if (cur->_key > key)
					{
						cur = cur->left;
					}
					else if (cur->_key < key)
					{
						cur = cur->right;
					}
					else
						return false;//˵�������ظ�������ʧ��
				}

				cur = new Node(key, value);
				//�жϽڵ����parent�ڵ������������������
				if (parent->_key < key)
				{
					parent->right = cur;
				}
				else
				{
					parent->left = cur;
				}

			}

			return true;
		}

		bool _InsertR(Node*& root, const K& key, const V& value)
		{
			if (root == nullptr)
			{
				root = new Node(key, value);
				return true;
			}

			if (root->_key > key)
			{
				return _InsertR(root->left, key);
			}
			else if (root->_key < key)
			{
				return _InsertR(root->right, key);
			}
			else
				return false;

		}

		bool InsertR(const K& key, const V& value)
		{
			return _InsertR(_root, key, value);
		}

		//�������
		void _InOrder(const Node* _root)
		{
			if (_root == nullptr)
				return;
			_InOrder(_root->left);
			cout << _root->_key << ":" << _root->_value << endl;;
			_InOrder(_root->right);

		}

		void InOrder()
		{
			_InOrder(_root);
		}

		//����
		Node* Find(const K& key)
		{
			Node* cur = _root;

			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->right;
				}
				else if (cur->_key > key)
				{
					cur = cur->left;
				}
				else
					return cur;
			}

			return nullptr;
			
		}

		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
				return nullptr;

			if (root->_key > key)
			{
				return _FindR(root->left, key);
			}
			else if (root->_key < key)
			{
				return _FindR(root->right, key);
			}
			else
				return root;
		}

		bool FindR(const K& key)
		{
			return _FindR(_root, key) == nullptr ? false : true;
		}

		//ɾ��
		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{//�ҵ�Ҫɾ���Ľڵ�
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->left;
				}
				else//˵���ҵ���Ҫɾ���Ľڵ���
				{
					if (cur->left == nullptr)
					{//��ɾ���ڵ�����Ϊ�գ��Һ��Ӳ�Ϊ��
						if (cur == _root)
						{
							_root = _root->right;
						}
						else
						{
							if (parent->left == cur)
							{
								parent->left = cur->right;
							}
							else
							{
								parent->right = cur->right;
							}
						}
						delete cur;
					}
					else if (cur->right == nullptr)
					{//��ɾ���ڵ��Һ���Ϊ�գ����Ӳ�Ϊ��
						if (cur == _root)
						{
							_root = _root->left;
						}
						else
						{
							if (parent->left == cur)
							{
								parent->left = cur->left;
							}
							else
							{
								parent->right = cur->left;
							}
						}
						delete cur;
					}
					else
					{//��ɾ���Ľڵ����Һ��Ӿ���Ϊ��
						Node* rightMin = cur->right;
						Node* rightMinParent = cur;
						while (rightMin->left != nullptr)
						{
							rightMinParent = rightMin;
							rightMin = rightMin->left;
						}
						cur->_key = rightMin->_key;
						if (rightMinParent->left == rightMin)
							rightMinParent->left == rightMin->right;
						else if (rightMinParent->right == rightMin)
							rightMinParent->right == rightMin->right;
						delete rightMin;
					}

					return true;
				}

			}
			return false;
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key > key)
			{
				_EraseR(root->left, key);
			}
			else if (root->_key < key)
			{
				_EraseR(root->right, key);
			}
			else
			{
				Node* del = root;
				if (root->left == nullptr)
				{
					root = root->right;
				}
				else if (root->right == nullptr)
				{
					root = root->left;
				}
				else
				{
					Node* rightMin = root->right;
					while (rightMin->left != nullptr)
					{
						rightMin = rightMin->left;
					}
					root->_key = rightMin->_key;
					return _EraseR(root->right, rightMin->_key);
				}

				delete del;
				return true;
			}

		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:
		Node* _root;
	};
}

void TestBSTree3()
{
	_K_V::BSTree<string, string> t1;
	t1.Insert("sort", "����");
	t1.Insert("left", "���");
	t1.Insert("right", "�ұ�");
	t1.Insert("string", "�ַ���");

	string str;
	while (cin >> str)
	{
		auto ret = t1.Find(str);
		if (ret)
		{
			cout << ":" << ret->_value << endl;
		}
		else
		{
			cout << "�޴˵���" << endl;
		}
	}
}

void TestBSTree4()
{
	// ͳ��ˮ�����ֵĴ���
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
	"ƻ��", "�㽶", "ƻ��", "�㽶" };
	_K_V::BSTree<string, int> countTree;
	for (const auto& str : arr)
	{
		// �Ȳ���ˮ���ڲ�����������
		// 1�����ڣ�˵��ˮ����һ�γ��֣������<ˮ��, 1>
		// 2���ڣ�����ҵ��Ľڵ���ˮ����Ӧ�Ĵ���++
		//BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
}