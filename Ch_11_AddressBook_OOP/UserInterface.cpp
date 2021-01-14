#include "UserInterface.h"

CUserInterface::CUserInterface(CMyList &rList) :m_List(rList)
{

}

CUserInterface::~CUserInterface()
{

}
void CUserInterface::Add()
{

}

void CUserInterface::Search(void)
{

}

void CUserInterface::Remove(void)
{

}

int CUserInterface::PrintUI(void)
{
	return 0;
}


int CUserInterface::Run(void)
{
	int nMenu = 0;

	//���� �̺�Ʈ �ݺ���
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu) {
		case 1: //Add
			Add();
			break;

		case 2: //Search
			Search();
			break;

		case 3: // Print all
			m_List.PrintAll();
			break;

		case 4: // Remove
			Remove();
			break;
		}
	}

	return 0;
}