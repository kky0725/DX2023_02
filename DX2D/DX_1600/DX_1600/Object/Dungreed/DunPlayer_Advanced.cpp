#include "framework.h"
#include "DunPlayer_Advanced.h"
#include "DunPlayer.h"
#include "DunBullet.h"

DunPlayer_Advanced::DunPlayer_Advanced()
{
	_collider = make_shared<CircleCollider>(50.0f);

	_player->GetTransform()->SetParent(_collider->GetTransform());
	_bowSlot->SetParent(_collider->GetTransform());
}

DunPlayer_Advanced::~DunPlayer_Advanced()
{
}

void DunPlayer_Advanced::Collider_Update()
{
	for (auto bullet : _bullets)
		bullet->Collider_Update();

	_collider->Update();
}

void DunPlayer_Advanced::Update()
{
	_collider->Update();

	Input();
	Falling();

	DunPlayer::Update();
}

void DunPlayer_Advanced::Render()
{
	DunPlayer::Render();
	_collider->Render();
}

void DunPlayer_Advanced::Input()
{
	if (KEY_PRESS('A'))
	{
		Vector2 movePos = Vector2(-500.0f, 0.0f) * DELTA_TIME;
		Move(movePos);
	}

	if (KEY_PRESS('D'))
	{
		Vector2 movePos = Vector2(500.0f, 0.0f) * DELTA_TIME;
		Move(movePos);
	}
}

void DunPlayer_Advanced::Falling()
{
	
	if (!_isFalling)
	{	
		_fallingVec = { 0.0f, 0.0f };
		return;
	}

	_fallingVec.y -=  GRAVITY * DELTA_TIME;
	Move(_fallingVec);
}
