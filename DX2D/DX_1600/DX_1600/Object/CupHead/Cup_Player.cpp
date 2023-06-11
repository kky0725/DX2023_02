#include "framework.h"
#include "Cup_Player.h"
#include "Cup_Ani.h"
#include "Cup_Bullet.h"

using namespace tinyxml2;

Cup_Player::Cup_Player()
{
	_collider = make_shared<CircleCollider>(50.0f);
	_animation = make_shared<Cup_Ani>();

	for (int i = 0; i < 30; i++)
	{
		shared_ptr<Cup_Bullet> bullet = make_shared<Cup_Bullet>();
		_bullets.push_back(bullet);
	}

	_animation->SetParent(_collider->GetTransform());
}

Cup_Player::~Cup_Player()
{
}

void Cup_Player::Update()
{
	Input();
	_collider->Update();
	_animation->Update();
	for(auto& bullet : _bullets)
		bullet->Update();
}

void Cup_Player::Render()
{
	_animation->Render();
	for(auto& bullet : _bullets)
		bullet->Render();
	_collider->Render();
}

void Cup_Player::PosRender()
{

}


void Cup_Player::Input()
{
	if (KEY_PRESS(VK_LEFT))
	{
		Vector2 movePos = Vector2(-_speed, 0.0f) * DELTA_TIME;
		Move(movePos);
	}

	if (KEY_PRESS(VK_RIGHT))
	{
		Vector2 movePos = Vector2(_speed, 0.0f) * DELTA_TIME;
		Move(movePos);
	}

	Fire();

	Jump();
}

void Cup_Player::Fire()
{
	if (_atkCool)
	{
		_time += DELTA_TIME;
		if (_time > _atkSpeed)
		{
			_time = 0.0f;
			_atkCool = false;
		}
		return;
	}




	if (KEY_PRESS('X'))
	{
		auto bulletIter = std::find_if(_bullets.begin(), _bullets.end(),
			[](const shared_ptr<Cup_Bullet>& obj)-> bool {return !obj->IsActive(); });

		if (bulletIter == _bullets.end())
			return;

		_atkCool = true;
		Vector2 startPos = _collider->GetPos();
		if (_animation->GetIsRight())
		{
			startPos += Vector2(50, 0);
			(*bulletIter)->SetRight();
			(*bulletIter)->Shoot(Vector2(1, 0), startPos);
		}
		else
		{
			startPos += Vector2(-50, 0);
			(*bulletIter)->SetLeft();
			(*bulletIter)->Shoot(Vector2(-1, 0), startPos);
		}


	}

}

void Cup_Player::Jump()
{
	// 중력적용
	{
		_jumpPower -= 15.0f;

		if (_jumpPower < -600.0f)
			_jumpPower = -600.0f;

		_collider->GetTransform()->AddVector2(Vector2(0.0f, 1.0f) * _jumpPower * DELTA_TIME);
	}

	if (KEY_DOWN('Z') && _animation->GetISGround())
	{
		_jumpPower = 600.0f;
		_animation->SetIsGround(false);
	}
}

bool Cup_Player::IsCollision_Bullets(shared_ptr<Collider> col)
{
	for (auto bullet : _bullets)
	{
		if (!bullet->IsActive())
			continue;

		if (col->IsCollision(bullet->GetCollider()))
		{
			bullet->SetActive(false);
			return true;
		}
	}
	return false;
}


void Cup_Player::SetGrounded()
{
	if (!_animation->GetISGround() && _jumpPower < 0)
	{
		_animation->EndEvent();
		_animation->SetIsGround(true);
	}
}
