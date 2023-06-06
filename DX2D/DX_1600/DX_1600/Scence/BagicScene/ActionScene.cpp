#include "framework.h"
#include "ActionScene.h"

#include "../../Object/Zelda/Link_Ani.h"

ActionScene::ActionScene()
{
	_link = make_shared<Link_Ani>();
}

ActionScene::~ActionScene()
{
}

void ActionScene::Update()
{
	_link->Update();
}

void ActionScene::Render()
{
	_link->Render();
}

void ActionScene::PostRender()
{
	_link->PostRender();
}
