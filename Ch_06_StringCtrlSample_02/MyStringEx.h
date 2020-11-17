#pragma once
#include "MyString.h"
class CMyStringEx :
    public CMyString
{
public:
    CMyStringEx();
    int Find(const char* pszParam);
    int SetString(const char* pszParam);
    ~CMyStringEx();

};

