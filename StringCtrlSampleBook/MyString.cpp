#include "pch.h"
#include "MyString.h"

CMyString::CMyString() : m_pszData(nullptr), m_nLength(0)
{

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