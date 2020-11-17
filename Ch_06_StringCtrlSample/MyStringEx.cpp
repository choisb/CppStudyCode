#include "MyStringEx.h"
#include "pch.h"

CMyStringEx::CMyStringEx()
{

}
CMyStringEx::~CMyStringEx()
{

}

int CMyStringEx::Find(const char* pszParam)
{
	//m_pszData를 가리키는 포인터 변수
	const char* pm_pszData;
	const char* pSerchStr;
	int nIndex = 0;

	pm_pszData = CMyString::GetString();

	if (pm_pszData == nullptr || pszParam == nullptr)
		return -1;

	pSerchStr = strstr(pm_pszData, pszParam);
	

	if (pSerchStr == nullptr)
		return -1;

	nIndex = (pSerchStr - pm_pszData) / sizeof(char);


	return nIndex;
}
