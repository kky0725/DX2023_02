#pragma once
class Cup_Ani
{
public:
	enum State
	{
		IDLE,
		JUMP,
		RUN,
		SHOT,
		RUN_SHOT,
		NONE
	};

	Cup_Ani();
	~Cup_Ani();

	void Update();
	void Render();
	void PostRender();

	void CreateAction(wstring srvPath, string xmlPath, string actionName, Vector2 size);
	void SelectState();
	void SetParent(shared_ptr<Transform> parent) { _transform->SetParent(parent); }

	void EndEvent() { _state = State::IDLE; }

	void SetIsGround(bool value) { _isGround = value; }
	bool GetISGround() const { return _isGround; }
	bool GetIsRight() const { return _isRight; }

private:
	void SetLeft();
	void SetRight();

	vector<shared_ptr<Action>> _actions;
	vector<shared_ptr<Sprite>> _sprites;
	shared_ptr<Transform> _transform;

	State _state = State::IDLE;

	Vector2 _fixedPos;

	bool _isRight = true;
	bool _isGround = false;
};

