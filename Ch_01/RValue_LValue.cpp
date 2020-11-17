#include <iostream>
using namespace std;

int main() {

	// 좌측값은 어떠한 메모리 위치를 가리키는데, &연산자를 통해서 참조 가능하다.
	// 우측값은 좌측값이 아닌 값들.

	// 좌측값들
	//
	int i = 42;
	i = 43;            // ok, i 는 좌측값
	int* p = &i;       //&i 를 쓸 수 있다.
	int& foo();        // int& 을 리턴하는 함수
	foo() = 42;        // ok, foo() 는 좌측값
	int* p1 = &foo();  // ok, &foo() 를 할 수 있다.
	++i;

	// 우측값들
	//
	int foobar();  // int 를 리턴하는 함수
	int j = 0;
	j = foobar();         // ok. foobar() 는 우측값이다
	//int* p2 = &foobar();  // error. 우측값의 주소는 참조할 수 없다.
	j = 42;               // 42 는 우측값이다.
	j++;

	return 0;

	//참고 https://modoocode.com/189
}