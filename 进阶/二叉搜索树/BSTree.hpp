#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace yyf
{
	template <class K>
	struct BSTreeNode//二叉树节点
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
	struct BSTree//二叉搜索树
	{
		typedef BSTreeNode<K> Node;

		BSTree()
			:_root(nullptr)
		{}

		~BSTree()//析构
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

		//插入
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
				//cur->一直走，走到要插入的位置
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
						return false;//说明数字重复，插入失败
				}

				cur = new Node(key);
				//判断节点放在parent节点的左子树还是右子树
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

		//中序遍历
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

		//查找
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

		//删除
		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			
			while (cur)
			{//找到要删除的节点
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
				else//说明找到了要删除的节点了
				{
					if (cur->left == nullptr)
					{//被删除节点左孩子为空，右孩子不为空
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
					{//被删除节点右孩子为空，左孩子不为空
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
					{//被删除的节点左右孩子均不为空
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
	struct BSTreeNode//二叉树节点
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
	struct BSTree//二叉搜索树 _K_V
	{
		typedef BSTreeNode<K, V> Node;

		BSTree()
			:_root(nullptr)
		{}

		//插入
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
				//cur->一直走，走到要插入的位置
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
						return false;//说明数字重复，插入失败
				}

				cur = new Node(key, value);
				//判断节点放在parent节点的左子树还是右子树
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

		//中序遍历
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

		//查找
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

		//删除
		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{//找到要删除的节点
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
				else//说明找到了要删除的节点了
				{
					if (cur->left == nullptr)
					{//被删除节点左孩子为空，右孩子不为空
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
					{//被删除节点右孩子为空，左孩子不为空
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
					{//被删除的节点左右孩子均不为空
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
	t1.Insert("sort", "排序");
	t1.Insert("left", "左边");
	t1.Insert("right", "右边");
	t1.Insert("string", "字符串");

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
			cout << "无此单词" << endl;
		}
	}
}

void TestBSTree4()
{
	// 统计水果出现的次数
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
	"苹果", "香蕉", "苹果", "香蕉" };
	_K_V::BSTree<string, int> countTree;
	for (const auto& str : arr)
	{
		// 先查找水果在不在搜索树中
		// 1、不在，说明水果第一次出现，则插入<水果, 1>
		// 2、在，则查找到的节点中水果对应的次数++
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