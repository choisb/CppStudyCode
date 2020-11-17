#pragma once
#include <iostream>
#include <string>
#include "Body.h"

using namespace std;


class Animation {
private:
	string motion;

public:
	Animation(string);
	int Play(Body*);

};

Animation::Animation(string _motion)
{
	motion = _motion;
}

int Animation::Play(Body* _body)
{
	cout << _body->GetName() << ' ' << motion << endl;
	return 0;
}