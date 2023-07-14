#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// 这里需要free(p2)吗？
//	free(p3);
//}


//void Test()
//{
//	// 动态申请一个int类型的空间
//	int* ptr4 = new int;
//	// 动态申请一个int类型的空间并初始化为10
//	int* ptr5 = new int(10);
//	// 动态申请10个int类型的空间
//	int* ptr6 = new int[3];
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//}

//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//1. 选择题：
//选项 : A.栈 B.堆 C.数据段(静态区) D.代码段(常量区)
//globalVar在哪里？____ staticGlobalVar在哪里？____
//staticVar在哪里？____ localVar在哪里？____
//num1 在哪里？____
//char2在哪里？____ * char2在哪里？___
//pChar3在哪里？____ * pChar3在哪里？____
//ptr1在哪里？____ * ptr1在哪里？____
//2. 填空题：
//sizeof(num1) = ____;
//sizeof(char2) = ____; strlen(char2) = ____;
//sizeof(pChar3) = ____; strlen(pChar3) = ____;
//sizeof(ptr1) = ____;
//3. sizeof 和 strlen 区别？

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
	//// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间还会调用构造函数和析构函数
	//A* p1 = (A*)malloc(sizeof(A));
	//A* p2 = new A(1);
	//free(p1);
	//delete p2;

	//// 内置类型是几乎是一样的
	//int* p3 = (int*)malloc(sizeof(int)); // C
	//int* p4 = new int;
	//free(p3);
	//delete p4;

//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	A* p6 = new A[10];
//	free(p5);
//	delete[] p6;
//
//	
//	return 0;
//}

//int main()
//{
//	int* p1 = new int;  // 不会初始化
//	int* p1 = new int(10); // 申请一个int，初始化10
//	int* p3 = new int[10]; // 申请10个int的数组
//	int* p4 = new int[10] {1, 2, 3, 4};
//
//	int* p2 = (int*)malloc(sizeof(int));
//	if (p2 == nullptr)
//	{
//		perror("malloc fail");
//	}
//
//	return 0;
//}

///*
//operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间
//失败，尝试执行空 间不足应对措施，如果改应对措施用户设置了，则继续申请，否
//则抛异常。
//*/
//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
///*
//operator delete: 该函数最终是通过free来释放空间的
//*/
//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK); /* block other threads */
//	__TRY
//		/* get a pointer to memory block header */
//		pHead = pHdr(pUserData);
//	/* verify block type */
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//	_free_dbg(pUserData, pHead->nBlockUse);
//	__FINALLY
//		_munlock(_HEAP_LOCK); /* release other threads */
//	__END_TRY_FINALLY
//		return;
//}
///*
//free的实现
//*/
//#define free(p) _free_dbg(p, _NORMAL_BLOCK)

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};


//class Stack
//{
//public:
//	Stack()
//	{
//		cout << "Stack()" << endl;
//		_a = new int[4];
//		_top = 0;
//		_capacity = 4;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		delete[] _a;
//		_top = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};


//int main()
//{
//	// 失败了抛异常
//	//int* p1 = (int*)operator new(sizeof(int*));
//
//	//// 失败返回nullptr
//	//int* p2 = (int*)malloc(sizeof(int*));
//	//if (p2 == nullptr)
//	//{
//	//	perror("malloc fail");
//	//}
//
//	// 申请空间 operator new -> 封装malloc
//	// 调用构造函数
//	A* p5 = new A;
//
//	// 先调用析构函数
//	// 再operator delete p5指向的空间
//	// operator delete -> free
//	delete p5;
//
//	// 申请空间 operator new[] ->perator new-> 封装malloc
//	// 调用10次构造函数
//	A* p6 = new A[10];
//	
//	// 先调用10次析构函数
//	// 再operator delete[] p6指向的空间
//	delete[] p6;
//
//
//	int* p7 = new int[10];
//	free(p7);  // 正常释放
//
//	A* p8 = new A;
//	//free(p8); // 少调用的析构函数
//	delete p8;
//
//	Stack st;
//
//	Stack* pst = new Stack;
//	//delete pst;
//	free(pst); // 少调用了析构函数 -- 有内存泄漏
//
//	// 结论：new/malloc系列 有底层实现机制有关联交叉。不匹配使用
//	// 可能有问题，可能没问题，建议大家一定匹配使用
//
//	A* p9 = new A[10];
//	//free(p9);
//	//delete p9;
//	delete[] p9;
//
//	return 0;
//}

//int main()
//{
//	A aa;
//
//	A* p1 = (A*)malloc(sizeof(A));
//	if (p1 == nullptr)
//	{
//		perror("malloc fail");
//	}
//
//	// 对一块已有的空间初始化 -- 定义new
//	//new(p1)A;
//	new(p1)A(1);
//
//	A* p2 = new A;
//
//	p1->~A();
//	free(p1);
//
//	delete p2;
//
//
//	return 0;
//}


//void MemoryLeaks()
//{
//	// 1.内存申请了忘记释放
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//	// 2.异常安全问题
//	int* p3 = new int[10];
//	Func(); // 这里Func函数抛异常导致 delete[] p3未执行，p3没被释放.
//	delete[] p3;
//}

//int main()
//{
//	int* p = new int[10];
//	// 将该函数放在main函数之后，每次程序退出的时候就会检测是否存在内存泄漏
//	_CrtDumpMemoryLeaks();
//	return 0;
//}
//////////////////////////////////////////////////////////
//// 程序退出后，在输出窗口中可以检测到泄漏了多少字节，但是没有具体的位置
//Detected memory leaks!
//Dumping objects ->
//{79} normal block at 0x00EC5FB8, 40 bytes long.
//Data: < > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD
//Object dump complete.