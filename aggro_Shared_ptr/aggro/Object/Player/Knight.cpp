#include "framework.h"
#include "Knight.h"

Knight::Knight(int hp, int atk, string name)
	: Player(hp,atk,name)
{
	SOUND->CreKSound();
}

void Knight::Attack(shared_ptr<Creature> other)
{
	if (!other->IsAlive() || !IsAlive())
		return;
	cout << _name << "이 " << other->GetName() << "을 공격! ";
	
	int curAtk = _atk;
	if (rand() % 10 > 5)
	{
		SOUND->MissSound();
		curAtk = 0;
	}
	else
	{
		SOUND->KAtkSound();
	}

	if (other->GetType() == CreatureType::BOSS)
	{
		other->Damged(curAtk, shared_from_this());
	}
	else
	{
		other->Damged(curAtk);
	}

	if (other->IsAlive())
		cout << other->GetName() << "의 남은 체력은 " << other->GetHP() << "입니다." << endl;
}
