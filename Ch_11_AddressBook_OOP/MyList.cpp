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
	// 동일한 이름이 리스트에 존재할 경우 해당 UserData를 return
		if (strcmp(pCursor->GetName, pszName) == 0)
			return pCursor;
		pCursor = pCursor->pNext;
	}

	// 동일한 이름이 리스트에 없다면 nullptr을 return
	return nullptr;
}

int CMyList::AddNewNode(const char* pszName, const char* pszPhone)
{
	// 동일한 이름이 리스트에 존재한다면 Node를 추가하지 않고 0을 return
	if (FindNode(pszName) != nullptr)
		return 0;

	// 새로운 UserData Node를 생성하여서 값을 저장
	CUserData* newUserData = new CUserData();
	strcpy_s(newUserData->szName, pszName);
	strcpy_s(newUserData->szPhone, pszPhone);

	// head의 next에 새로운 UserData 삽입
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