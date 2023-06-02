#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	_quad1 = make_shared<Quad>(L"Resource/Zelda.png");
	_quad2 = make_shared<Quad>(L"Resource/Goomba.png");
	_transform1 = make_shared<Transform>();
	_transform2 = make_shared<Transform>();

	_transform1->SetParent(_transform2);

	_transform1->SetPosition({1000, 0});

	//_quad1->GetTransform()->SetScale({ 0.5f, 0.5f });
	_transform2->SetScale({ 0.1f, 0.1f });
}

TutorialScene::~TutorialScene()
{
	
}

void TutorialScene::Update()
{
	_angle1 += 0.0001f;
	_angle2 += 0.0003f;

	Vector2 lerpResult = LERP(_transform2->GetPos(), MOUSE_POS, 0.001f);
	_transform2->SetPosition(lerpResult);

	_transform1->SetAngel(_angle1);
	_transform2->SetAngel(_angle2);

	_transform1->Update();
	_transform2->Update();
}

void TutorialScene::Render()
{
	_transform1->SetBuffer(0);
	_transform2->SetBuffer(0);
	_quad1->Render();
	_quad2->Render();
}
