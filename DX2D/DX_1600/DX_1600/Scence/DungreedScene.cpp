#include "framework.h"
#include "DungreedScene.h"

#include "../Object/Dungreed/DunPlayer.h"
#include "../Object/Dungreed/DunBullet.h"
#include "../Object/Dungreed/DunMonster.h"

DungreedScene::DungreedScene()
{
	_player = make_shared<DunPlayer>();
	_monster = make_shared<DunMonster>();
	_ground = make_shared<Quad>(L"Resource/DunResource/Map1.png");
	_groundCollider = make_shared<RectCollider>(_ground->GetImageSize());

	_groundCollider->GetTransform()->SetParent(_ground->GetTransform());

	_player->SetTarget(_monster);
	_ground->GetTransform()->SetPosition(CENTER);
	_groundCollider->GetTransform()->SetPosition(Vector2(0, -100));
	_groundCollider->SetScale(Vector2(1.0f, 0.3f));

	_ground->GetTransform()->SetScale(Vector2(3.5f, 2.0f));
}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::Update()
{
	if (KEY_PRESS('A'))
	{
		Vector2 movePos = Vector2(-500.0f, 0.0f) * DELTA_TIME;
		_player->Move(movePos);
	}

	if (KEY_PRESS('D'))
	{
		Vector2 movePos = Vector2(500.0f, 0.0f) * DELTA_TIME;
		_player->Move(movePos);
	}

	_ground->Update();
	_groundCollider->Update();
	_monster->Update();
	_player->Update();

	if (_groundCollider->Block(_player->GetCollider()))
		_player->SetPosition(_player->GetCollider()->GetPos());
}

void DungreedScene::Render()
{
	_ground->Render();
	_player->Render();
	_monster->Render();

	_groundCollider->Render();
}

void DungreedScene::PostRender()
{
	ImGui::Text("mouseX : %d, mouseY : %d", (int)MOUSE_POS.x, (int)MOUSE_POS.y);
	ImGui::Text("monster HP : %d", _monster->GetHp());
}
