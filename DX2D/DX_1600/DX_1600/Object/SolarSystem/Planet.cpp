#include "framework.h"
#include "Planet.h"

Planet::Planet(wstring srvfile, Vector2 scale, float rotation)
	: _rotation(rotation), _revolutionAngel(rotation * 0.5f)
{
	_quad = make_shared<Quad>(srvfile);
	_quad->GetTransform()->SetScale(scale);

	_revolution = make_shared<Transform>();
}

Planet::~Planet()
{
}

void Planet::Update()
{
	_quad->GetTransform()->AddAngle(_rotation);
	_revolution->AddAngle(_revolutionAngel);

	_revolution->SetPosition(_quad->GetTransform()->GetWorldPosition());

	_quad->Update();
	_revolution->Update();
}

void Planet::Render()
{
	_quad->Render();
}
