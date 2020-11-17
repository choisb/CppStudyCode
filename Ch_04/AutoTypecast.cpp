#include "tchar.h"
#include <iostream>
using namespace std;

class CTestData
{
public:
	explicit CTestData(int nParam) : m_nData(nParam)
	{
		cout << "CTestData(int)" << endl;
	}

	operator int(void) { return m_nData; }
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
	// int �ڷ������� CTestData �������� ��ȯ�� �� �ִ�.

	CTestData test(10);
	
	cout << test.GetData() << endl;
	cout << test << endl;
	cout << (int)test << endl;
	cout << static_cast<int>(test) << endl;
	//cout << reinterpret_cast<int>(test) << endl;
	

	return 0;
}