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
	//m_pszData�� ����Ű�� ������ ����
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

void CMyStringEx::OnSetString(char* pszData, int nLength)
{
	if (strcmp(pszData, "�۸��̾Ƶ�") == 0)
		strcpy_s(pszData, sizeof(char) * (nLength + 1), "*���ѾƵ�*");
}