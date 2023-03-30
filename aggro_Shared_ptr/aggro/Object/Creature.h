#pragma once
class Creature
{
public:
	Creature() : _hp(0), _atk(0), _name(" ") {};
	Creature(int hp, int atk, string name): _hp(hp), _atk(atk), _name(name) {};
	virtual ~Creature() {};

	void SetInfo(int hp, int atk, string name) { if (this == nullptr) return; _hp = hp; _atk = atk; _name = name; };
	void PrintInfo();

	virtual void Damged(int amount, shared_ptr<Creature> attacker = nullptr);
	virtual void Attack(shared_ptr<Creature> other) = 0;
	bool IsAlive() const { return _isAlive; }
	const int GetHP() const { return _hp; }
	const int GetAtk() const { return _atk; }
	const string& GetName() const { return _name; }
	const CreatureType GetType() const { return _type; }

protected:
	int _hp;
	int _atk;
	string _name;

	int _aggro = 0;
	bool _isAlive = true;
	CreatureType _type = CreatureType::NONE;
};