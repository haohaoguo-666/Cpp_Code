#define _CRT_SECURE_NO_WARNINGS 1

#include "string.h"
int main()
{
	

	/*try
	{
		yyf::test_string9();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	

	return 0;*/

	yyf::string s1;
	std::string s2;
	cout << sizeof(s1) << endl;
	cout << sizeof(s2) << endl;

	yyf::string s3("11111");
	std::string s4("1111111");
	cout << sizeof(s3) << endl;
	cout << sizeof(s4) << endl;

} 

