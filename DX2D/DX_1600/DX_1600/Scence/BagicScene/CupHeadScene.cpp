#include "framework.h"
#include "CupHeadScene.h"

#include "../../Object/CupHead/Cup_Player.h"
#include "../../Object/CupHead/Cup_Boss.h"
#include "../../Object/CupHead/Cup_Track.h"

CupHeadScene::CupHeadScene()
{
	_player = make_shared<Cup_Player>();
	_player->SetPosition(Vector2(0,0));

	_boss = make_shared<Cup_Boss>();
	
	for (int i = 0; i < 3; i++)
	{
		shared_ptr<Cup_Track> track = make_shared<Cup_Track>(Vector2(CENTER.x * i * 2, CENTER.y * -1.0f + i * 50.0f));
		_tracks.push_back(track);
	}

	CAMERA->SetTarget(_player->GetTransform());
	CAMERA->SetLeftBottom(Vector2(-_tracks[0]->GetTrackSize().x, -1000.0f));
	CAMERA->SetRightTop(Vector2(_tracks[0]->GetTrackSize().x * 6, 1000.0f));
}

CupHeadScene::~CupHeadScene()
{
}

void CupHeadScene::Update()
{
	_player->Update();
	_boss->Update();
	for (auto track : _tracks)
	{
		track->Update();
	}

	if(_player->GetHp() > 0)
		_boss->Fire(_player->GetCollider()->GetTransform()->GetWorldPosition());
	CheckAttack();

	for (auto track : _tracks)
	{
		if (track->GetCollider()->Block(_player->GetCollider()))
		{
			_player->SetGrounded();
		}
	}

}

void CupHeadScene::Render()
{
	for (auto track : _tracks)
	{
		track->Render();
	}

	_boss->Render();
	_player->Render();
}

void CupHeadScene::PostRender()
{
	ImGui::Text("Boss HP: %d", _boss->GetHp());
	ImGui::Text("Cup HP: %d", _player->GetHp());

	if(ImGui::Button("TargetON", ImVec2(100, 50)))
	{
		CAMERA->SetTarget(_player->GetTransform());
	}

	if (ImGui::Button("TargetOFF", ImVec2(100, 50)))
	{
		CAMERA->SetTarget(nullptr);
	}

	if (ImGui::Button("Save", ImVec2(50, 50)))
	{
		Save();
	}

	if (ImGui::Button("Load", ImVec2(50, 50)))
	{
		Load();
	}
}

void CupHeadScene::CheckAttack()
{
	if (!_boss->IsAtcive() || !_player->IsAtcive())
		return;

	if (!_player->IsAlive())
		return;

	if (_player->IsCollision_Bullets(_boss->GetCollider()))
	{
		_boss->Damaged(1);
	}

	//if (_boss->IsCollision_Bullets(_player->GetCollider()))
	//{
	//	_player->Damaged(1);
	//}
}

void CupHeadScene::Save()
{
	BinaryWriter writer = BinaryWriter(L"save/test.test");
	writer.Int(1);

	Vector2 playerPos = _player->GetCollider()->GetTransform()->GetWorldPosition();

	writer.String("PlayerPos");
	writer.Byte(&playerPos, sizeof(Vector2));

	int bossHp = _boss->GetHp();
	writer.Int(bossHp);
}

void CupHeadScene::Load()
{
	BinaryReader reader = BinaryReader(L"save/test.test");
	int temp = reader.Int();

	string str = reader.String();
	assert(str == "PlayerPos");

	Vector2 playerPos;
	Vector2* ptr = &playerPos;
	reader.Byte((void**)&ptr, sizeof(Vector2));

	_player->SetPosition(playerPos);
	
	temp = reader.Int();
	_boss->SetHp(temp);
}
