#pragma once
class Link_Ani
{
public:
	enum State
	{
		IDLE_D,
		IDLE_L,
		IDLE_U,
		IDLE_R,
		RUN_D,
		RUN_L,
		RUN_U,
		RUN_R,
		NONE
	};

	Link_Ani();
	~Link_Ani();

	void Update() ;
	void Render() ;
	void PostRender();

	void CreateAction();
	void CreateRunAction(float w, float h, float nth, string name, shared_ptr<SRV> srv);
	void CreateIdleAction(float w, float h, float nth, int num, string name, shared_ptr<SRV> srv);
	void SelectDir();

	void EndEvent() { _isEnd = true; }

	void SetParent(shared_ptr<Transform> parent) { _transform->SetParent(parent); }

private:
	bool _isEnd = false;

	shared_ptr<Sprite> _sprite;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Transform> _transform;

	State _state = State::IDLE_D;
};

