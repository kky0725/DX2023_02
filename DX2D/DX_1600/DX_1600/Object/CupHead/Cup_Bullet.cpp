#include "framework.h"
#include "Cup_Bullet.h"

using namespace tinyxml2;

Cup_Bullet::Cup_Bullet()
{
	CreateAction(L"Resource/CupHead/Bullet_Intro.png", "Resource/CupHead/Bullet_Intro.xml", "BULLET_INTRO", Vector2(50, 150), false);
	CreateAction(L"Resource/CupHead/Bullet_Loop.png", "Resource/CupHead/Bullet_Loop.xml", "BULLET_LOOP", Vector2(50, 150));

	_collider = make_shared<CircleCollider>(5.0f);
	_collider->SetPosition(Vector2(-1000, -1000));
	_transform = make_shared<Transform>();
	_transform->SetParent(_collider->GetTransform());
	_transform->SetAngel(-PI * 0.5f);
	_transform->SetPosition(Vector2(-60.0f, 0.0f));

	_actions[State::INTRO]->SetEndEvent(std::bind(&Cup_Bullet::EndEvent, this));
	_state = State::LOOP;

	_collider->Update();
	_transform->Update();
}

Cup_Bullet::~Cup_Bullet()
{
}

void Cup_Bullet::Update()
{
	if (_isActive == false)
		return;

	_collider->GetTransform()->AddVector2(_direction * _speed * DELTA_TIME);

	if (_collider->GetTransform()->GetWorldPosition().y > WIN_HEIGHT || _collider->GetTransform()->GetWorldPosition().x > WIN_WIDTH
		|| _collider->GetTransform()->GetWorldPosition().y < -WIN_HEIGHT || _collider->GetTransform()->GetWorldPosition().x < -WIN_WIDTH)
		_isActive = false;

	_actions[_state]->Update();
	_sprites[_state]->Update();
	_collider->Update();
	_transform->Update();
}

void Cup_Bullet::Render()
{
	if (_isActive == false)
		return;

	_transform->SetBuffer(0);
	_sprites[_state]->SetCurClip(_actions[_state]->GetCurClip());
	_sprites[_state]->Render();
	_collider->Render();
}

void Cup_Bullet::Shoot(const Vector2& dir, const Vector2 startPos)
{
	_state = State::INTRO;
	_actions[_state]->Play();
	_actions[LOOP]->Reset();

	_isActive = true;
	_direction = dir.NormalVector2();
	_collider->GetTransform()->SetPosition(startPos);
	_collider->GetTransform()->SetAngel(_direction.Angle());
}

void Cup_Bullet::CreateAction(wstring srvPath, string xmlPath, string actionName, Vector2 size, bool isLoop)
{
	shared_ptr<SRV> srv = ADD_SRV(srvPath);

	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	document->LoadFile(xmlPath.c_str());

	XMLElement* texturAtlas = document->FirstChildElement();
	XMLElement* row = texturAtlas->FirstChildElement();

	vector<Action::Clip> clips;

	while (true)
	{
		if (row == nullptr)
			break;

		int x = row->FindAttribute("x")->IntValue();
		int y = row->FindAttribute("y")->IntValue();
		int w = row->FindAttribute("w")->IntValue();
		int h = row->FindAttribute("h")->IntValue();

		Action::Clip clip = Action::Clip(x, y, w, h, srv);
		clips.push_back(clip);

		row = row->NextSiblingElement();
	}

	shared_ptr<Action> action;
	if (isLoop)
	{
		action = make_shared<Action>(clips, actionName);
	}
	else
	{
		action = make_shared<Action>(clips, actionName, Action::Type::END, 0.1f);
	}
	action->Play();
	shared_ptr<Sprite> sprite = make_shared<Sprite>(srvPath, size);
	_actions.push_back(action);
	_sprites.push_back(sprite);
}

void Cup_Bullet::SetLeft()
{
	_sprites[_state]->SetLeft();
}

void Cup_Bullet::SetRight()
{
	_sprites[_state]->SetRight();
}
