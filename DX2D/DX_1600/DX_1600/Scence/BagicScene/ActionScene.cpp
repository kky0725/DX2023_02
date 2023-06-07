#include "framework.h"
#include "ActionScene.h"

#include "../../Object/Zelda/Link_Ani.h"
#include "../../Object/Zelda/Zelda_Player.h"
#include "../../Object/Zelda/Zelda_Item.h"

ActionScene::ActionScene()
{
	_player = make_shared<Zelda_Player>();
	srand((unsigned int)time(nullptr));

	for (int i = 0; i < 5; i++)
	{
		int w = rand() % WIN_WIDTH + 1;
		int h = rand() % WIN_HEIGHT + 1;

		shared_ptr<Zelda_Item> item = make_shared<Zelda_Item>(Vector2(w, h));
		_items.push_back(item);
	}
	
}

ActionScene::~ActionScene()
{
}

void ActionScene::Update()
{
	_player->Update();
	for (auto& item : _items)
	{
		item->Update();
	}
	GetItem();
}

void ActionScene::Render()
{
	_player->Render();
	for (auto& item : _items)
	{
		item->Render();
	}
}

void ActionScene::PostRender()
{
	_player->PostRender();
}

void ActionScene::GetItem()
{
	for (auto& item : _items)
	{
		if (!item->GetActive())
			continue;

		if (_player->GetCollider()->IsCollision(item->GetCollider()))
		{
			item->SetActive(false);
			_player->AddHp(20);
		}
	}

}
