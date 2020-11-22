#include <iostream>
#include <string.h>
using namespace std;

class CNode
{
	friend class CMyList;

public:
	explicit CNode(const char* pszName)
	{
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}

private:
	char m_szName[32];
	CNode* pNext = nullptr;
};

class CMyList
{
public:
	CMyList() : m_HeadNode("Dummy Head") {}
	~CMyList()
	{
		CNode* pNode = m_HeadNode.pNext;
		CNode* pDelete = nullptr;

		while (pNode)
		{
			pDelete = pNode;
			pNode = pNode->pNext;

			cout << pDelete->m_szName << endl;
			delete pDelete;
		}

		m_HeadNode.pNext = nullptr;
	}

	// ����Ʈ�� ���ο� ��带 �߰�
	void AddNewNode(const char* pszName)
	{
		CNode* pNode = new CNode(pszName);

		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

	// ����Ʈ�� ��� ��� ���� ���
	void Print()
	{
		CNode* pNode = m_HeadNode.pNext;
		while (pNode)
		{
			cout << pNode->m_szName << endl;
			pNode = pNode->pNext;
		}
	}

private:
	CNode m_HeadNode;
};

//UI Ŭ����
class CMyUI
{
public:
	CMyUI(CMyList& rList) : m_list(rList) {}
	//�޴� ��� �� ����� �Է� Ȯ��
	int PrintMenu()
	{
		system("cls");
		cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n: ";
		cout.flush();
		int nInput = 0;
		cin >> nInput;

		return nInput;
	}


	// ���������� �޴��� ����ϴ� ���� �̺�Ʈ �ݺ���
	void Run()
	{
		char szName[32];
		int nInput = 0;

		while ((nInput = PrintMenu()) > 0)
		{
			switch (nInput)
			{
			case 1: // Add
				cout << "�̸�: ";
				cout.flush();
				cin >> szName;
				m_list.AddNewNode(szName);
				break;

			case 2: // Print
				m_list.Print();
				break;

			default:
				break;
			}
		}
	}

private:
	// UI Ŭ���� ���ο� �ڷᱸ���� ���Եȴ�.
	CMyList &m_list;
};

// ����� �ڵ�
int main()
{

	CMyList list;
	CMyUI ui(list);
	ui.Run();

	return 0;
}