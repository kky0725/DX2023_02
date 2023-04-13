#include "framework.h"
#include "ArkaBall.h"

ArkaBall::ArkaBall()
{
	_circle = make_shared<CircleCollider>(Vector2(700, 500), _radius);
}

ArkaBall::~ArkaBall()
{
}

void ArkaBall::Update()
{

	_circle->MoveCenter(_direction * _speed);

	if (_circle->GetCenter().y < (WIN_HEIGHT - FRAME_HEIGHT) * 0.5f - 15 + _radius /*|| _circle->GetCenter().y > (WIN_HEIGHT+FRAME_HEIGHT) * 0.5f - 15 - _radius*/)
		_direction.y *= -1;
	if (_circle->GetCenter().x < (WIN_WIDTH - FRAME_WIDTH) * 0.5f + _radius || _circle->GetCenter().x > (WIN_WIDTH + FRAME_WIDTH) * 0.5f - _radius)
		_direction.x *= -1;

	_circle->Update();
}

void ArkaBall::Render(HDC hdc)
{
	_circle->Render(hdc);
}
