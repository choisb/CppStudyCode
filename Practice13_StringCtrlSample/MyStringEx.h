#pragma once
#include "MyString.h"
class CMyStringEx :
    public CMyString
{
public:
    CMyStringEx();
    int Find(const char* pszParam);
    ~CMyStringEx();

    void OnSetString(char* pszData, int nLength);

};

