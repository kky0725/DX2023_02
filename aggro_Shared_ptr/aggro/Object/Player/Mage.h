#pragma once
class Mage : public Player, public enable_shared_from_this<Mage>
{
public:
	Mage() {};
	Mage(int hp, int atk, string name);
	virtual ~Mage() {};

	virtual void Attack(shared_ptr<Creature> ohter) override;
private:
	int _mp = 0;
};


