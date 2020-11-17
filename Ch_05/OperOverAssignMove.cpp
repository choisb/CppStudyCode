#include <iostream>
using namespace std;

class CMyData
{
public:
	explicit CMyData(int nParam)
	{
		cout << "CMyData(int)" << endl;
		m_pnData = new int(nParam);
	}

	CMyData(const CMyData& rhs)
	{
		cout << "CMyData(const CMyData &" << endl;
		m_pnData = new int(*rhs.m_pnData);
	}

	~CMyData() { delete m_pnData; }
	
	operator int() { return *m_pnData; }

	CMyData operator+(const CMyData& rhs)
	{
		return CMyData(*m_pnData + *rhs.m_pnData);
	}

	// �ܼ� ���Կ����� ��������
	CMyData& operator=(const CMyData& rhs)
	{
		cout << "operator= " << endl;
		if (this == &rhs)
			return *this;

		delete m_pnData;
		m_pnData = new int(*rhs.m_pnData);

		return *this;
	}

	// �̵� ���� ������
	CMyData& operator=(CMyData&& rhs) noexcept
	{
		cout << "operator = (Move)" << endl;

		//���� ���縦 �����ϰ� ������ NULL�� �ʱ�ȭ
		m_pnData = rhs.m_pnData;
		rhs.m_pnData = nullptr;

		return *this;
	}
private:
	int* m_pnData = nullptr;
};


int main() {

	CMyData a(0), b(3), c(4);
	cout << "*********Before*******" << endl;

	// �̵� ���� �����ڰ� ����ȴ�.
	a = b + c;
	cout << "*********After*********" << endl;
	cout << a << endl;
	a = b;
	cout << a << endl;

	return 0;
}