#include <iostream>
using namespace std;

class CMyExp {
public:
	// ���� �ڵ�� �޽����� �Է¹޴´�.
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
		cout << "���� ������ �Է��ϼ���.: ";
		cin >> nInput;

		if (nInput <= 0)
		{
			CMyExp exp(10, "���� ������ �Է��ؾ� �մϴ�.");
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