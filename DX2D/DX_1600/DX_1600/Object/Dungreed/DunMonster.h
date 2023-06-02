#pragma once
class DunMonster
{
public:
	DunMonster();
	~DunMonster();

	void Collider_Update();
	void Update();
	void Render();

	void Damaged(int damgae);
	const int& GetHp() const { return _hp; }

	void SetPostion(Vector2 pos) { _collider->SetPosition(pos); }

	const shared_ptr<CircleCollider>& GetCollider() { return _collider; }

	void SetActive(bool value) { _isActive = value; }
	bool IsAtcive() { return _isActive; }


private:
	shared_ptr<Quad> _quad;
	shared_ptr<Transform> _transform;
	int _hp = 20;
	bool _isActive = true;

	shared_ptr<CircleCollider> _collider;
};

