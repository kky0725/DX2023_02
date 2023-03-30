#include "framework.h"
#include "BossMonster.h"

BossMonster::BossMonster(int hp, int atk, string name)
	:Monster(hp, atk, name)
{
	_type = CreatureType::BOSS;
}

void BossMonster::Attack(shared_ptr<Creature> other)
{
	if (!IsAlive() || !other->IsAlive())
		return;
	cout << _name << "이 " << other->GetName() << "을 공격! ";
	SOUND->MoAtkSound();
	other->Damged(this->_atk);

	if (other->IsAlive())
		cout << other->GetName() << "의 남은 체력은 " << other->GetHP() << "입니다." << endl;

}

void BossMonster::Damged(int amount, shared_ptr<Creature> attacker)
{
	Creature::Damged(amount);

	string name = attacker->GetName();
	auto iter = std::find_if(_aggroTable.begin(), _aggroTable.end(), [name](const AggroInfo& info)->bool
		{
			if (info.attacker->GetName() == name)
				return true;
			return false;
		});

	if (iter != _aggroTable.end())
	{
		iter->totalDamage += amount;
	}
	else
	{
		AggroInfo info;
		info.attacker = attacker;
		info.totalDamage = amount;

		_aggroTable.push_back(info);
	}
}


void BossMonster::AtkPlayerByAggroInfo()
{
	auto iter = std::remove_if(_aggroTable.begin(), _aggroTable.end(), [](const AggroInfo& info)->bool
		{
			if (info.attacker->IsAlive())
				return false;
			return true;
		});

	_aggroTable.erase(iter, _aggroTable.end());

	int count = 0;

	for (auto& info : _aggroTable)
	{
		if (count >= _range)
			break;

		Attack(info.attacker);
		count++;
	}
}
