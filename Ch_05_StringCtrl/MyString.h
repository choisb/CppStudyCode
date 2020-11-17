#pragma once
class CMyString
{

public:
	// ����Ʈ ������. nullptr�� �ʱ�ȭ
	CMyString();

	// ���������. rhs�� ������ ������.
	CMyString(const CMyString&);

	// �̵�������
	CMyString(CMyString&&);

	// ��ȯ������. explicit ���� ����ϸ� ���������� ��ȯ������ ȣ�� �Ұ�
	explicit CMyString(const char*);

	// �Ҹ���
	~CMyString();

private:
	//���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;

	// ����� ���ڿ��� ����
	int m_nLength;

public:
	int SetString(const char* psdParam);
	const char* GetString() const;
	void Release();

	// ����ȯ ������. explicit ���� ����ϸ� ������ ����ȯ ������ ȣ�� �Ұ�. �ݵ�� static_cast<char*> ����ؾ���.
	operator char* (void) const { return m_pszData; }

	//���� ������. rhs�� ���� ������ �ڽŰ��� return
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
};

