#include "framework.h"
#include "SoundManager.h"

SoundManager* SoundManager::_instance = nullptr;
SoundManager::SoundManager()
{
	_playerAtkSound = "(플레이어가 공격하는 소리)";
	_knightAtkSound = "(기사가 공격하는 소리)";
	_mageAtkSound = "(마법사가 공격하는 소리)";
	_archerAtkSound = "(궁수가 공격하는 소리)";
	_monsterAtkSound = "(몬스터가 공격하는 소리)";

	_createPlayerSound = "(플레이어가 생성되는 소리)";
	_createKinghtSound = "(기사가 생성되는 소리)";
	_createMageSound = "(마법사가 생성되는 소리)";
	_createArcherSound = "(궁수가 생성되는 소리)";
	_createMonsterSound = "(몬스터가 생성되는 소리)";

	_fireBall = "파이어 볼!!";
	_critical = "치명타!!";
	_miss = "빗나감!!";
}
