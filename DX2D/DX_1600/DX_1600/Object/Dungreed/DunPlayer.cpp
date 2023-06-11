#include "framework.h"
#include "DunPlayer.h"
#include "DunBullet.h"
#include "DunMonster.h"

DunPlayer::DunPlayer()
{
	_quad = make_shared<Quad>(L"Resource/DunResource/Player.png");
	_bow = make_shared<Quad>(L"Resource/DunResource/Bow.png");
	_bowSlot = make_shared<Transform>();
	
	_transform = make_shared<Transform>();
	_bowTransform = make_shared<Transform>();

	for (int i = 0; i < 30; i++)
	{
		shared_ptr<DunBullet> bullet = make_shared<DunBullet>();
		_bullets.push_back(bullet);
	}

	_bowTransform->SetParent(_bowSlot);

	_bowTransform->SetPosition({ 100,0 });
	_bowTransform->SetAngel(_radian);
}

DunPlayer::~DunPlayer()
{
}


void DunPlayer::Update()
{
	Fire();

	SetBowAngle();

	_bowSlot->SetPosition(_transform->GetPos());

	_transform->Update();
	_bowTransform->Update();
	_bowSlot->Update();
	for (auto& bullet : _bullets)
	{
		bullet->Update();
	}
	CheckAttack();
}

void DunPlayer::Render()
{
	_transform->SetBuffer(0);
	_quad->Render();
	_bowTransform->SetBuffer(0);
	_bow->Render();
	for (auto& bullet : _bullets)
	{
		if (bullet->IsActive())
			bullet->Render();
	}
}

void DunPlayer::SetBowAngle()
{
	Vector2 temp = MOUSE_POS - GetPos();
	_bowSlot->SetAngel(temp.Angle());
}

void DunPlayer::Fire()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x0001)
	{
		auto bulletIter = std::find_if(_bullets.begin(), _bullets.end(),
			[](const shared_ptr<DunBullet>& obj)-> bool	{return !obj->IsActive();});

		Vector2 dir = MOUSE_POS - GetPos();
		if (bulletIter != _bullets.end())
		{
			(*bulletIter)->Shoot(dir, _bowTransform->GetWorldPosition());
		}
	}
}

void DunPlayer::CheckAttack()
{
	if (_target.expired())
		return;

	if (!_target.lock()->IsAtcive())
		return;

	for (auto& bullet : _bullets)
	{
		if (!bullet->IsActive())
			continue;
		if (bullet->IsCollision(_target.lock()))
		{
			bullet->SetActive(false);
			_target.lock()->Damaged(1);
		}
	}
}


