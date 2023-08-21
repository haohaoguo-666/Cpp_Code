#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

// 节点的颜色
enum Color { RED, BLACK };
// 红黑树节点的定义
template<class K, class V>
struct RBTreeNode
{
	RBTreeNode(const pair<K,V>& kv, Color col = RED)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(col)
	{}
	RBTreeNode<K, V>* _left; // 节点的左孩子
	RBTreeNode<K, V>* _right; // 节点的右孩子
	RBTreeNode<K, V>* _parent; // 节点的双亲(红黑树需要旋转，为了实现简单给出该字段)
	pair<K, V> _kv; // 节点的值域
	Color _col; // 节点的颜色
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	//插入节点
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;//根节点为黑色
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);

		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}

		cur->_parent = parent;//链接父节点

		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				
				Node* uncle = grandfather->_right;
				//情况一：叔叔存在且为红色，变色处理，并继续网上处理
				if(uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续向上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				else //情况二+三：u不存在/u存在且为黑，旋转+变色
				{
					if(cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						//parent->_col = RED;
						grandfather->_col = RED;
					}

					break;
				}
			}
			else  // grandfather->_right == parent
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续向上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				else //情况二+三：u不存在/u存在且为黑，旋转+变色
				{
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						//parent->_col = RED;
						grandfather->_col = RED;
					}

					break;
				}
			}
		}

		_root->_col = BLACK;

		return true;
	}

	//中序遍历
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	//检测是否符合红黑树
	bool IsBalance()
	{
		if (_root && _root->_col == RED)
		{
			cout << "根节点颜色是红色" << endl;
			return false;
		}

		//基准值
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++benchmark;
			cur = cur->_left;
		}

		//连续红色节点
		return _Check(_root, 0, benchmark);
	}
	
	//求高度
	int Height()
	{
		return _Height(_root);
	}

	//析构函数
	~RBTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}
private:
	//左旋转
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* ppnode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (ppnode == nullptr)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}

			subR->_parent = ppnode;
		}

		//parent->_bf = subR->_bf = 0;
	}

	//右旋转
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		Node* ppnode = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;



		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subL;
			}
			else
			{
				ppnode->_right = subL;

			}
			subL->_parent = ppnode;
		}

		//parent->_bf = subL->_bf = 0;

	}

	//左右旋转
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		/*if (bf == 1)
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else
		{
			assert(false);
		}*/

	}

	//右左旋转
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		/*if (bf == 1)
		{
			parent->_bf = -1;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
		else
		{
			assert(false);
		}*/
	}

	//中序遍历
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	//检验是否有连续的红色节点以及黑色节点的数量
	bool _Check(Node* root, int blackNum, int benchmark)
	{
		if (root == nullptr)
		{
			if (benchmark != blackNum)
			{
				cout << "某条路径黑色节点的数量不相等" << endl;
				return false;
			}

			return true;
		}

		if (root->_col == BLACK)
		{
			++blackNum;
		}

		if (root->_col == RED
			&& root->_parent
			&& root->_parent->_col == RED)
		{
			cout << "存在连续的红色节点" << endl;
			return false;
		}

		return _Check(root->_left, blackNum, benchmark)
			&& _Check(root->_right, blackNum, benchmark);
	}

	//树的高度
	int _Height(Node* root)
	{
		if (root == NULL)
			return 0;

		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);

		return leftH > rightH ? leftH + 1 : rightH + 1;
	}

	//删除树
	void _Destroy(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}

	//查找
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}

private:
	Node* _root = nullptr;
};


void Test_RBTree1()
{//测试代码1
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RBTree<int, int> t1;
	for (auto e : a)
	{
		t1.Insert(make_pair(e, e));
		//cout << e << ":" << t1.IsBalance() << endl;
	}

	t1.InOrder();
	//cout << t1.IsBalance() << endl;
}

void Test_RBTree2()
{//测试代码2
	srand(time(0));
	const size_t N = 50000;
	RBTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand() + i;
		t.Insert(make_pair(x, x));
		//cout << t.IsBalance() << endl;
	}

	//t.Inorder();

	cout << t.IsBalance() << endl;
	cout << t.Height() << endl;
}