#pragma once
typedef int DataType;
class Stack
{
public:
	void Init(size_t capacity = 4);
	
	void Push(const DataType& data);

private:
	DataType Top();
	void Destroy();
	DataType* _array;
	size_t _capacity;
	size_t _size;
};
