#include <memory>
#include <iostream>
using namespace std;

template<typename T>
T Add(T a, T b) { return a + b; }

// 두 개의 변수가 모두 char* 형식이면 이 함수로 대체된다.
template<>
char* Add(char* pszLeft, char* pszRight)
{
	int nLenLeft = strlen(pszLeft);
	int nLenRight = strlen(pszRight);
	char* pszResult = new char[nLenLeft + nLenRight + 1];

	// 새로 할당한 메모리에 문자열을 복사한다.
	strcpy_s(pszResult, nLenLeft + 1, pszLeft);
	strcpy_s(pszResult + nLenLeft, nLenRight + 1, pszRight);

	return pszResult;
}
template<>
const char* Add(const char* pszLeft, const char* pszRight);


int main()
{
	int nResult = Add<int>(3, 4);
	cout << nResult << endl;

	const char* pszResult = Add<const char*>("Hello", "World"); //error

	char str1[6] = "hello";
	char str2[6] = "world";

	char* pszResult = Add<char*>(str1, str2);

	cout << pszResult << endl;
}