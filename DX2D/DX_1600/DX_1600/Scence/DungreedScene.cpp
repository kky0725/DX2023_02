#include "framework.h"
#include "DungreedScene.h"

#include "../Object/Dungreed/DunPlayer.h"
#include "../Object/Dungreed/DunBullet.h"
#include "../Object/Dungreed/DunMonster.h"
#include "../Object/Dungreed/DunPlayer_Advanced.h"

DungreedScene::DungreedScene()
{
	_player = make_shared<DunPlayer_Advanced>();
	_monster = make_shared<DunMonster>();
	//_ground = make_shared<Quad>(L"Resource/DunResource/Map1.png");
	_groundCollider = make_shared<RectCollider>(Vector2((float)WIN_WIDTH, 100.0f));

	//_ground->GetTransform()->SetParent(_groundCollider->GetTransform());

	_player->SetTarget(_monster);
	//_ground->GetTransform()->SetPosition(CENTER);
	_groundCollider->GetTransform()->SetPosition(Vector2(0, -100));
	_groundCollider->SetScale(Vector2(1.0f, 0.3f));

	//_ground->GetTransform()->SetScale(Vector2(3.5f, 2.0f));
}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::Collider_Update()
{
	_player->Collider_Update();
	_groundCollider->Update();
	_monster->Collider_Update();
}

void DungreedScene::Update()
{
	//_ground->Update();
	_monster->Update();
	_player->Update();

	_player->SetFalling(!_groundCollider->Block(_player->GetCollider()));
}

void DungreedScene::Render()
{
	//_ground->Render();
	_player->Render();
	_monster->Render();

	_groundCollider->Render();
}

void DungreedScene::PostRender()
{
	ImGui::Text("mouseX : %d, mouseY : %d", (int)MOUSE_POS.x, (int)MOUSE_POS.y);
	ImGui::Text("monster HP : %d", _monster->GetHp());
}
