#include <iostream>
using namespace std;

int main()
{
	int* pA, * pB;

	pA = new int;
	*pA = 10;

	pB = new int;
	*pB = *pA;

	delete pA;

	pA = pB;

	delete pA;


	return 0;
}