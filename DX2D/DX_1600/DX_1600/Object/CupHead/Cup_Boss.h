#pragma once
class Cup_Bullet;

class Cup_Boss
{
public:
	enum State
	{
		INTRO,
		IDLE,
		DIE,
		NONE
	};

	Cup_Boss();
	~Cup_Boss();

	void Update();
	void Render();

	void CreateAction(wstring srvPath, string xmlPath, string actionName, Vector2 size, bool isLoop = true, float time = 0.1f);

	void Damaged(int damgae);
	const int& GetHp() const { return _hp; }
	void Fire(Vector2 targetPos);

	const shared_ptr<CircleCollider>& GetCollider() { return _collider; }

	void SetActive(bool value) { _isActive = value; }
	bool IsAtcive() { return _isActive; }

	void IdleEvent() { _state = State::IDLE; }
	void DieEvent() { _state = State::DIE; }
	void EndEvent() { _isActive = false; }


private:
	vector<shared_ptr<Sprite>> _sprites;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Transform> _transform;
	int _hp = 5;
	bool _isActive = true;

	shared_ptr<CircleCollider> _collider;

	State _state = State::INTRO;

	shared_ptr<IntBuffer> _intBuffer;


	vector<shared_ptr<Cup_Bullet>> _bullets;
	float _speed = 200.0f;
	float _time = 0.0f;
	float _atkSpeed = 0.5f;
	//bool _atkCool = false;
};

