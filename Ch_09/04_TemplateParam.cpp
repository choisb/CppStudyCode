#include <iostream>
using namespace std;

template<typename T, int nSize>
class CMyArray
{
public:
	CMyArray()
	{
		m_pData = new T[nSize];
	}

	~CMyArray() { 
		cout << "~CMyArray()" << endl;
		delete[] m_pData; }


	// �迭 ������
	T& operator[](int nIndex)
	{
		if (nIndex < 0 || nIndex >= nSize)
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
	int GetSize() { return nSize; }

private:
	T* m_pData = nullptr;
};

class CMyData
{
public:
	CMyData() {}

private:
	int m_nData = 0;
};

int main()
{
	//int �ڷ��� �迭
	CMyArray<int, 5> arr;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 20;
	arr[3] = 20;
	arr[4] = 20;

	//	arr[10] = 3; // ERROR: �迭�� ��踦 ��� �����Դϴ�.

	//for (int i = 0; i < 5; ++i)
	//	cout << arr[i] << ' ';

	//cout << endl;

	CMyArray<int, 5> arr2;
	arr2 = arr;
	//for (int i = 0; i < 5; ++i)
	//	cout << arr2[i] << ' ';

	cout << endl;

	return 0;
}