#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

namespace yyf
{
	//ÊÊÅäÆ÷Ä£Ê½/Åä½ÓÆ÷
	template <class T, class Container = deque<int>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		//vector<T> _v
		Container _con;
	};

	void test_stack()
	{
		//stack<int, list<int>> st;
		//stack<int, vector<in>> st;
		stack<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);

		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;

	}
}
