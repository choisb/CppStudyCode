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

	//// 파생 형식의 객체를 기본 형식으로 포인팅합니다.
	//CMyData* pData = new CMyDataEx;
	//CMyDataEx* pNewData = nullptr;

	//// CMyData::SetData() 함수를 호출합니다.
	//// 따라서 10이 넘는지 검사하지 않습니다.
	//pData->SetData(15);

	//// 기본 형식에 대한 포인터이지만 가리키는 대상은 파생 형식입니다.
	//// 이 사실이 명확하므로 파생 형식에 대한 포인터로 형변환을 시도합니다.
	//pNewData = static_cast<CMyDataEx*>(pData);

	////pNewData = pData; //error C2440: '=': 'CMyData *'에서 'CMyDataEx *'(으)로 변환할 수 없습니다.
	////pNewData = (CMyDataEx*) pData //C style 형 변환. 오류를 유발 할 수 있기에 사용 지양.

	//pNewData->PrintData();
	//delete pData;

	//int nData = 10;
	//char* pszData = nullptr;
	////pszData = static_cast<char*> (&nData); // error C2440: 'static_cast': 'int *'에서 'char *'(으)로 변환할 수 없습니다.
	//

	return 0;
}