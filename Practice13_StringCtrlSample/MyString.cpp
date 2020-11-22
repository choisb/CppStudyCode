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
	// 이동 생성자로 생성된 객체는 금방 사라질 것이기 때문에 얕은 복사만 한다.
	cout << "CMyString 이동 생성자 호출" << endl;
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	// 원본 임시 객체의 멤버들을 초기화 한다. 절대로 해제하면 안 된다.
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
	// 새로운 문자열 할당에 앞서 기존 정보를 해제한다.
	Release();

	// nullptr을 인수로 함수를 호출했다는 것은 메모리를 해제하고
	// nullptr로 초기화하는 기능으로 작동

	if (pszParam == nullptr)
		return 0;

	// 길이가 0인 문자열도 초기화로 인식하고 처리한다.
	int nLength = strlen(pszParam);

	if (nLength == 0)
		return 0;

	// 문자열의 끝인 NULL 문자를 고려해 메모리를 할당
	m_pszData = new char[nLength + 1];

	// 새로 할당한 메모리에 문자열을 저장한다.
	strcpy_s(m_pszData, sizeof(char) * (nLength + 1), pszParam);
	m_nLength = nLength;

	//미래를 호출한다! 미래에 MyString 클래스를 사용할 사용자에게 SetString() 함수에 관여할 수 있는 길을 열어준 것! 
	OnSetString(m_pszData, m_nLength);

	// 문자열의 길이를 반환한다.
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
	// 매개변수 유효성 검사
	if (pszParam == nullptr)
		return 0;

	int nLenParam = strlen(pszParam);

	if (nLenParam == 0)
		return 0;

	// 세트된 문자열이 없다면 새로 문자열을 할당한 것과 동일하게 처리함
	if (m_pszData == nullptr)
	{
		SetString(pszParam);

		return m_nLength;
	}

	// 현재 문자열의 길이 백업
	int nLenCur = m_nLength;

	// 두 문자열을 합쳐서 저장할 수 있는 메모리를 새로 할당함.
	char* pszResult = new char[nLenCur + nLenParam + 1];

	// 문자열 조합
	strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char) * nLenCur), sizeof(char) * (nLenParam + 1), pszParam);

	// 기존 문자열 삭제 및 멤버 정보 갱신
	Release();
	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}

CMyString CMyString::operator+(const CMyString& rhs)
{
	cout << "operator+ 호출 " << endl;
	CMyString result(this->m_pszData);

	if (rhs == nullptr)
		return result;

	result.Append(rhs.GetString());
	return result;
}



CMyString& CMyString::operator=(const CMyString& rhs)
{
	cout << "operator= 호출 " << endl;

	if (this != &rhs)
		this->SetString(rhs.GetString());

	return *this;
}

CMyString& CMyString::operator+= (const CMyString& rhs)
{
	cout << "operator+= 호출 " << endl;

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