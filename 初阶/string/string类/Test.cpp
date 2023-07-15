#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

using namespace std;

//int main()
//{
//
//	char str2[] = "好好";
//
//	cout << sizeof(str2) << endl;
//
//	str2[3]--;
//	cout << str2 << endl;
//
//	str2[3]--;
//	cout << str2 << endl;
//
//	str2[3]++;
//	cout << str2 << endl;
//	
//	str2[3]++;
//	cout << str2 << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1;
//	string s2("hello world");
//	string s3 = "hello world";//隐式类型转化 const char* -> string
//	string s4(s3, 6, 3);
//	string s5(s3, 6, 13);
//	string s6(s3, 6);
//	string s7("hello world", 5);
//	string s8(10, 'y');
//
//
//	cout << s4 << endl;
//
//	for (size_t i = 0; i < s2.size(); i++)
//	{
//		s2[i]++;
//	}
//
//
//	cout << s2 << endl;
//
//	cout << s3 << endl;
//
//	cout << s4 << endl;
//
//	cout << s5 << endl;
//
//	cout << s6 << endl;
//
//	cout << s7 << endl;
//
//
//	cout << s8 << endl;
//	return 0;
//
//}

//int main()
//{
//	
//	string s1("hello world");
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.max_size() << endl;
//	cout << s1.capacity() << endl;
//
//	string s2;
//	if (s2.empty())
//		cout << "空字符串" << endl;
//	return 0;
//}


//int main()
//{
//	string s1("hello");
//	//s1.push_back(' ');
//	//s1.push_back('w');
//	//cout << s1 << endl;
//
//	//s1.append(" world");
//	//cout << s1 << endl;
//
//	/*s1 += " world";
//	cout << s1 << endl;*/
//
//
//
//}

//class string
//{
//private:
//	char* ptr;//大小大于16就会去开辟空间，第一次会开32B,依次1.5倍增长
//	char _buf[16]; //一开始存在这数组
//	size_t _size;
//	size_t _capacity;
//};

//void TestPushBack()
//{//观察扩容的情况
//	string s;
//	cout << sizeof(s) << endl;
//	size_t sz = s.capacity();
//	cout << sz << endl;
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}

//void TestPushBack()
//{//观察扩容的情况
//	string s;
//	cout << sizeof(s) << endl;
//	s.reserve(100);//把空间提前开好，如果知道需要多少空间，减少扩容，提高效率
//	size_t sz = s.capacity();
//	cout << sz << endl;
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//
//int main()
//{
//	TestPushBack();
//}

//int main()
//{
//	string s1("hello world");
//	s1.reserve(100);//扩容 
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	s1.resize(100);//扩容并且初始化为'\0'
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	s1.resize(200);//扩容并且初始化为'x'
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	s1.resize(100);//不会缩容，缩容需要开辟新的空间还有拷贝，性能下降
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//}

//int main()
//{
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//
	//for (auto ch : s1)
	//{
	//	cout << ch << " ";
	//}

	//cout << endl;
//	
//	return 0;
//}

//void Func1(const string& s)
//{
//	//遍历和读容器的数据，不能写
//	//string::const_iterator it = s.cbegin();
//	auto it = s.cbegin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//
//	cout << endl;
//}
//void Func2(const string& s)
//{
//	//string::const_reverse_iterator it = s.rbegin();
//	auto it = s.crbegin();
//	while (it != s.rend())
//	{
//		cout << *it << " ";
//		it++;
//	}
//
//	cout << endl;
//}
//
//int main()
//{
//	string s1("hello world");
//	//遍历和读写容器的数据
//	//string::reverse_iterator rit = s1.rbegin();
//	auto rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	return 0;
//}

//int main()
//{
//	string s1("world");
//
//	s1.insert(0, "hello");
//
//	//不推荐使用insert,效率低
//	//s1.insert(5, 1, ' ');
//	//s1.insert(5, " "); 
//	string::iterator it = s1.begin();
//	s1.insert(it+5, ' ');
//	cout << s1 << endl;
//	return 0;
//}
//
//int main()
//{
//	//不推荐使用erase,效率低
//	string s1("hello world");
//	//s1.erase(5, 1);
//
//	string::iterator it = s1.begin();
//	//s1.erase(it + 5);
//
//	//s1.erase(5);
//	s1.erase(5, 6);
//	cout << s1 << endl;
//
//}

//int main()
//{
//	//string s1("hello world");
//	//s1.replace(5, 1, "%%d");//扩容+移动数据
//	//cout << s1 << endl;、
//
//	string s1("hello world i love you");
//	size_t num = 0;
//	for (auto ch : s1)
//	{
//		if (ch == ' ')
//		{
//			num++;
//		}
//	}
//	//提前开空间，避免replace时扩容
//	s1.reserve(2* num + s1.size());
//	size_t pos = s1.find(' ');
//	while(pos != string::npos)
//	{	
//		s1.replace(pos, 1, "%20");
//		pos = s1.find(' ', pos + 3);
//	}
//	cout << s1 << endl;
//}

//int main()
//{
//	string s1("hello world i love you");
//	string newStr;
//	size_t num = 0;
//	for (auto ch : s1)
//	{
//		if (ch == ' ')
//		{
//			num++;
//		}
//	}
//	//提前开空间，避免replace时扩容
//	s1.reserve(2* num + s1.size());
//	for (auto ch : s1)
//	{
//		if (ch != ' ')
//			newStr += ch;
//		else
//			newStr += "%20";
//	}
//	s1 = newStr;
//	cout << newStr << endl;
//}

//int main()
//{
//	string s1("xxx");
//	string s2("yyy");
//
//	s1.swap(s2);
//	cout << s1 << endl;
//	cout << s2 << endl;
//
//	swap(s1, s2);
//	cout << s1 << endl;
//	cout << s2 << endl;
//	 
//}

//int main()
//{
//	string s1("hello world");
//
//	cout << s1.c_str() << endl;
//
//	string filename("test.cpp");
//	FILE* fout = fopen(filename.c_str(), "r");
//	if (fout == nullptr)
//	{
//		perror("fopen fail");
//	}
//	char ch = fgetc(fout);
//	while (ch != EOF)
//	{
//		cout << ch;
//		ch = fgetc(fout);
//
//	}
//	fclose(fout);
//
//	return 0;
//}

//int main()
//{
//	// 获取file的后缀
//	string file("string.cpp");
//	size_t pos = file.rfind('.');
//	string suffix(file.substr(pos, file.size() - pos));
//	cout << suffix << endl;
//}

//int main()
//{
//	// 获取file的后缀
//	string file("string.cpp");
//	size_t pos = file.rfind('.');
//	string suffix(file.substr(pos, file.size() - pos));
//	cout << suffix << endl;
//
//	// npos是string里面的一个静态成员变量
//	// static const size_t npos = -1;
//
//	// 取出url中的域名
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//		return -1;
//	}
//	start += 3;
//	size_t finish = url.find('/', start);
//	string address = url.substr(start, finish - start);
//	cout << address << endl;
//
//	// 删除url的协议前缀
//	pos = url.find("://");
//	url.erase(0, pos + 3);
//	cout << url << endl;
//
//	return 0;
//}

//int main()
//{
//	std::string str("Please, replace the vowels in this sentence by asterisks.");
//	std::size_t found = str.find_first_of("aeiou");
//	while (found != std::string::npos)
//	{
//		str[found] = '*';
//		found = str.find_first_of("aeiou", found + 1);
//	}
//
//	std::cout << str << '\n';
//
//	return 0;
//}
