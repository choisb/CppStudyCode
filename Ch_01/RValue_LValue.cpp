#include <iostream>
using namespace std;

int main() {

	// �������� ��� �޸� ��ġ�� ����Ű�µ�, &�����ڸ� ���ؼ� ���� �����ϴ�.
	// �������� �������� �ƴ� ����.

	// ��������
	//
	int i = 42;
	i = 43;            // ok, i �� ������
	int* p = &i;       //&i �� �� �� �ִ�.
	int& foo();        // int& �� �����ϴ� �Լ�
	foo() = 42;        // ok, foo() �� ������
	int* p1 = &foo();  // ok, &foo() �� �� �� �ִ�.
	++i;

	// ��������
	//
	int foobar();  // int �� �����ϴ� �Լ�
	int j = 0;
	j = foobar();         // ok. foobar() �� �������̴�
	//int* p2 = &foobar();  // error. �������� �ּҴ� ������ �� ����.
	j = 42;               // 42 �� �������̴�.
	j++;

	return 0;

	//���� https://modoocode.com/189
}