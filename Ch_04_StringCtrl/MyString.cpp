#include "pch.h"
#include "MyString.h"

CMyString::CMyString() : m_pszData(nullptr), m_nLength(0)
{

}
CMyString::CMyString(const CMyString& rhs) : m_pszData(nullptr), m_nLength(0)
{
	Release();

	if (rhs.m_pszData == nullptr)
		return;

	int nLength = strlen(rhs.m_pszData);

	if (nLength == 0)
		return;

	m_pszData = new char[nLength + 1];

	strcpy_s(m_pszData, sizeof(char) * (nLength + 1), rhs.m_pszData);
	m_nLength = nLength;

}
CMyString CMyString::operator=(const CMyString& rhs)
{
	Release();

	if (rhs.m_pszData == nullptr)
		return *this;

	int nLength = strlen(rhs.m_pszData);

	if (nLength == 0)
		return *this;

	m_pszData = new char[nLength + 1];

	strcpy_s(m_pszData, sizeof(char) * (nLength + 1), rhs.m_pszData);
	m_nLength = nLength;

	return *this;
}

CMyString::~CMyString()
{
	CMyString::Release();
}

int CMyString::SetString(const char* pszParam)
{
	// ���ο� ���ڿ� �Ҵ翡 �ռ� ���� ������ �����Ѵ�.
	Release();

	// nullptr�� �μ��� �Լ��� ȣ���ߴٴ� ���� �޸𸮸� �����ϰ�
	// nullptr�� �ʱ�ȭ�ϴ� ������� �۵�

	if (pszParam == nullptr)
		return 0;

	// ���̰� 0�� ���ڿ��� �ʱ�ȭ�� �ν��ϰ� ó���Ѵ�.
	int nLength = strlen(pszParam);

	if (nLength == 0)
		return 0;

	// ���ڿ��� ���� NULL ���ڸ� ����� �޸𸮸� �Ҵ�
	m_pszData = new char[nLength + 1];

	// ���� �Ҵ��� �޸𸮿� ���ڿ��� �����Ѵ�.
	strcpy_s(m_pszData, sizeof(char) * (nLength + 1), pszParam);
	m_nLength = nLength;

	// ���ڿ��� ���̸� ��ȯ�Ѵ�.
	return nLength;
}

const char* CMyString::GetString() const
{
	return m_pszData;
}

void CMyString::Release()
{
	if(m_pszData != nullptr)
		delete[] m_pszData;

	m_pszData = nullptr;
	m_nLength = 0;
}