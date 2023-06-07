#include "framework.h"
#include "Zelda_Player.h"

#include "Link_Ani.h"

Zelda_Player::Zelda_Player()
{
	shared_ptr<SRV> srv = ADD_SRV(L"Resource/zelda_sprite.png");
	Vector2 imageSize = srv->GetImageSize();
	Vector2 maxFrame = { 10, 8 };
	float w = imageSize.x / maxFrame.x;
	float h = imageSize.y / maxFrame.y;

	_animation = make_shared<Link_Ani>();
	_collider = make_shared<RectCollider>(Vector2(w,h));

	_animation->SetParent(_collider->GetTransform());
	_collider->SetPosition(CENTER);
}

Zelda_Player::~Zelda_Player()
{
}

void Zelda_Player::Update()
{
	Input();
	_animation->Update();
	_collider->Update();
}

void Zelda_Player::Render()
{
	_animation->Render();
	_collider->Render();
}

void Zelda_Player::PostRender()
{
	ImGui::Text("HP : %d", _hp);
}

void Zelda_Player::Input()
{
	if (KEY_PRESS('S'))
	{
		Vector2 movePos = Vector2(0.0f, -_speed) * DELTA_TIME;
		Move(movePos);
	}

	if (KEY_PRESS('A'))
	{
		Vector2 movePos = Vector2(-_speed, 0.0f) * DELTA_TIME;
		Move(movePos);
	}

	if (KEY_PRESS('W'))
	{
		Vector2 movePos = Vector2(0.0f, _speed) * DELTA_TIME;
		Move(movePos);
	}

	if (KEY_PRESS('D'))
	{
		Vector2 movePos = Vector2(_speed, 0.0f) * DELTA_TIME;
		Move(movePos);
	}
}
