#include "pch.h"
#include "MyString.h"

CMyString::CMyString() : m_pszData(NULL), m_nLength(0)
{
	m_pszData = new char[m_nLength + 1]();

}

CMyString::~CMyString()
{
	CMyString::Release();
}

int CMyString::SetString(const char* pszParam)
{
	int pszParam_Length = strlen(pszParam);

	// m_pszData에 아무 값도 없을 경우.
	if (m_nLength == 0) 
	{
		//입력값의 길이가 0 인 경우 아무것도 안하고 return
		if (pszParam_Length == 0)
		{
			return 0;
		}
		// 입력값의 길이가 유효할 경우 (0보다 클 경우)
		else {

			m_nLength = pszParam_Length;
			m_pszData = new char[m_nLength + 1]();
			strcpy_s(m_pszData, m_nLength + 1, pszParam);

			return 0;
		}
	}
	// m_pszData에 값이 있을 경우
	else { 

		// 새로 입력받은 값이 기존 값과 다를 경우
		if (strcmp(m_pszData, pszParam))
		{
			delete[] m_pszData;

			m_nLength = pszParam_Length;
			m_pszData = new char[m_nLength + 1]();
			strcpy_s(m_pszData, m_nLength + 1, pszParam);

			return 0;
		}
		else // 새로 입력받은 값이 현재 값과 같을 경우
		{
			return 0;
		}
	}
}

const char* CMyString::GetString()
{
	return m_pszData;
}

void CMyString::Release()
{
	delete[] m_pszData;
}