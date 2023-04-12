#include "framework.h"
#include "ArkaBar.h"

ArkaBar::ArkaBar()
{
	_rect = make_shared<RectCollider>(Vector2(WIN_WIDTH * 0.5f, 600.0f), Vector2(_barWidth, _barHeight));
	_isControlled = true;

	_brush = CreateSolidBrush(CYAN);
}

ArkaBar::~ArkaBar()
{
	DeleteObject(_brush);
}

void ArkaBar::Move()
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
}

void ArkaBar::Shoot()
{
}

void ArkaBar::Update()
{
	if (_isControlled)
	{
		Move();
	}
	_rect->Update();
}

void ArkaBar::Render(HDC hdc)
{
	SelectObject(hdc, _brush);
	_rect->Render(hdc);
}
