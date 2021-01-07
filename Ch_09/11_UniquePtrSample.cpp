#include <iostream>
using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest()" << endl; }
	~CTest() { cout << "~CTest()" << endl; }
	void TestFunc() { cout << "TestFunc()" << endl; }
};

int main()
{
	unique_ptr<CTest> ptr1(new CTest);
	
	//unique_ptr<CTest> ptr2(ptr1); //error
	unique_ptr<CTest> ptr2;
	//ptr2 = ptr1; //error
}