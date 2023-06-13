#pragma once
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

	void CreateAction(wstring srvPath, string xmlPath, string actionName, Vector2 size, bool isLoop = true);

	void Damaged(int damgae);
	const int& GetHp() const { return _hp; }

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
	int _hp = 1;
	bool _isActive = true;

	shared_ptr<CircleCollider> _collider;

	State _state = State::INTRO;
};

