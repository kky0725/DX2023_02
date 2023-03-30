#pragma once
class World
{
public:
	World();
	~World() {}

	void Battle();

	bool End();

	int Random(int min, int max) { return rand() % (max - min + 1) + min; };

private:
	vector <shared_ptr<Creature>> _players;
	shared_ptr<Creature> _boss;

};

