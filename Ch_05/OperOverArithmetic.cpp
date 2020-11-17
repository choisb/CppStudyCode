#include <iostream>
using namespace std;

class CMyData
{
public:
	// 변환 생성자
	CMyData(int nParam) : m_nData(nParam) {
		cout << "CMyData(int)" << endl;
	}

	// 복사 생성자
	CMyData(const CMyData& rhs) : m_nData(rhs.m_nData)
	{
		cout << "CMyData(const CMyData &)" << endl;
	}

	// 이동 생성자
	CMyData(const CMyData&& rhs) : m_nData(rhs.m_nData)
	{
		cout << "CMyData(const CMyData &&)" << endl;
	}

	// 형변환
	operator int() { return m_nData; }

	//+ 연산자
	CMyData operator + (const CMyData& rhs)
	{
		cout << "operator+" << endl;
		CMyData result(0);
		result.m_nData = this->m_nData + rhs.m_nData;

		return result;
	}

	//연산자 =
	CMyData& operator= (const CMyData& rhs)
	{
		cout << "operator=" << endl;
		m_nData = rhs.m_nData;

		return *this;
	}
private:
	int m_nData = 0;
};

int main(int argc, char* argv[])
{
	cout << "******Begin******" << endl;
	CMyData a(0), b(3), c(4);
	a = b = c;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << "******End******" << endl;

	return 0;
}