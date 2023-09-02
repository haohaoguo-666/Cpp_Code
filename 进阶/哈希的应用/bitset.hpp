#include <iostream>
#include <vector>

using namespace std;

template<size_t N>
class bitset
{
public:
	//构造
	bitset()
	{
		_bits.resize(N / 8 + 1, 0);
	}

	//设置1
	void set(size_t val)
	{
		//1. 第几个char
		size_t i = val / 8;
		//2. char中第几位
		size_t j = val % 8;

		//3. 设置为1
		_bits[i] |= (1 << j);
	}

	//设置0
	void rset(size_t val)
	{
		size_t i = val / 8;
		size_t j = val % 8;
		_bits[i] &= ~(1 << j);
	}

	//检测是否存在
	bool test(size_t val)
	{
		size_t i = val / 8;
		size_t j = val % 8;
		return _bits[i] & (1 << j);
	}

	
private:
		
	vector<char> _bits;
};

void test_bitset1()
{
	bitset<1000> bs;
	bs.set(10);
	bs.set(11);
	bs.set(15);
	bs.rset(10);
}