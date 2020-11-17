#pragma once
#include <string>
#include "Body.h"

#define BLUETEAM 0
#define REDTEAM 1

using namespace std;

class Champion : public Body {

private:
	bool team;

public:
	Champion(int, string, bool);
	Body* TryGetBody();
};

Champion::Champion(int _hp, string _name, bool _team) : Body(_hp, _name)
{
	team = _team;
}

Body* Champion::TryGetBody()
{
	return Body::GetBodyIncetance();
}