#include "Animation.h"
#include "Champion.h"
#include "Body.h"



int main()
{
	Champion* timo = new Champion (10, "티모", BLUETEAM);
	Animation* runAnim = new Animation("달려!");


	// auto를 사용하지 않을 경우

	timo->Damaged(10);

	Body* body = timo->TryGetBody();
	if (body != 0)
		runAnim->Play(body);










	
	//int indexCount;
	//
	//cout << "index Count를 입력해주세요" << endl;
	//cin >> indexCount;

	//int *myArray = new int[indexCount];

	//int myArray[10];


	//for (auto& n : myArray)
	//	n = 10;

	//for (auto n : myArray)
	//	cout << n << ' ';

	




	return 0;
}