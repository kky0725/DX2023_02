#pragma once
class Cannon
{
public:
	Cannon(Vector2 pos);
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void Move();
	void Angle();
	void Fire();

private:
	float _muzzleLength = 100.0f;
	float _muzzleAngle = 0.0f;
	Vector2 _muzzleDir = Vector2(1.0f, 0.0f);

	shared_ptr<CircleCollider> _body;
	shared_ptr<Line> _muzzle;

	vector<shared_ptr<Bullet>> _bullets;
};

