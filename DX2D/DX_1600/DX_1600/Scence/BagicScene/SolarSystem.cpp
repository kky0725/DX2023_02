#include "framework.h"
#include "SolarSystem.h"

#include "../../Object/SolarSystem/Planet.h"

SolarSystem::SolarSystem()
{
	_sun = make_shared<Planet>(L"Resource/sun.png", Vector2{ 0.1f, 0.1f }, 0.0005f);
	_earth = make_shared<Planet>(L"Resource/earth.png", Vector2{ 0.07f, 0.07f }, 0.0005f);
	_moon = make_shared<Planet>(L"Resource/moon.png", Vector2{ 0.05f, 0.05f }, 0.0005f);

	_earth->SetParent(_sun);
	_moon->SetParent(_earth);

	_earth->SetPosition({ 200, 0 });
	_moon->SetPosition({ 50, 0 });

	_sun->SetRevolution(0.00015f);
	_earth->SetRevolution(0.00025f);

}

SolarSystem::~SolarSystem()
{
}

void SolarSystem::Update()
{
	Vector2 lerpResult = LERP(_sun->GetTransform()->GetPos(), MOUSE_POS, 0.001f);
	_sun->SetPosition(lerpResult);


	_sun->Update();
	_earth->Update();
	_moon->Update();
}

void SolarSystem::Render()
{
	_sun->Render();
	_earth->Render();
	_moon->Render();
}
