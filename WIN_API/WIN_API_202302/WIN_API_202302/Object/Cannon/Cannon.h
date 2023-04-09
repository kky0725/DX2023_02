#pragma once
class Cannon
{
public:
	Cannon(Vector2 pos);
	~Cannon();

	void Update();
	void Render(HDC hdc);

	virtual void Move();
	virtual void Angle();
	virtual void Fire();

	const vector<shared_ptr<Bullet>>& GetBullets() { return _bullets; }
	const shared_ptr<CircleCollider>& GetBody() const { return _body; }
	const int& GetHp() const { return _hp; }
	void AddHp(int value) { _hp += value; }

protected:
	float _muzzleLength = 100.0f;
	float _muzzleAngle = 0.0f;
	Vector2 _muzzleDir = Vector2(1.0f, 0.0f);

	shared_ptr<CircleCollider> _body;
	shared_ptr<Line> _muzzle;

	vector<shared_ptr<Bullet>> _bullets;

	int _hp = 100;
};

