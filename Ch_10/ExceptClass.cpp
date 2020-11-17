#include <iostream>
using namespace std;

class CMyExp {
public:
	// 예외 코드와 메시지를 입력받는다.
	CMyExp(int nCode, const char* pszMsg)
	{
		m_nErrorCode = nCode;
		strcpy_s(m_szMsg, sizeof(m_szMsg), pszMsg);
	}

	int GetErrorCode() const { return m_nErrorCode; }
	const char* GetMessage() { return m_szMsg; }

private:
	int m_nErrorCode;
	char m_szMsg[128];
};

int main()
{
	try {
		int nInput = 0;
		cout << "양의 정수를 입력하세요.: ";
		cin >> nInput;

		if (nInput <= 0)
		{
			CMyExp exp(10, "양의 정수를 입력해야 합니다.");
			throw exp;
		}
	}
	
	catch (CMyExp& exp)
	{
		cout << "ERROR CODE [" << exp.GetErrorCode() << "] " 
			<< exp.GetMessage() << endl;
	}

	return 0;
}