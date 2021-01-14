#include "UserData.h"
#include <memory>

CUserData::CUserData()
	: pNext(nullptr)
{
	memset(szName, 0, sizeof(szName));
	memset(szPhone, 0, sizeof(szPhone));
	nUserDataCounter++;
}

CUserData::~CUserData()
{
	nUserDataCounter--;
}