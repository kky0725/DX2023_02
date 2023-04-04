#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector2 center, Vector2 size)
	: _center(center), _size(size), _halfSize(size * 0.5f)
{
	HPEN green = CreatePen(PS_SOLID, 1, GREEN);
	HPEN red = CreatePen(PS_SOLID, 1, RED);
	_pens.push_back(green);
	_pens.push_back(red);
}

RectCollider::~RectCollider()
{
	for (auto& pen : _pens)
		DeleteObject(pen);
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPenIndex]);

	float left		= _center.x -_halfSize.x;
	float top		= _center.y -_halfSize.y;
	float right		= _center.x +_halfSize.x;
	float bottom	= _center.y +_halfSize.y;
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

void RectCollider::SetSize(Vector2 size)
{
	_size = size;
	_halfSize = _size * 0.5f;
}

bool RectCollider::IsCollision(Vector2 pos)
{
	if (pos.x < Left() || pos.x > Right())
		return false;
	else if (pos.y < Top() || pos.y > Bottom())
		return false;
	return true;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{

	return false;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	float sumWidth = _halfSize.x + other->GetSize().x * 0.5f;
	float sumHeight = _halfSize.y + other->GetSize().y * 0.5f;
	float disWidth = abs(_center.x - other->GetCenter().x);
	float disHeight = abs(_center.y - other->GetCenter().y);
	return (sumWidth > disWidth) && (sumHeight < disHeight);
}

