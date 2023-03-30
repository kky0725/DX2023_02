#pragma once
#define SOUND SoundManager::GetInstance()

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

enum class CreatureType
{
	NONE,
	PLAYER,
	MONSTER,
	BOSS
};

#include "Object/SoundManager.h"
#include "Object/Creature.h"

#include "Object/Player/Player.h"
#include "Object/Player/Knight.h"
#include "Object/Player/Mage.h"
#include "Object/Player/Archer.h"

#include "Object/Monster/Monster.h"
#include "Object/Monster/BossMonster.h"

#include "Scene/World.h"

