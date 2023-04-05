#include "framework.h"
#include "Collider.h"

Collider::Collider(Vector2 center)
	: _center(center)
{
	HPEN green = CreatePen(PS_SOLID, 3, GREEN);
	HPEN red = CreatePen(PS_SOLID, 3, RED);
	HPEN blue = CreatePen(PS_SOLID, 3, BLUE);
	HPEN black = CreatePen(PS_SOLID, 3, BLACK);
	_pens.push_back(green);
	_pens.push_back(red);
	_pens.push_back(blue);
	_pens.push_back(black);
}

Collider::~Collider()
{
	for (auto& pen : _pens)
		DeleteObject(pen);
}

void Collider::MoveCenter(const Vector2& value)
{
	_center += value;
}

void Collider::SetCenter(const Vector2 value)
{
	_center = value;
}

bool Collider::IsCollision(shared_ptr<Collider> col)
{
	switch (col->_type)
	{
	case Collider::ColliderType::NONE:
		return false;
		break;
	case Collider::ColliderType::CIRCLE:
	{
		shared_ptr<CircleCollider> circle = dynamic_pointer_cast<CircleCollider>(col);
		return IsCollision(circle);
		break;
	}
		case Collider::ColliderType::RECT:
	{
		shared_ptr<RectCollider> rect = dynamic_pointer_cast<RectCollider>(col);
		return IsCollision(rect);
		break;
	}
	default:
		break;
	}
	return false;
}

