#include "tchar.h"
#include <iostream>
using namespace std;

class CTestData
{
public:
	CTestData(int nParam) : m_nData(nParam)
	{
		cout << "CTestData(int)" << endl;
	}

	CTestData(const CTestData& rhs) : m_nData(rhs.m_nData)
	{
		cout << "CTestData(const CTestData &)" << endl;
	}

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
	~CTestData() 
	{
		cout << "~CTestData()" << endl;
	}

private:
	int m_nData = 0;
};



int _tmain(int argc, _TCHAR* argv[])
{
	// int 자료형에서 CTestData 형식으로 변환될 수 있다.

	CTestData test(10);
	test = 5; //test = CTestData(5);
	cout << test.GetData() << endl;

	return 0;
}