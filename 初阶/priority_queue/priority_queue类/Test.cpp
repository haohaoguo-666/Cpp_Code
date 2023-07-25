#include <iostream>
#include <queue>
#include <functional>
 
using namespace std;

void test_priority_queue()
{
	//Ĭ���Ǵ�� -- ������ȼ���
	//priority_queue<int> pq;
	//greater<int> �º���/�������� 
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(1);
	pq.push(0);
	pq.push(5);
	pq.push(2);
	pq.push(1);
	pq.push(7);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	} 
	cout << endl;
}

template< class T>
struct Less
{
	bool operator()(const T& x,const T& y)
	{
		return x < y;
	}
};

int main()
{
	test_priority_queue();

	Less<int> lessFunc;

	cout << lessFunc(1, 2) << endl;
	return 0;
}