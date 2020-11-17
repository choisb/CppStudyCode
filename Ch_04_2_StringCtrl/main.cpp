#include "pch.h"
#include "MyString.h"

void TestFunc(const CMyString& strParam)
{
	cout << strParam << endl;
}
CMyString TestFunc2(void)
{
	CMyString strTest("Test");
	cout << strTest << endl;

	return strTest;
}
int _tmain(int argc, _TCHAR* argv[])
{
	string test;

	test = "123";

	cout << test << endl;;
	//CMyString strData("Hello");

	//::TestFunc(strData);
	//::TestFunc(CMyString("World"));

	TestFunc2();
	return 0;
}