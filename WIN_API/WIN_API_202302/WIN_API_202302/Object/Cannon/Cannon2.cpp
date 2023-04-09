#include "framework.h"
#include "Cannon2.h"

void Cannon2::Move()
{
	if (GetAsyncKeyState('A'))
	{
		_body->MoveCenter(Vector2(-1.0f, 0.0f));
	}
	if (GetAsyncKeyState('D'))
	{
		_body->MoveCenter(Vector2(1.0f, 0.0f));
	}

	_muzzle->_start = _body->GetCenter();
	_muzzle->_end = _muzzle->_start + _muzzleDir * _muzzleLength;
}

void Cannon2::Angle()
{
	if (GetAsyncKeyState('W'))
	{
		_muzzleAngle += 0.1f;
	}

	if (GetAsyncKeyState('S'))
	{
		_muzzleAngle -= 0.1f;
	}

	_muzzleDir = Vector2(cosf(_muzzleAngle), sinf(_muzzleAngle));
}

void Cannon2::Fire()
{
	if (GetAsyncKeyState(VK_SHIFT))
	{
		auto iter = std::find_if(_bullets.begin(), _bullets.end(),
			[](const shared_ptr<Bullet>& bullet)-> bool
			{
				if (bullet->IsAtcive() == false)
					return true;
				return false;
			});

		if (iter != _bullets.end())
		{
			(*iter)->SetPos(_muzzle->_end);
			(*iter)->Shoot(_muzzleDir.NormalVector2(), 10.0f);
		}
	}
}
