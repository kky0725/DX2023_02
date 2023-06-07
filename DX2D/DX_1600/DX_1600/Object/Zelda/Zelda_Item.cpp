#include "framework.h"
#include "Zelda_Item.h"

Zelda_Item::Zelda_Item(Vector2 pos)
{
	Vector2 size = ADD_SRV(L"Resource/zelda_sprite.png")->GetImageSize();
	size.x /= 10;
	size.y /= 8;
	_sprite = make_shared<Sprite>(L"Resource/zelda_sprite.png", Vector2(10, 8), size);
	_transform = make_shared<Transform>();
	_collider = make_shared<RectCollider>(Vector2(50, 50));
	_transform->SetParent(_collider->GetTransform());
	_collider->SetPosition(pos);
}

Zelda_Item::~Zelda_Item()
{
}

void Zelda_Item::Update()
{
	_sprite->Update();
	_transform->Update();
	_collider->Update();
}

void Zelda_Item::Render()
{
	_transform->SetBuffer(0);
	_sprite->SetCurFrmae(Vector2(0,0));
	_sprite->Render();
	_collider->Render();
}
