#include <iostream>
using namespace std;

// �ʱ� �������� �ڵ�
class CMyObject
{
public:
	CMyObject() {}
	virtual ~CMyObject() {}

	virtual int GetDeviceID() = 0;


protected:
	int m_nDeviceID;
};

// �ʱ� �����ڰ� ���� �Լ�
void PrintID(CMyObject* pObj)
{
	//������ � �������� ������ �׷��� ID�� ����� �� �ִ�!
	cout << "Device ID: " << pObj->GetDeviceID() << endl;
}

//�ı� �������� �ڵ�
class CMyTV : public CMyObject
{
public:
	CMyTV(int nID) { m_nDeviceID = nID; }
	virtual int GetDeviceID()
	{
		cout << "CMyTV::GetDeviceID()" << endl;
		return m_nDeviceID;
	}
};

class CMyPhone : public CMyObject
{
public:
	CMyPhone(int nID) { m_nDeviceID = nID; }
	virtual int GetDeviceID()
	{
		cout << "CMyPhone::GetDeviceID()" << endl;
		return m_nDeviceID;
	}
};

//����� �ڵ�

int main()
{
	CMyTV tv(5);
	CMyPhone phone(10);

	//���� ��ü�� �����̵� �˾Ƽ� �ڽ��� ID�� ����Ѵ�.
	::PrintID(&tv);
	::PrintID(&phone);

	return 0;
}