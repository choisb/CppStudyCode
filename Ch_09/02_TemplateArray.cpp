#include <iostream>
using namespace std;

template<typename T>
class CMyArray
{
public:
	explicit CMyArray(int nSize) : m_nSize(nSize)
	{
		m_pData = new T[nSize];
	}

	~CMyArray() { delete[] m_pData; }

	//���� ������
	CMyArray(const CMyArray& rhs)
	{
		cout << "���� ������()" << endl;
		m_pData = new T[rhs.m_nSize];
		memcpy(m_pData, rhs.m_pData, sizeof(T) * rhs.m_nSize);
		m_nSize = rhs.m_nSize;
	}

	// ���� ������
	CMyArray& operator=(const CMyArray& rhs)
	{
		if (this == &rhs)
			return *this;

		delete m_pData;
		m_pData = new T[rhs.m_nSize];
		memcpy(m_pData, rhs.m_pData, sizeof(T) * rhs.m_nSize);
		m_nSize = rhs.m_nSize;

		return *this;
	}

	// �̵� ������
	CMyArray(CMyArray&& rhs)
	{
		operator = (rhs);
	}

	// �̵� ���� ������
	CMyArray& operator=(const CMyArray&& rhs)
	{
		m_pData = rhs.m_pData;
		m_nSize = rhs.m_nSize;
		rhs.m_pData = nullptr;
		rhs.m_nSize = 0;
	}

	// �迭 ������
	T& operator[](int nIndex)
	{
		if (nIndex < 0 || nIndex >= m_nSize)
		{
			cout << "ERROR: �迭�� ��踦 ��� �����Դϴ�." << endl;
			exit(1);
		}

		return m_pData[nIndex];
	}

	//���ȭ�� �迭 ������
	T& operator[] (int nIndex) const
	{
		return operator[](nIndex);
	}

	// �迭 ����� ������ ��ȯ
	int GetSize() { return m_nSize; }

private:
	T* m_pData = nullptr;
	int m_nSize = 0;

};

class CMyData
{
public:
	CMyData() {}

private:
	int m_nData = 0;
};

void test(CMyArray<int> arr)
{
}

int main()
{
	//int �ڷ��� �迭
	CMyArray<int> arr(5);
	arr[0] = 10;
	arr[1] = 20;
	// CMyData �ڷ��� �迭
	CMyArray<CMyData> Darr(3);

	test(arr);
	
	CMyArray<int> arr2();

//	arr[10] = 3; // ERROR: �迭�� ��踦 ��� �����Դϴ�.

	for (int i = 0; i < 2; ++i)
		cout << arr[i] << ' ';

	cout << endl;

	//CMyArray<int> arr2(3);
	//arr2 = arr;
	//for (int i = 0; i < 2; ++i)
	//	cout << arr2[i] << ' ';

	//cout << endl;

	return 0;
}