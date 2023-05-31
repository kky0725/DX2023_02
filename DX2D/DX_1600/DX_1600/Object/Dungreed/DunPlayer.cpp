#include "framework.h"
#include "DunPlayer.h"
#include "DunBullet.h"
#include "DunMonster.h"

DunPlayer::DunPlayer()
{
	_player = make_shared<Quad>(L"Resource/DunResource/Player.png");
	_bow = make_shared<Quad>(L"Resource/DunResource/Bow.png");
	_bowSlot = make_shared<Transform>();

	for (int i = 0; i < 30; i++)
	{
		shared_ptr<DunBullet> bullet = make_shared<DunBullet>();
		_bullets.push_back(bullet);
	}

	_bow->GetTransform()->SetParent(_bowSlot);

	_bow->GetTransform()->SetPosition({ 100,0 });
	_bow->GetTransform()->SetAngel(_radian);
}

DunPlayer::~DunPlayer()
{
}

void DunPlayer::SetBowAngle()
{
	Vector2 temp = MOUSE_POS - _bowSlot->GetPos();
	_bowSlot->SetAngel(temp.Angle());
}

void DunPlayer::Fire()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x0001)
	{
		auto bulletIter = std::find_if(_bullets.begin(), _bullets.end(),
			[](const shared_ptr<DunBullet>& obj)-> bool	{return !obj->IsAtcive();});

		Vector2 dir = MOUSE_POS - _bowSlot->GetPos();
		if (bulletIter != _bullets.end())
		{
			(*bulletIter)->Shoot(dir, _bow->GetTransform()->GetWorldPosition());
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
		if (!bullet->IsAtcive())
			continue;
		if (bullet->IsCollision(_target.lock()))
		{
			bullet->SetActive(false);
			_target.lock()->Damaged(1);
		}
	}
}

void DunPlayer::Update()
{
	SetBowAngle();

	_player->Update();
	_bow->Update();
	_bowSlot->Update();
	Fire();
	for (auto& bullet : _bullets)
	{
		bullet->Update();
	}
	CheckAttack();
}

void DunPlayer::Render()
{
	_player->Render();
	_bow->Render();
	for (auto& bullet : _bullets)
	{
		if(bullet->IsAtcive())
			bullet->Render();
	}
}

