#include "Animation.h"
#include "Champion.h"
#include "Body.h"



int main()
{
	Champion* timo = new Champion (10, "Ƽ��", BLUETEAM);
	Animation* runAnim = new Animation("�޷�!");


	// auto�� ������� ���� ���

	timo->Damaged(10);

	Body* body = timo->TryGetBody();
	if (body != 0)
		runAnim->Play(body);










	
	//int indexCount;
	//
	//cout << "index Count�� �Է����ּ���" << endl;
	//cin >> indexCount;

	//int *myArray = new int[indexCount];

	//int myArray[10];


	//for (auto& n : myArray)
	//	n = 10;

	//for (auto n : myArray)
	//	cout << n << ' ';

	




	return 0;
}