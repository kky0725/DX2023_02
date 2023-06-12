#pragma once
class Cup_Bullet
{
public:
	enum State
	{
		INTRO,
		LOOP,
		NONE
	};

	Cup_Bullet();
	~Cup_Bullet();

	void Update();
	void Render();

	void SetPos(const Vector2& pos) { _transform->SetPosition(pos); }
	void Shoot(const Vector2& dir, const Vector2 startPos);

	void CreateAction(wstring srvPath, string xmlPath, string actionName, Vector2 size, bool isLoop = true);

	bool IsActive() { return _isActive; }
	void SetActive(bool value) { _isActive = value; }
	void SetDir(float value) { _transform->SetAngel(value); }

	const shared_ptr<CircleCollider>& GetCollider() { return _collider; }

	void EndEvent() { _state = State::LOOP; _actions[LOOP]->Play(); }

	void SetLeft();
	void SetRight();

private:
	bool _isActive = false;
	float _speed = 300.0f;
	Vector2 _direction = Vector2(0.0f, 0.0f);

	shared_ptr<CircleCollider> _collider;

	vector<shared_ptr<Sprite>> _sprites;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Transform> _transform;

	State _state = State::INTRO;
};

