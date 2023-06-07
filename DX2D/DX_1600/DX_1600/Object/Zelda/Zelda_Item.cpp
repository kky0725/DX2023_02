#include "framework.h"
#include "Zelda_Item.h"

Zelda_Item::Zelda_Item(Vector2 pos)
{
	Vector2 size = ADD_SRV(L"Resource/Item_11x5.png")->GetImageSize();
	size.x /= 11;
	size.y /= 5;
	_sprite = make_shared<Sprite>(L"Resource/Item_11x5.png", Vector2(11, 5), size);
	_transform = make_shared<Transform>();
	_collider = make_shared<RectCollider>(size);
	_transform->SetParent(_collider->GetTransform());
	_collider->SetPosition(pos);
}

Zelda_Item::~Zelda_Item()
{
}

void Zelda_Item::Update()
{
	if (!_isActive)
		return;
	_sprite->Update();
	_transform->Update();
	_collider->Update();
}

void Zelda_Item::Render()
{
	if (!_isActive)
		return;
	_transform->SetBuffer(0);
	_sprite->SetCurFrmae(Vector2(4,0));
	_sprite->Render();
	_collider->Render();
}
