#include "framework.h"
#include "Cup_Player.h"

using namespace tinyxml2;

Cup_Player::Cup_Player()
{
	_collider = make_shared<CircleCollider>(50.0f);

	CreateIdleAction();
	CreateRunAction();

	_transform = make_shared<Transform>();
	_transform->SetParent(_collider->GetTransform());
	_transform->SetPosition(Vector2(0, 9.76));
}

Cup_Player::~Cup_Player()
{
}

void Cup_Player::Update()
{
	Input();
	SelectState();
	_collider->Update();

	_actions[_state]->Update();
	_sprites[_state]->Update();
	_transform->Update();

}

void Cup_Player::Render()
{
	_transform->SetBuffer(0);

	_sprites[_state]->SetCurFrmae(_actions[_state]->GetCurClip());
	_sprites[_state]->Render();

	_collider->Render();
}

void Cup_Player::PosRender()
{
	ImGui::SliderFloat2("FixedPos", (float*)&_fixedPos, 0, 100);
	_transform->SetPosition(_fixedPos);
}

void Cup_Player::CreateAction(wstring srvPath, string xmlPath, string actionName, Vector2 size)
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

	shared_ptr<Action> action = make_shared<Action>(clips, actionName);
	action->Play();
	shared_ptr<Sprite> sprite = make_shared<Sprite>(srvPath, Vector2(250, 250));
	_actions.push_back(action);
	_sprites.push_back(sprite);
}

void Cup_Player::CreateIdleAction()
{
	wstring srvPath = L"Resource/CupHead/Idle.png";
	shared_ptr<SRV> srv = ADD_SRV(srvPath);

	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	string path = "Resource/CupHead/Idle.xml";
	document->LoadFile(path.c_str());

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

	shared_ptr<Action> action = make_shared<Action>(clips, "CUP_IDLE");
	action->Play();
	_spriteIdle = make_shared<Sprite>(srvPath, Vector2(250, 250));
	_actions.push_back(action);
}

void Cup_Player::CreateRunAction()
{
	wstring srvPath = L"Resource/CupHead/Run.png";
	shared_ptr<SRV> srv = ADD_SRV(srvPath);

	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	string path = "Resource/CupHead/Run.xml";
	document->LoadFile(path.c_str());

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

	shared_ptr<Action> action = make_shared<Action>(clips, "CUP_RUN");
	action->Play();
	_spriteRun = make_shared<Sprite>(srvPath, Vector2(120, 120));
	_actions.push_back(action);
}

void Cup_Player::SelectState()
{
	if (KEY_UP('A'))
	{
		_state = State::IDLE;
	}

	if (KEY_UP('D'))
	{
		_state = State::IDLE;
	}

	if (KEY_PRESS('A'))
	{
		_state = State::RUN;
		SetLeft();
	}

	if (KEY_PRESS('D'))
	{
		_state = State::RUN;
		SetRight();
	}
}

void Cup_Player::Input()
{
	if (KEY_PRESS('A'))
	{
		Vector2 movePos = Vector2(-_speed, 0.0f) * DELTA_TIME;
		Move(movePos);
	}

	if (KEY_PRESS('D'))
	{
		Vector2 movePos = Vector2(_speed, 0.0f) * DELTA_TIME;
		Move(movePos);
	}
	Jump();
}

void Cup_Player::Jump()
{
	// �߷�����
	{
		_jumpPower -= 15.0f;

		if (_jumpPower < -600.0f)
			_jumpPower = -600.0f;

		_collider->GetTransform()->AddVector2(Vector2(0.0f, 1.0f) * _jumpPower * DELTA_TIME);
	}

	if (KEY_DOWN(VK_SPACE))
		_jumpPower = 600.0f;
}

void Cup_Player::AnimationControl()
{

}

void Cup_Player::SetLeft()
{
	for (auto sprite : _sprites)
		sprite->SetLeft();
}

void Cup_Player::SetRight()
{
	for (auto sprite : _sprites)
		sprite->SetRight();
}
