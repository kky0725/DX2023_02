#include "framework.h"
#include "Link_Ani.h"


Link_Ani::Link_Ani()
{
	CreateAction();
	Vector2 size = ADD_SRV(L"Resource/zelda_sprite.png")->GetImageSize();
	size.x /= 10;
	size.y /= 8;
	_sprite = make_shared<Sprite>(L"Resource/zelda_sprite.png", Vector2(10, 8), size);
	_transform = make_shared<Transform>();

	_transform->SetPosition(CENTER);

	// Listner 패턴, Observer 패턴, 구독자 패턴
	for (int i = 0; i < 4; i++)
	{
		_actions[i]->SetEndEvent(std::bind(&Link_Ani::EndEvent, this));
	}
	_curAction = &_actions[0];
}

Link_Ani::~Link_Ani()
{
}

void Link_Ani::Update()
{
	SelectDir();
	_sprite->Update();
	_transform->Update();
	(*_curAction)->Update();
}

void Link_Ani::Render()
{
	_transform->SetBuffer(0);
	_sprite->SetCurFrmae((*_curAction)->GetCurClip());
	_sprite->Render();
}

void Link_Ani::PostRender()
{
	if (_isEnd)
		ImGui::Text("EndEvent!!");
}

void Link_Ani::CreateAction()
{
	shared_ptr<SRV> srv = ADD_SRV(L"Resource/zelda_sprite.png");
	Vector2 imageSize = srv->GetImageSize();
	Vector2 maxFrame = { 10, 8 };
	float w = imageSize.x / maxFrame.x;
	float h = imageSize.y / maxFrame.y;

	CreateDirAction(w, h, 4, "RUN_D", srv);
	CreateDirAction(w, h, 5, "RUN_L", srv);
	CreateDirAction(w, h, 6, "RUN_U", srv);
	CreateDirAction(w, h, 7, "RUN_R", srv);
}

void Link_Ani::CreateDirAction(float w, float h, float nth, string name, shared_ptr<SRV> srv)
{
	vector<Action::Clip> clips;
	{
		for (int i = 0; i < 10; i++)
		{
			Action::Clip clip = Action::Clip(i * w, nth * h, w, h, srv);
			clips.push_back(clip);
		}
	}

	shared_ptr<Action> action = make_shared<Action>(clips, name, Action::Type::END);
	action->Play();

	_actions.push_back(action);
}

void Link_Ani::SelectDir()
{
	if (KEY_PRESS('S'))
	{
		_actions[0]->Play();
		_isEnd = false;
		_curAction = &_actions[0];
	}
	else if (KEY_PRESS('A'))
	{
		_actions[1]->Play();
		_isEnd = false;
		_curAction = &_actions[1];
	}
	else if (KEY_PRESS('W'))
	{
		_actions[2]->Play();
		_isEnd = false;
		_curAction = &_actions[2];
	}
	else if (KEY_PRESS('D'))
	{
		_actions[3]->Play();
		_isEnd = false;
		_curAction = &_actions[3];
	}
}
