#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_circle = make_shared<CircleCollider>(Vector2(300.0f, 300.0f), 50.0f);
}

PaintScene::~PaintScene()
{

}

void PaintScene::Update()
{
	if (GetAsyncKeyState('A'))
	{
		//Vector2 movePos = _circle->GetCenter() - Vector2(1, 0);
		//_circle->SetCenter(movePos);
		_circle->MoveCenter(Vector2(-1, -1).NormalVector2() * _speed);
	}
	if (GetAsyncKeyState('D'))
	{
		//Vector2 movePos = _circle->GetCenter() + Vector2(1, 0);
		//_circle->SetCenter(movePos);
		_circle->MoveCenter(Vector2(1, 1).NormalVector2() * _speed);
	}

	_circle->Update();
}

void PaintScene::Render(HDC hdc)
{
	_circle->Render(hdc);
}
