#pragma once
class BossMonster : public Monster
{
public:
	struct AggroInfo
	{
		shared_ptr<Creature> attacker;
		int totalDamage;

		bool operator<(const AggroInfo& other) const { return totalDamage < other.totalDamage; }
		bool operator>(const AggroInfo& other) const { return totalDamage > other.totalDamage; }
	};

	BossMonster(int hp, int atk, string name);
	virtual ~BossMonster() {}

	virtual void Attack(shared_ptr<Creature> other) override;
	virtual void Damged(int amount, shared_ptr<Creature> attacker = nullptr) override;

	void AtkPlayerByAggroInfo();
private:
	vector<AggroInfo> _aggroTable;
	int _range = 4;
};

