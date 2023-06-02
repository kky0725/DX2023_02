#include "framework.h"
#include "Planet.h"

Planet::Planet(wstring srvfile, Vector2 scale, float rotation)
	: _rotation(rotation), _revolutionAngel(rotation * 0.5f)
{
	_quad = make_shared<Quad>(srvfile);
	_transform = make_shared<Transform>();
	_transform->SetScale(scale);

	_revolution = make_shared<Transform>();
}

Planet::~Planet()
{
}

void Planet::Update()
{
	_transform->AddAngle(_rotation);

	_revolution->SetPosition(_transform->GetWorldPosition());
	_revolution->AddAngle(_revolutionAngel);

	_transform->Update();
	_revolution->Update();
}

void Planet::Render()
{
	_transform->SetBuffer(0);
	_quad->Render();
}
