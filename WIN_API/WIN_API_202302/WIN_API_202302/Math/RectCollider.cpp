#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector2 center, float width, float length)
	: _center(center), _width(width), _length(length)
{
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	float left = _center.x - 0.5*_width;
	float top = _center.y - 0.5 * _length;
	float right = _center.x + 0.5 * _width;
	float bottom = _center.y + 0.5 * _length;
	Rectangle(hdc, left, top, right, bottom);
}

void RectCollider::MoveCenter(const Vector2& value)
{
	_center += value;
}

void RectCollider::SetCenter(const Vector2 value)
{
	_center = value;
}

void RectCollider::SetWidth(float width)
{
	_width = width;
}

void RectCollider::SetLength(float length)
{
	_length = length;
}
