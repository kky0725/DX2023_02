#pragma once
class Cup_Player
{
public:
	enum State
	{
		IDLE,
		RUN_R,
		NONE
	};

	Cup_Player();
	~Cup_Player();

	void Update();
	void Render();
	void PosRender();

	void CreateIdleAction();
	void CreateRunAction();
	void SelectState();

	void Move(Vector2 movePos) { _collider->GetTransform()->AddVector2(movePos); }
	void Input();

	void SetPosition(Vector2 pos) { _collider->SetPosition(pos); }

private:
	shared_ptr<CircleCollider> _collider;

	vector<shared_ptr<Action>> _actions;

	shared_ptr<Sprite> _spriteIdle;
	shared_ptr<Sprite> _spriteRun;
	shared_ptr<Transform> _transform;

	State _state = State::IDLE;
	float _speed = 200.0f;

	Vector2 _fixedPos;
};

