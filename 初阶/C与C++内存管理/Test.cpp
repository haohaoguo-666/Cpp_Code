#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	// 1.malloc/calloc/realloc��������ʲô��
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// ������Ҫfree(p2)��
//	free(p3);
//}


//void Test()
//{
//	// ��̬����һ��int���͵Ŀռ�
//	int* ptr4 = new int;
//	// ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* ptr5 = new int(10);
//	// ��̬����10��int���͵Ŀռ�
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
//1. ѡ���⣺
//ѡ�� : A.ջ B.�� C.���ݶ�(��̬��) D.�����(������)
//globalVar�����____ staticGlobalVar�����____
//staticVar�����____ localVar�����____
//num1 �����____
//char2�����____ * char2�����___
//pChar3�����____ * pChar3�����____
//ptr1�����____ * ptr1�����____
//2. ����⣺
//sizeof(num1) = ____;
//sizeof(char2) = ____; strlen(char2) = ____;
//sizeof(pChar3) = ____; strlen(pChar3) = ____;
//sizeof(ptr1) = ____;
//3. sizeof �� strlen ����

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
	//// new/delete �� malloc/free��������� new/delete���ڡ��Զ������͡����˿��ռ仹����ù��캯������������
	//A* p1 = (A*)malloc(sizeof(A));
	//A* p2 = new A(1);
	//free(p1);
	//delete p2;

	//// ���������Ǽ�����һ����
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
//	int* p1 = new int;  // �����ʼ��
//	int* p1 = new int(10); // ����һ��int����ʼ��10
//	int* p3 = new int[10]; // ����10��int������
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
//operator new���ú���ʵ��ͨ��malloc������ռ䣬��malloc����ռ�ɹ�ʱֱ�ӷ��أ�����ռ�
//ʧ�ܣ�����ִ�п� �䲻��Ӧ�Դ�ʩ�������Ӧ�Դ�ʩ�û������ˣ���������룬��
//�����쳣��
//*/
//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// ��������ڴ�ʧ���ˣ�������׳�bad_alloc �����쳣
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
///*
//operator delete: �ú���������ͨ��free���ͷſռ��
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
//free��ʵ��
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
//	// ʧ�������쳣
//	//int* p1 = (int*)operator new(sizeof(int*));
//
//	//// ʧ�ܷ���nullptr
//	//int* p2 = (int*)malloc(sizeof(int*));
//	//if (p2 == nullptr)
//	//{
//	//	perror("malloc fail");
//	//}
//
//	// ����ռ� operator new -> ��װmalloc
//	// ���ù��캯��
//	A* p5 = new A;
//
//	// �ȵ�����������
//	// ��operator delete p5ָ��Ŀռ�
//	// operator delete -> free
//	delete p5;
//
//	// ����ռ� operator new[] ->perator new-> ��װmalloc
//	// ����10�ι��캯��
//	A* p6 = new A[10];
//	
//	// �ȵ���10����������
//	// ��operator delete[] p6ָ��Ŀռ�
//	delete[] p6;
//
//
//	int* p7 = new int[10];
//	free(p7);  // �����ͷ�
//
//	A* p8 = new A;
//	//free(p8); // �ٵ��õ���������
//	delete p8;
//
//	Stack st;
//
//	Stack* pst = new Stack;
//	//delete pst;
//	free(pst); // �ٵ������������� -- ���ڴ�й©
//
//	// ���ۣ�new/mallocϵ�� �еײ�ʵ�ֻ����й������档��ƥ��ʹ��
//	// ���������⣬����û���⣬������һ��ƥ��ʹ��
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
//	// ��һ�����еĿռ��ʼ�� -- ����new
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
//	// 1.�ڴ������������ͷ�
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//	// 2.�쳣��ȫ����
//	int* p3 = new int[10];
//	Func(); // ����Func�������쳣���� delete[] p3δִ�У�p3û���ͷ�.
//	delete[] p3;
//}

//int main()
//{
//	int* p = new int[10];
//	// ���ú�������main����֮��ÿ�γ����˳���ʱ��ͻ����Ƿ�����ڴ�й©
//	_CrtDumpMemoryLeaks();
//	return 0;
//}
//////////////////////////////////////////////////////////
//// �����˳�������������п��Լ�⵽й©�˶����ֽڣ�����û�о����λ��
//Detected memory leaks!
//Dumping objects ->
//{79} normal block at 0x00EC5FB8, 40 bytes long.
//Data: < > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD
//Object dump complete.