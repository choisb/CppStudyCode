#include "MyList.h"
#include <string.h>

CMyList::CMyList()
{

}

CMyList::~CMyList()
{

}

void CMyList::PrintAll(void) 
{

}

void CMyList::ReleaseList(void)
{

}

CUserData* CMyList::FindNode(const char* pszName)
{
	CUserData* pCursor;
	pCursor = m_Head.pNext;

	while (pCursor) {
	// ������ �̸��� ����Ʈ�� ������ ��� �ش� UserData�� return
		if (strcmp(pCursor->GetName, pszName) == 0)
			return pCursor;
		pCursor = pCursor->pNext;
	}

	// ������ �̸��� ����Ʈ�� ���ٸ� nullptr�� return
	return nullptr;
}

int CMyList::AddNewNode(const char* pszName, const char* pszPhone)
{
	// ������ �̸��� ����Ʈ�� �����Ѵٸ� Node�� �߰����� �ʰ� 0�� return
	if (FindNode(pszName) != nullptr)
		return 0;

	// ���ο� UserData Node�� �����Ͽ��� ���� ����
	CUserData* newUserData = new CUserData();
	strcpy_s(newUserData->szName, pszName);
	strcpy_s(newUserData->szPhone, pszPhone);

	// head�� next�� ���ο� UserData ����
	newUserData->pNext = m_Head.pNext;
	m_Head.pNext = newUserData;
}

int CMyList::RemoveNode(const char* pszName)
{
	CUserData* pPreve = &m_Head;
	CUserData* pDelete = nullptr;

	while (pPreve->pNext)
	{
		pDelete = pPreve->pNext;

		if (strcmp(pDelete->GetName, pszName) == 0)
		{
			pPreve->pNext = pDelete->pNext;
			delete pDelete;
			return 1;
		}
		pPreve = pPreve->pNext;
	}

	return 0;
}