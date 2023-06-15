#include "framework.h"
#include "CupHeadScene.h"

#include "../../Object/CupHead/Cup_Player.h"
#include "../../Object/CupHead/Cup_Boss.h"

CupHeadScene::CupHeadScene()
{
	_player = make_shared<Cup_Player>();
	_player->SetPosition(CENTER);

	_boss = make_shared<Cup_Boss>();

	_track = make_shared<Quad>(L"Resource/CupHead/track.png");
	_transform = make_shared<Transform>();
	Vector2 trackSize = _track->GetQuadHalfSize();
	_collider = make_shared<RectCollider>(trackSize * 2.0f);

	_transform->SetParent(_collider->GetTransform());
	_transform->SetPosition(Vector2(0, 75));

	Vector2 pos = CENTER;
	pos.y -= 350.0f;
	_collider->GetTransform()->SetPosition(pos);
	_transform->Update();
}

CupHeadScene::~CupHeadScene()
{
}

void CupHeadScene::Update()
{
	_player->Update();
	_boss->Update();
	_boss->Fire(_player->GetCollider()->GetPos());
	_collider->Update();
	CheckAttack();

	if (_collider->Block(_player->GetCollider()))
	{
		_player->SetGrounded();
	}
}

void CupHeadScene::Render()
{
	_transform->SetBuffer(0);
	_track->Render();
	_collider->Render();

	_boss->Render();
	_player->Render();
}

void CupHeadScene::PostRender()
{
	//_player->PosRender();
	ImGui::Text("HP: %d", _boss->GetHp());
}

void CupHeadScene::CheckAttack()
{
	if (!_boss->IsAtcive())
		return;

	if (_player->IsCollision_Bullets(_boss->GetCollider()))
	{
		_boss->Damaged(1);
	}
}
