#include "framework.h"
#include "ActionScene.h"

#include "../../Object/Zelda/Link_Ani.h"
#include "../../Object/Zelda/Zelda_Player.h"
#include "../../Object/Zelda/Zelda_Item.h"

ActionScene::ActionScene()
{
	_player = make_shared<Zelda_Player>();
	_item = make_shared<Zelda_Item>(Vector2(600, 600));
}

ActionScene::~ActionScene()
{
}

void ActionScene::Update()
{
	_player->Update();
	_item->Update();
}

void ActionScene::Render()
{
	_player->Render();
	_item->Render();
}

void ActionScene::PostRender()
{
	_player->PostRender();
}
