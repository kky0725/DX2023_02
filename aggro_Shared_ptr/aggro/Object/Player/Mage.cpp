#include "framework.h"
#include "Mage.h"

Mage::Mage(int hp, int atk, string name)
	: Player(hp, atk, name)
{
	SOUND->CreMSound();
}

void Mage::Attack(shared_ptr<Creature> other)
{
	if (!other->IsAlive() || !IsAlive())
		return;
	cout << _name << "이 " << other->GetName() << "을 공격! ";

	int curAtk = _atk;
	if (_mp >= 60)
	{
		curAtk = 100;
		_mp -= 60;
		SOUND->FireBallSound();
	}
	else
	{
		SOUND->MAtkSound();
	}

	if (other->GetType() == CreatureType::BOSS)
	{
		other->Damged(curAtk, shared_from_this());
	}
	else
	{
		other->Damged(curAtk);
	}
	_mp += 40;

	if (other->IsAlive())
		cout << other->GetName() << "의 남은 체력은 " << other->GetHP() << "입니다." << endl;
}
