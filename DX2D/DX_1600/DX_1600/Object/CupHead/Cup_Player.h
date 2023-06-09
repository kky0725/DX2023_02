#pragma once
class Cup_Player
{
public:
	enum State
	{
		IDLE,
		JUMP,
		RUN,
		NONE
	};

	Cup_Player();
	~Cup_Player();

	void Update();
	void Render();
	void PosRender();

	void CreateAction(wstring srvPath, string xmlPath, string actionName, Vector2 size);
	void CreateIdleAction();
	void CreateRunAction();
	void SelectState();

	void Move(Vector2 movePos) { _collider->GetTransform()->AddVector2(movePos); }
	void Input();
	void Jump();
	void AnimationControl();

	void SetGrounded() { _jumpPower = 0.0f; }

	void SetPosition(Vector2 pos) { _collider->SetPosition(pos); }
	shared_ptr<Collider> GetCollider() { return _collider; }

private:
	void SetLeft();
	void SetRight();

	shared_ptr<Collider> _collider;

	vector<shared_ptr<Action>> _actions;

	vector<shared_ptr<Sprite>> _sprites;
	shared_ptr<Transform> _transform;

	State _state = State::IDLE;
	float _speed = 200.0f;

	Vector2 _fixedPos;

	float _jumpPower = 0.0f;
};

