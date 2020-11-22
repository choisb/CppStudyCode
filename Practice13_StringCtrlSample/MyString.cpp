#include "pch.h"
#include "MyString.h"

CMyString::CMyString()
	: m_pszData(nullptr)
	, m_nLength(0)
{

}

CMyString::CMyString(const CMyString& rhs)
	: m_pszData(nullptr)
	, m_nLength(0)
{
	this->SetString(rhs.GetString());

}

CMyString::CMyString(CMyString&& rhs)
	: m_pszData(nullptr)
	, m_nLength(0)
{
	// �̵� �����ڷ� ������ ��ü�� �ݹ� ����� ���̱� ������ ���� ���縸 �Ѵ�.
	cout << "CMyString �̵� ������ ȣ��" << endl;
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	// ���� �ӽ� ��ü�� ������� �ʱ�ȭ �Ѵ�. ����� �����ϸ� �� �ȴ�.
	rhs.m_pszData = nullptr;
	rhs.m_nLength = 0;
}

CMyString::CMyString(const char* pszParam)
	: m_pszData(nullptr), m_nLength(0)
{
	this->SetString(pszParam);
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

	//�̷��� ȣ���Ѵ�! �̷��� MyString Ŭ������ ����� ����ڿ��� SetString() �Լ��� ������ �� �ִ� ���� ������ ��! 
	OnSetString(m_pszData, m_nLength);

	// ���ڿ��� ���̸� ��ȯ�Ѵ�.
	return nLength;
}

const char* CMyString::GetString() const
{
	return m_pszData;
}

int CMyString::GetLength() const
{
	return m_nLength;
}

void CMyString::Release()
{
	if(m_pszData != nullptr)
		delete[] m_pszData;

	m_pszData = nullptr;
	m_nLength = 0;
}

int CMyString::Append(const char* pszParam)
{
	// �Ű����� ��ȿ�� �˻�
	if (pszParam == nullptr)
		return 0;

	int nLenParam = strlen(pszParam);

	if (nLenParam == 0)
		return 0;

	// ��Ʈ�� ���ڿ��� ���ٸ� ���� ���ڿ��� �Ҵ��� �Ͱ� �����ϰ� ó����
	if (m_pszData == nullptr)
	{
		SetString(pszParam);

		return m_nLength;
	}

	// ���� ���ڿ��� ���� ���
	int nLenCur = m_nLength;

	// �� ���ڿ��� ���ļ� ������ �� �ִ� �޸𸮸� ���� �Ҵ���.
	char* pszResult = new char[nLenCur + nLenParam + 1];

	// ���ڿ� ����
	strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char) * nLenCur), sizeof(char) * (nLenParam + 1), pszParam);

	// ���� ���ڿ� ���� �� ��� ���� ����
	Release();
	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}

CMyString CMyString::operator+(const CMyString& rhs)
{
	cout << "operator+ ȣ�� " << endl;
	CMyString result(this->m_pszData);

	if (rhs == nullptr)
		return result;

	result.Append(rhs.GetString());
	return result;
}



CMyString& CMyString::operator=(const CMyString& rhs)
{
	cout << "operator= ȣ�� " << endl;

	if (this != &rhs)
		this->SetString(rhs.GetString());

	return *this;
}

CMyString& CMyString::operator+= (const CMyString& rhs)
{
	cout << "operator+= ȣ�� " << endl;

	if (rhs == nullptr)
		return *this;

	this->Append(rhs.GetString());
	return *this;

}

char& CMyString::operator[](int nIndex)
{
	return m_pszData[nIndex];
}
char CMyString::operator[](int nIndex) const
{
	return m_pszData[nIndex];
}

int CMyString::operator== (const CMyString& rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 1;

	return 0;
}

int CMyString::operator!= (const CMyString& rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 0;

	return 1;
}

CMyString operator+(const char* pszParam, const CMyString& strParam)
{
	CMyString strResult(pszParam);
	strResult.Append(strParam.m_pszData);

	return strResult;
}

void CMyString::OnSetString(char* pszData, int nLength)
{

}