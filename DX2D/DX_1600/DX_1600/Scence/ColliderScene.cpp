#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_rectCollider = make_shared<RectCollider>(Vector2(100.0f, 100.0f));
	_rectCollider2 = make_shared<RectCollider>(Vector2(100.0f, 100.0f));
	_circleCollider = make_shared<CircleCollider>(100.0f);
	_circleCollider2 = make_shared<CircleCollider>(50.0f);

	//_circleCollider2->SetScale(1.5f);

	_rectCollider->SetPosition(CENTER);
	_circleCollider->SetPosition(CENTER);
	_rectCollider->SetScale(Vector2(1.5f, 1.5f));
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	_rectCollider->Update();
	_rectCollider2->Update();
	_circleCollider->Update();
	_circleCollider2->Update();

	if (_circleCollider2->IsCollision(_circleCollider) || _circleCollider2->IsCollision(_rectCollider))
		_circleCollider2->SetRed();
	else
		_circleCollider2->SetGreen();

	//_circleCollider2->SetPosition(MOUSE_POS);
	//_circleCollider2->Block(_circleCollider);
	_rectCollider2->SetPosition(MOUSE_POS);
	_rectCollider2->Block(_circleCollider);

	if (_rectCollider2->IsCollision(_circleCollider) || _rectCollider2->IsCollision(_rectCollider))
		_rectCollider2->SetRed();
	else
		_rectCollider2->SetGreen();
}

void ColliderScene::Render()
{
	_rectCollider->Render();
	_rectCollider2->Render();
	_circleCollider->Render();
	_circleCollider2->Render();
}

void ColliderScene::PostRender()
{
	//ImGui::SliderFloat2("RectPos", (float*)&_rectPos, 0, 1280);
	//ImGui::SliderFloat2("CirclePos", (float*)&_circlePos, 0, 1280);
	//_rectCollider2->SetPosition(_rectPos);
	//_circleCollider2->SetPosition(_circlePos);
}
