
#include <iostream>
using namespace std;

class CMyData
{
public:
	// 가상 함수로 선언 및 정의
	virtual void PrintData()
	{
		cout << "CMyData: " << m_nData << endl;
	}

	void TestFunc()
	{
		cout << "***TestFunc()***" << endl;

		//실 형식의 함수 호출
		PrintData();
		cout << "****************" << endl;
	}

protected:
	int m_nData = 10;
};

class CMyDataEx : public CMyData
{
public:
	virtual void PrintData()
	{
		cout << "CMyDataEx: " << m_nData * 2 << endl;
	}
};

int main()
{
	CMyDataEx a;
	a.PrintData();
	a.TestFunc();

	CMyData& b = a;
	b.PrintData();

	b.TestFunc();
}