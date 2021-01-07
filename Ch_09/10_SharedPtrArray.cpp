#include <iostream>
//#include <memory>
using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest()" << endl; }
	~CTest() { cout << "~CTest() " << endl; }
	void TestFunc() { cout << "TestFunc() " << endl; }
};

void RemoveTest(CTest* pTest)
{
	cout << "RemoveTest()" << endl;

	// ����� �迭�� �����Ѵ�.
	delete[] pTest;
}

int main()
{
	cout << "****Beging*****" << endl;

	// ��� ��ü�� �Ҹ��� �Լ��� ������ ����Ѵ�.
	shared_ptr<CTest> ptr(new CTest[3], RemoveTest);
	cout << "******End******" << endl;

	return 0;
}