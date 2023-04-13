#include "framework.h"
#include "ArkaBall.h"

ArkaBall::ArkaBall()
{
	_ball = make_shared<CircleCollider>(Vector2(700, 500), 5);
}

ArkaBall::~ArkaBall()
{
}

void ArkaBall::Update()
{

	_ball->MoveCenter(_direction * _speed);

	if (_ball->GetCenter().y < (WIN_HEIGHT - FRAME_HEIGHT) * 0.5f + 15 || _ball->GetCenter().y > (WIN_HEIGHT+FRAME_HEIGHT) * 0.5f + 15)
		_direction.y *= -1;
	if (_ball->GetCenter().x < (WIN_WIDTH + FRAME_WIDTH) * 0.5f || _ball->GetCenter().x > (WIN_WIDTH + FRAME_WIDTH) * 0.5f)
		_direction.x *= -1;

	_ball->Update();
}

void ArkaBall::Render(HDC hdc)
{
	_ball->Render(hdc);
}
