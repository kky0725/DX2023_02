#pragma once
class Monster : public Creature
{
public:
	Monster() {};
	Monster(int hp, int atk, string name);
	virtual ~Monster() {};

	virtual void Attack(shared_ptr<Creature> other) override;

private:

};


