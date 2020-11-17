#include "pch.h"
#include "MyString.h"

void TestFunc(const CMyString& param)
{
	cout << param.GetString() << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{

	CMyString strData;
	strData.SetString("Hello");
	TestFunc(strData);

	strData.~CMyString();

	return 0;
}