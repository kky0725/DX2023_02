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

	//_transform->SetPosition(CENTER);

	// Listner 패턴, Observer 패턴, 구독자 패턴
	for (int i = 0; i < 4; i++)
	{
		_actions[i]->SetEndEvent(std::bind(&Link_Ani::EndEvent, this));
	}
}

Link_Ani::~Link_Ani()
{
}

void Link_Ani::Update()
{
	SelectDir();
	_sprite->Update();
	_transform->Update();
	_actions[_state]->Update();
}

void Link_Ani::Render()
{
	_transform->SetBuffer(0);
	_sprite->SetCurClip(_actions[_state]->GetCurClip());
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

	CreateIdleAction(w, h, 0, 3, "IDLE_D", srv);
	CreateIdleAction(w, h, 1, 3, "IDLE_L", srv);
	CreateIdleAction(w, h, 2, 1, "IDLE_U", srv);
	CreateIdleAction(w, h, 3, 3, "IDLE_R", srv);
	CreateRunAction(w, h, 4, "RUN_D", srv);
	CreateRunAction(w, h, 5, "RUN_L", srv);
	CreateRunAction(w, h, 6, "RUN_U", srv);
	CreateRunAction(w, h, 7, "RUN_R", srv);
}

void Link_Ani::CreateRunAction(float w, float h, float nth, string name, shared_ptr<SRV> srv)
{
	vector<Action::Clip> clips;
	{
		for (int i = 0; i < 10; i++)
		{
			Action::Clip clip = Action::Clip(i * w, nth * h, w, h, srv);
			clips.push_back(clip);
		}
	}

	shared_ptr<Action> action = make_shared<Action>(clips, name);
	action->Play();

	_actions.push_back(action);
}

void Link_Ani::CreateIdleAction(float w, float h, float nth, int num, string name, shared_ptr<SRV> srv)
{
	vector<Action::Clip> clips;
	{
		for (int i = 0; i < num; i++)
		{
			Action::Clip clip = Action::Clip(i * w, nth * h, w, h, srv);
			clips.push_back(clip);
		}
	}

	shared_ptr<Action> action = make_shared<Action>(clips, name, Action::Type::LOOP, 0.3f);
	action->Play();

	_actions.push_back(action);
}

void Link_Ani::SelectDir()
{
	if (KEY_UP('S'))
	{
		_state = State::IDLE_D;
	}
	
	if (KEY_UP('A'))
	{
		_state = State::IDLE_L;
	}
	
	if (KEY_UP('W'))
	{
		_state = State::IDLE_U;
	}
	
	if (KEY_UP('D'))
	{
		_state = State::IDLE_R;
	}
	
	if (KEY_PRESS('S'))
	{
		_state = State::RUN_D;
	}
	
	if (KEY_PRESS('A'))
	{
		_state = State::RUN_L;
	}
	
	if (KEY_PRESS('W'))
	{
		_state = State::RUN_U;
	}
	
	if (KEY_PRESS('D'))
	{
		_state = State::RUN_R;
	}
}
