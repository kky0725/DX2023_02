#include "framework.h"
#include "Player.h"

Player::Player(int hp, int atk, string name)
	:Creature(hp, atk, name)
{
	_type = CreatureType::PLAYER;
}