#include "framework.h"
#include "Monster.h"

Monster::Monster(int hp, int atk, string name)
	:Creature(hp, atk, name)
{
	SOUND->CreMoSound();
}

void Monster::Attack(shared_ptr<Creature> other)
{
	if (!other->IsAlive()|| !IsAlive())
		return;
	cout << _name << "이 " << other->GetName() << "을 공격! ";
	SOUND->MoAtkSound();
	other->Damged(this->_atk);

	if (other->IsAlive())
		cout << other->GetName() << "의 남은 체력은 " << other->GetHP() << "입니다." << endl;
}