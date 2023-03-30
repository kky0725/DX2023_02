#include "framework.h"
#include "Creature.h"

void Creature::PrintInfo()
{
	if (!_isAlive) return;
	cout << "이름: " << _name << endl;
	cout << "체력: " << _hp << endl;
	cout << "공격력: " << _atk << endl;
}

void Creature::Damged(int amount, shared_ptr<Creature> attacker)
{
	if (amount <= 0 || !_isAlive)
		return;

	_hp -= amount;

	if (_hp <= 0)
	{
		cout << _name << "은 죽었습니다." << endl;
		_hp = 0;
		_isAlive = false;
	}

}
