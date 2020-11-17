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

	// m_pszData�� �ƹ� ���� ���� ���.
	if (m_nLength == 0) 
	{
		//�Է°��� ���̰� 0 �� ��� �ƹ��͵� ���ϰ� return
		if (pszParam_Length == 0)
		{
			return 0;
		}
		// �Է°��� ���̰� ��ȿ�� ��� (0���� Ŭ ���)
		else {

			m_nLength = pszParam_Length;
			m_pszData = new char[m_nLength + 1]();
			strcpy_s(m_pszData, m_nLength + 1, pszParam);

			return 0;
		}
	}
	// m_pszData�� ���� ���� ���
	else { 

		// ���� �Է¹��� ���� ���� ���� �ٸ� ���
		if (strcmp(m_pszData, pszParam))
		{
			delete[] m_pszData;

			m_nLength = pszParam_Length;
			m_pszData = new char[m_nLength + 1]();
			strcpy_s(m_pszData, m_nLength + 1, pszParam);

			return 0;
		}
		else // ���� �Է¹��� ���� ���� ���� ���� ���
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