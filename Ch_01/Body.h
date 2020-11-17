#pragma once
#include <string>
using namespace std;

class Body
{
private:
	int hp;
	string name;


protected:
	Body* GetBodyIncetance();
	Body(int, string);


public:
	string GetName();
	void Damaged(int);



};

Body::Body(int _hp, string _name)
{
	hp = _hp;
	name = _name;

}
void Body::Damaged(int _damage)
{
	hp -= _damage;
}


Body* Body::GetBodyIncetance()
{
	if (hp > 0)
		return this;
	else
		return 0;
}

string Body::GetName()
{
	return name;
}