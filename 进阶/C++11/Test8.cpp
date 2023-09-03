#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <assert.h>
#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

int Plus(int a, int b)
{
	return a + b;
}

class Sub
{
public:
	int sub(int a, int b)
	{
		return a - b;
	}
};

int main()
{
	//绑定固定参数
	function<int(int)> func1 = bind(Plus, placeholders::_1, 10);
	cout << func1(2) << endl; //12

	function<int(Sub, int, int)> func2 = &Sub::sub;
	cout << func2(Sub(), 1, 2) << endl; //-1

	//绑定固定参数
	function<int(int, int)> func3 = bind(&Sub::sub, Sub(), placeholders::_1, placeholders::_2);
	cout << func3(1, 2) << endl; //-1

	//调整传参顺序
	function<int(int, int)> func4 = bind(&Sub::sub, Sub(), placeholders::_2, placeholders::_1);
	cout << func4(1, 2) << endl; //1
	return 0;
	

}

