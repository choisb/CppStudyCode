#include <iostream>
using namespace std;

class CMyData {
public:
	CMyData(int nParam)
	{
		m_pnData = new int;
		*m_pnData = nParam;
	}

	CMyData(const CMyData& rhs)
	{
		//디폴트 복사 생성자 얕은 복사
		//m_pnData = rhs.m_pnData;

		// 깊은 복사 예시
		m_pnData = new int;

		*m_pnData = *rhs.m_pnData;
	}

	~CMyData()
	{
		delete m_pnData;
	}

	int GetData()
	{
		if (m_pnData != NULL)
			return *m_pnData;

		return 0;
	}

private:
	int* m_pnData = nullptr;
};

int main() 
{
	CMyData a(10);
	CMyData b(a);

	return 0;
}