#pragma once
class CMyString
{

public:
	// 디폴트 생성자. nullptr로 초기화
	CMyString();

	// 복사생성자. rhs의 값으로 복사함.
	CMyString(const CMyString&);

	// 이동생성자
	CMyString(CMyString&&);

	// 변환생성자. explicit 예약어를 사용하면 묵시적으로 변환생성자 호출 불가
	explicit CMyString(const char*);

	// 소멸자
	~CMyString();

private:
	//문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;

	// 저장된 문자열의 길이
	int m_nLength;

public:
	int SetString(const char* psdParam);
	const char* GetString() const;
	void Release();

	// 형변환 연산자. explicit 예약어를 사용하면 묵시적 형변환 연산자 호출 불가. 반드시 static_cast<char*> 사용해야함.
	operator char* (void) const { return m_pszData; }

	//대입 연산자. rhs의 값을 복사한 자신값을 return
	//CMyString operator= (const CMyString&);

	int GetLength() const;
	int Append(const char* pszParm);

	CMyString operator+ (const CMyString& rhs);
	CMyString& operator= (const CMyString& rhs);
	CMyString& operator+= (const CMyString& rhs);
	char& operator[](int nIndex);
	char operator[](int nIndex) const;
	int operator== (const CMyString& rhs);
	int operator!= (const CMyString& rhs);

	virtual void OnSetString(char* pszData, int nLength);

	// (const char*) c_str + (CMyString) CMy_str 의 덧셈에서 덧셈의 주체가되는 왼쪽항 c_str의 
	// 타입은 (const char*)인 기본타입이기 때문에 (+의 연산의 주체가 CMYString 객체가 아니기 때문에) 
	// 멤버함수로 정의할 수 없다. friend 함수를 통해서 멤버변수에 접근권한을 주어서 정의해줄 수 있다.
	friend CMyString operator+(const char* pszParam, const CMyString& strParam);
};

