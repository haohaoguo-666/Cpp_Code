#pragma once
#include <cassert>
#include <iostream>
#include <time.h>

using namespace std;

template <class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	int _bf;//平衡因子

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	//插入节点
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
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

		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			if (parent->_bf == 1 || parent->_bf == -1)
			{
				//继续更新
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//旋转的原则：保持它继续是搜索树
				//选择的目的：左右均衡，降低整棵树的高度
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if(parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else
				{
					assert(false);
				}

				break;
			}
			else
			{
				assert(false);
			}

		}

		return true;
	}

	//中序遍历
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	//判断是否是平衡二叉树
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
	

private:
	//求树的高度
	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);

		return leftH > rightH ? leftH + 1 : rightH + 1;
	}

	//判断是否是平衡树
	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);

		//判断平衡因子
		if (rightH - leftH != root->_bf)
		{
			cout << root->_kv.first << "节点平衡因子异常" << endl;
			return false;
		}

		return abs(leftH - rightH) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);

	}

	//左旋转
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if(subRL)
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

		parent->_bf = subR->_bf = 0;
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

		parent->_bf = subL->_bf = 0;

	}

	//左右旋转
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 1)
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
		}
			 
	}

	//右左旋转
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 1)
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
		}
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


private:
	Node* _root = nullptr;
};

void Test_AVLTree1()
{//测试代码1
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t1;
	for (auto e : a)
	{
		t1.Insert(make_pair(e, e));
		cout << e << ":" << t1.IsBalance() << endl;
	}

	t1.InOrder();
	cout << t1.IsBalance() << endl;
}

void Test_AVLTree2()
{//测试代码2
	srand(time(0));
	const size_t N = 5000000;
	AVLTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand() + i;
		t.Insert(make_pair(x, x));
		//cout << t.IsBalance() << endl;
	}

	//t.Inorder();

	cout << t.IsBalance() << endl;
	//cout << t.Height() << endl;
}
