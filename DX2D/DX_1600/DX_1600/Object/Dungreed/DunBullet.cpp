#include "framework.h"
#include "DunBullet.h"

DunBullet::DunBullet()
{
	_bullet = make_shared<Quad>(L"Resource/DunResource/Bullet.png");
	_bullet->GetTransform()->SetScale({ 0.05f,0.05f });
}

DunBullet::~DunBullet()
{
}

void DunBullet::Shoot(const Vector2& dir, const Vector2 startPos, float speed)
{
	_isActive = true;
	_direction = dir.NormalVector2();
	_speed = speed;
	_bullet->GetTransform()->SetPosition(startPos);
	_bullet->GetTransform()->SetAngel(_direction.Angle());
}

void DunBullet::Update()
{
	if (_isActive == false)
		return;

	_bullet->GetTransform()->AddVector2(_direction*_speed * DELTA_TIME);

	if (_bullet->GetTransform()->GetWorldPosition().y > WIN_HEIGHT || _bullet->GetTransform()->GetWorldPosition().x > WIN_WIDTH 
		|| _bullet->GetTransform()->GetWorldPosition().y < 0 || _bullet->GetTransform()->GetWorldPosition().x < 0)
		_isActive = false;

	_bullet->Update();
}


void DunBullet::Render()
{
	_bullet->Render();
}

