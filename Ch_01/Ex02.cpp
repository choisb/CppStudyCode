#include <iostream>

#define COUT cout << a << ' ' << b << endl
using namespace std;

void mySwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	// 2��
	int a = 10;
	auto b = a;

	// 3��
	char* name = new char[12];
	delete[] name;

	// 4��
	a = 10;
	b = 20;

	mySwap(a, b);
	COUT;

	const int d = 10;

	// 5��
	//int&& c = d;
	// int&& d = b; ����
	//int&& d = 30;

	const int& e = 10;


}