#pragma once
class DunBullet
{
public:
	DunBullet();
	~DunBullet();

	void Update();
	void Render();

	void SetPos(const Vector2& pos) { _bullet->GetTransform()->SetPosition(pos); }
	void Shoot(const Vector2& dir, const Vector2 startPos,float speed = 200.0f);

	bool IsAtcive() { return _isActive; }
	void SetActive(bool value) { _isActive = value; }

private:
	bool _isActive = false;
	float _speed = 20.0f;
	Vector2 _direction = Vector2(0.0f, 0.0f);

	shared_ptr<Quad> _bullet;
};

