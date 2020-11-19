#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData() {}
	virtual ~CMyData() {}
	void SetData(int nParam) { m_nData = nParam; }
	int GetData() { return m_nData; }

protected:
	int m_nData;
};

class CMyDataEx : public CMyData
{
public:
	void SetData(int nParam) 
	{
		if (nParam > 10)
			nParam = 10;

		CMyData::SetData(nParam);
	}

	void PrintData()
	{
		cout << "PrintData(): " << GetData() << endl;
	}
};

int main()
{

	CMyData* pData = new CMyData;
	CMyDataEx* pNewData;
	pNewData = static_cast<CMyDataEx*> (pData);

	//// �Ļ� ������ ��ü�� �⺻ �������� �������մϴ�.
	//CMyData* pData = new CMyDataEx;
	//CMyDataEx* pNewData = nullptr;

	//// CMyData::SetData() �Լ��� ȣ���մϴ�.
	//// ���� 10�� �Ѵ��� �˻����� �ʽ��ϴ�.
	//pData->SetData(15);

	//// �⺻ ���Ŀ� ���� ������������ ����Ű�� ����� �Ļ� �����Դϴ�.
	//// �� ����� ��Ȯ�ϹǷ� �Ļ� ���Ŀ� ���� �����ͷ� ����ȯ�� �õ��մϴ�.
	//pNewData = static_cast<CMyDataEx*>(pData);

	////pNewData = pData; //error C2440: '=': 'CMyData *'���� 'CMyDataEx *'(��)�� ��ȯ�� �� �����ϴ�.
	////pNewData = (CMyDataEx*) pData //C style �� ��ȯ. ������ ���� �� �� �ֱ⿡ ��� ����.

	//pNewData->PrintData();
	//delete pData;

	//int nData = 10;
	//char* pszData = nullptr;
	////pszData = static_cast<char*> (&nData); // error C2440: 'static_cast': 'int *'���� 'char *'(��)�� ��ȯ�� �� �����ϴ�.
	//

	return 0;
}