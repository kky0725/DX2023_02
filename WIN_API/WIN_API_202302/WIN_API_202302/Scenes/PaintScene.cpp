#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_circle = make_shared<CircleCollider>(Vector2(300.0f, 300.0f), 50.0f);
	_circleMouse = make_shared<CircleCollider>(Vector2(0.0f, 0.0f), 70.0f);

	_rect = make_shared<RectCollider>(Vector2(500.0f, 300.0f), Vector2(100.0f, 150.0f));
	//_rectMouse = make_shared<RectCollider>(Vector2(0.0f, 0.0f), Vector2(150.0f, 100.0f));
}

PaintScene::~PaintScene()
{

}

void PaintScene::Update()
{
	Vector2 lerpResult = LERP(_circleMouse->GetCenter(), mousePos, 0.01f);
	_circleMouse->SetCenter(mousePos);
	//_rectMouse->SetCenter(mousePos);

	if (_rect->IsCollision(_circleMouse))
	{
		_rect->SetRed();
	}
	else
	{
		_rect->SetGreen();
	}

	_circle->Update();
	_rect->Update();
}

void PaintScene::Render(HDC hdc)
{
	_circle->Render(hdc);
	_circleMouse->Render(hdc);
	_rect->Render(hdc);
	//_rectMouse->Render(hdc);
}
