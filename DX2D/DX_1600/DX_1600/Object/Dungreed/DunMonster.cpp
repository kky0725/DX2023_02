#include "framework.h"
#include "DunMonster.h"

DunMonster::DunMonster()
{
	_quad = make_shared<Quad>(L"Resource/Goomba.png");
	_quad->GetTransform()->SetPosition({ 800,500 });
	_quad->GetTransform()->SetScale({ 0.3f, 0.3f });

	_collider = make_shared<CircleCollider>(80.0f);
}

DunMonster::~DunMonster()
{
}

void DunMonster::Update()
{
	if (_hp > 0)
	{
		_quad->Update();
		_collider->SetPosition(_quad->GetTransform()->GetWorldPosition());
		_collider->Update();
	}
}

void DunMonster::Render()
{
	if (_hp > 0)
	{
		_quad->Render();
		_collider->Render();
	}
}
