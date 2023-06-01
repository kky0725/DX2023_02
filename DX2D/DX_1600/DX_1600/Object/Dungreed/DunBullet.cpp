#include "framework.h"
#include "DunBullet.h"
#include "DunMonster.h"

DunBullet::DunBullet()
{
	_bullet = make_shared<Quad>(L"Resource/DunResource/Bullet.png");
	_bullet->GetTransform()->SetScale({ 0.05f,0.05f });

	_collider = make_shared<CircleCollider>(5.0f);
	_bullet->GetTransform()->SetParent(_collider->GetTransform());
	_bullet->GetTransform()->SetPosition({ -7.0f, 0.0f });
}

DunBullet::~DunBullet()
{
}

void DunBullet::Shoot(const Vector2& dir, const Vector2 startPos, float speed)
{
	_isActive = true;
	_direction = dir.NormalVector2();
	_speed = speed;
	_collider->GetTransform()->SetPosition(startPos);
	_collider->GetTransform()->SetAngel(_direction.Angle());
}

bool DunBullet::IsCollision(shared_ptr<DunMonster> monster)
{
	if (_collider->IsCollision(monster->GetCollider()))
		return true;
	return false;
}

void DunBullet::Collider_Update()
{
	if (_isActive == false)
		return;

	_collider->GetTransform()->AddVector2(_direction * _speed * DELTA_TIME);

	if (_collider->GetTransform()->GetWorldPosition().y > WIN_HEIGHT || _collider->GetTransform()->GetWorldPosition().x > WIN_WIDTH
		|| _collider->GetTransform()->GetWorldPosition().y < 0 || _collider->GetTransform()->GetWorldPosition().x < 0)
		_isActive = false;

	_collider->Update();
}

void DunBullet::Update()
{
	if (_isActive == false)
		return;

	_bullet->Update();

}


void DunBullet::Render()
{
	_bullet->Render();

	_collider->Render();
}

