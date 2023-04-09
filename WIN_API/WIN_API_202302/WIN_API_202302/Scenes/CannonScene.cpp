#include "framework.h"
#include "CannonScene.h"

CannonScene::CannonScene()
{
	_cannon1 = make_shared<Cannon>(Vector2(WIN_WIDTH * 0.5f +200, WIN_HEIGHT * 0.5f));
	_cannon2 = make_shared<Cannon2>(Vector2(WIN_WIDTH * 0.5f -200, WIN_HEIGHT * 0.5f));
}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{	
	if (_cannon1->GetHp() > 0)
	{
		for (auto& bullet : _cannon2->GetBullets())
		{
			if (bullet->IsAtcive() && _cannon1->GetBody()->IsCollision(bullet->GetCircle()))
			{
				_cannon1->AddHp(-1);
				bullet->SetIsActive(false);
			}
		}
	}

	if (_cannon2->GetHp() > 0)
	{
		for (auto& bullet : _cannon1->GetBullets())
		{
			if (bullet->IsAtcive() && _cannon2->GetBody()->IsCollision(bullet->GetCircle()))
			{
				_cannon2->AddHp(-1);
				bullet->SetIsActive(false);
			}
		}
	}

	_cannon1->Update();
	_cannon2->Update();
}

void CannonScene::Render(HDC hdc)
{
	_cannon1->Render(hdc);
	_cannon2->Render(hdc);
}
