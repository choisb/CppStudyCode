#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData() { cout << "CMyData() " << endl; }
	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

protected:
	void PrintData() { cout << "CMyData::PrintData()" << endl; }

private:
	int m_nData = 0;
};

class CMyDataEx : public CMyData
{
public:
	CMyDataEx() { cout << "CMyDataEx()" << endl; }
	void TestFunc()
	{
		PrintData();
		SetData(5);
		cout << CMyData::GetData() << endl;
	}

	void SetData(int nParam)
	{
		if (nParam < 0) {
			CMyData::SetData(0);

		}
		else if (nParam > 10) {
			CMyData::SetData(10);
		}
		else
		{
			CMyData::SetData(nParam);
		}
	}
};

int main()
{
	CMyData a;
	CMyDataEx b;

	a.SetData(-10);
	b.SetData(5);

	cout << "CMyData: " << a.GetData() << endl;
	cout << "CMyDataEx: " << b.GetData() << endl;

	return 0;
}