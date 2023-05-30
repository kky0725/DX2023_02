#pragma once
class DunMonster
{
public:
	DunMonster();
	~DunMonster();

	void Update();
	void Render();

	void Attacked(int damgae) { _hp -= damgae; if (_hp < 1) { _hp = 0; _isActive = false; } }
	const int& GetHp() const { return _hp; }

	const shared_ptr<CircleCollider>& GetCollider() { return _collider; }

	void SetActive(bool value) { _isActive = value; }
	bool IsAtcive() { return _isActive; }


private:
	shared_ptr<Quad> _quad;
	int _hp = 20;
	bool _isActive = true;

	shared_ptr<CircleCollider> _collider;
};

