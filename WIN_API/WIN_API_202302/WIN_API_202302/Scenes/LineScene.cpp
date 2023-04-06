#include "framework.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_lineFloor = make_shared<Line>(Vector2(0, 500), Vector2(1000, 330));
	_lineMouse = make_shared<Line>(Vector2(50, 250), Vector2(50, 250));
	_lineShadow = make_shared<Line>(Vector2(50, 450), Vector2(60, 450));

}

LineScene::~LineScene()
{
}

void LineScene::Update()
{
	_lineMouse->_end = mousePos;

	Vector2 line_floor = _lineFloor->GetVector();
	Vector2 line_mouse = _lineMouse->GetVector();
	Vector2 floor_normal = line_floor.NormalVector2();
	float shadowLength = floor_normal.Dot(line_mouse);

	_lineShadow->_end = _lineShadow->_start + floor_normal * shadowLength;

	_lineFloor->SetBlack();
	_lineFloor->Update();

	_lineMouse->SetBlue();
	_lineMouse->Update();

	_lineShadow->SetRed();
	_lineShadow->Update();
}

void LineScene::Render(HDC hdc)
{
	_lineFloor->Render(hdc);
	_lineMouse->Render(hdc);
	_lineShadow->Render(hdc);
}
