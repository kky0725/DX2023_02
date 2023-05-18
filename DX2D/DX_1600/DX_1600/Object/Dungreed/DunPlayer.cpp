#include "framework.h"
#include "DunPlayer.h"
#include "DunBullet.h"

DunPlayer::DunPlayer()
{
	_player = make_shared<Quad>(L"Resource/DunResource/Player.png");
	_item = make_shared<Quad>(L"Resource/DunResource/Item.png");
	_playerT = make_shared<Transform>();

	for (int i = 0; i < 30; i++)
	{
		shared_ptr<DunBullet> bullet = make_shared<DunBullet>();
		_bullets.push_back(bullet);
	}

	_item->GetTransform()->SetParent(_playerT);

	_player->GetTransform()->SetPosition({ 50,100 });
	_item->GetTransform()->SetPosition({ 100,0 });
	_playerT->SetPosition(_player->GetTransform()->GetPos());

}

DunPlayer::~DunPlayer()
{
}

void DunPlayer::Fire()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x0001)
	{
		auto iter = std::find_if(_bullets.begin(), _bullets.end(),
			[](const shared_ptr<DunBullet>& bullet)-> bool
		{
			if (bullet->IsAtcive() == false)
				return true;
			return false;
		});

		Vector2 temp = mousePos - _item->GetTransform()->GetWorldPosition();
		if (iter != _bullets.end())
		{
			(*iter)->Shoot(temp.NormalVector2(), _item->GetTransform()->GetWorldPosition(), 0.1f, temp.Angle());
		}
	}
}

void DunPlayer::Update()
{
	_item->GetTransform()->SetAngel(radian);

	Vector2 temp = mousePos - _playerT->GetPos();
	_playerT->SetAngel(temp.Angle());

	_player->Update();
	_item->Update();
	_playerT->Update();
	for (auto& bullet : _bullets)
	{
		bullet->Update();
	}
	Fire();

}

void DunPlayer::Render()
{
	_player->Render();
	_item->Render();
	for (auto& bullet : _bullets)
	{
		if(bullet->IsAtcive())
			bullet->Render();
	}
}

