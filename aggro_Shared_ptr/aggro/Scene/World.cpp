#include "framework.h"
#include "World.h"

World::World()
{
	_boss = make_shared<BossMonster>(5000, 40, "고블린 킹");
	for (int i = 0; i < 10; i++)
	{
		shared_ptr<Creature> _player;
		string job;
		switch (rand() % 3)
		{
		case 0:
		{
			job = "Knight" + to_string(i + 1);
			_player = make_shared<Knight>(Random(300, 400), Random(40, 50), job);
			break;
		}
		case 1:
		{
			job = "Mage" + to_string(i + 1);
			_player = make_shared<Mage>(Random(200, 300), Random(10, 20), job);
			break;
		}
		case 2:
		{
			job = "Archer" + to_string(i + 1);
			_player = make_shared<Archer>(Random(200, 300), Random(30, 40), job);
			break;
		}
		}
		_players.push_back(_player);
	}
}

void World::Battle()
{
	cout << endl;
	for (auto& player : _players)
	{
		player->Attack(_boss);
	}

	cout << endl;
	dynamic_pointer_cast<BossMonster>(_boss)->AtkPlayerByAggroInfo();
}

bool World::End()
{
	bool playerAll_Dead = true;

	for (auto& player : _players)
	{
		if (player->IsAlive())
		{
			playerAll_Dead = false;
			break;
		}
	}

	return playerAll_Dead || !_boss->IsAlive();
}
