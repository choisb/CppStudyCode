#include "pch.h"
#include "MyStringEx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyStringEx strTest;

	strTest.SetString("ธÛธÛภฬพฦต้");
	cout << strTest << endl;

	strTest.SetString("Hello");
	cout << strTest << endl;


	return 0;
}