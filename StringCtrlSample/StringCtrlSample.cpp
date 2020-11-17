#include "pch.h"
#include "MyString.h"

int _tmain(int argc, _TCHAR* argv[])
{

	CMyString strData;
	strData.SetString("Hello");
	strData.SetString("my");

	strData.SetString("name");
	strData.SetString("is");
	strData.SetString("");

	strData.SetString(" ");

	strData.SetString("123Choi");

	strData.~CMyString();

	return 0;
}