#include "pch.h"
#include "MyString.h"

void TestFunc(const CMyString& param)
{
	cout << param.GetString() << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{

	CMyString strData, strTest;
	strData.SetString("Hello");
	strTest.SetString("World");

	CMyString strNewData(strData);
	cout << strNewData.GetString() << endl;

	strNewData = strTest;
	cout << strNewData.GetString() << endl;

	strData.~CMyString();
	strTest.~CMyString();
	strNewData.~CMyString();


	return 0;
}