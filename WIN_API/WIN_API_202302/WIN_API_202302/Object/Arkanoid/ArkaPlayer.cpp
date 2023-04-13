#include "framework.h"
#include "ArkaPlayer.h"

ArkaPlayer::ArkaPlayer()
{
	_rect = make_shared<RectCollider>(Vector2(WIN_WIDTH * 0.5f, 600.0f), Vector2(_barWidth, _barHeight));
	_isControlled = true;
	_ball = make_shared<ArkaBall>();

	_brush = CreateSolidBrush(CYAN);
}

ArkaPlayer::~ArkaPlayer()
{
	DeleteObject(_brush);
}

void ArkaPlayer::Move()
{
	if (_rect->GetCenter().x < (WIN_WIDTH + FRAME_WIDTH - _barWidth) * 0.5f)
	{
		if (GetAsyncKeyState(VK_RIGHT))
		{
			_rect->MoveCenter(Vector2(1, 0) * _speed);
		}
	}

	if (_rect->GetCenter().x > (WIN_WIDTH - FRAME_WIDTH + _barWidth) * 0.5f)
	{
		if (GetAsyncKeyState(VK_LEFT))
		{
			_rect->MoveCenter(Vector2(-1, 0) * _speed);
		}
	}

	if (!_ball->IsActive())
	{
		_ball->SetDir(Vector2(0.0f, 0.0f));
		float radius = dynamic_pointer_cast<CircleCollider>(_ball->GetCollider())->GetRadius();
		_ball->GetCollider()->SetCenter(Vector2(_rect->GetCenter().x, _rect->GetCenter().y - radius - _barHeight * 0.5f));
	}
}

void ArkaPlayer::Shoot()
{
	if (!_ball->IsActive())
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			_ball->SetActive(true);
			_ball->SetDir(Vector2(0.0f, -1.0f));
		}
	}
}

void ArkaPlayer::ReflectBall()
{
	if (_rect->IsCollision(_ball->GetCollider()))
	{
		Vector2 newDir = _ball->GetCollider()->GetCenter() - _rect->GetCenter();
		_ball->SetDir(newDir.NormalVector2());
	}
}

void ArkaPlayer::Dead()
{
	float radius = dynamic_pointer_cast<CircleCollider>(_ball->GetCollider())->GetRadius();
	if (_ball->GetCollider()->GetCenter().y > (WIN_HEIGHT + FRAME_HEIGHT) * 0.5f - 15 - radius)
	{
		if (_life != 0)
		{
			_ball->SetActive(false);
			_life--;
		}
	}
}

void ArkaPlayer::Update()
{
	if (_life == 0)
		_isControlled = false;

	if (_isControlled)
	{
		Move();
		Shoot();
		ReflectBall();
		Dead();
	}
	_rect->Update();
	_ball->Update();
}

void ArkaPlayer::Render(HDC hdc)
{
	SelectObject(hdc, _brush);
	_rect->Render(hdc);
	_ball->Render(hdc);
}


