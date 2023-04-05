#include "framework.h"
#include "Line.h"

void Line::Update()
{
}

void Line::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPenIndex]);

	MoveToEx(hdc, _start.x, _start.y, nullptr);
	LineTo(hdc, _end.x, _end.y);
}

bool Line::IsCollision(Vector2 pos)
{
	return false;
}

bool Line::IsCollision(shared_ptr<CircleCollider> other)
{
	return false;
}

bool Line::IsCollision(shared_ptr<RectCollider> other)
{
	return false;
}
