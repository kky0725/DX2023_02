#include "framework.h"
#include "ArkanoidScene.h"

ArkanoidScene::ArkanoidScene()
{
	_stage = make_shared<ArkaStage>();
	_bar = make_shared<ArkaBar>();
	_ball = make_shared<ArkaBall>();
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_stage->Update();
	_bar->Update();
	_ball->Update();
}

void ArkanoidScene::Render(HDC hdc)
{
	_stage->Render(hdc);
	_bar->Render(hdc);
	_ball->Render(hdc);
}
