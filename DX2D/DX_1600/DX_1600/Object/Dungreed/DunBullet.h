#pragma once
class DunMonster;


class DunBullet
{
public:
	DunBullet();
	~DunBullet();

	void Collider_Update();
	void Update();
	void Render();

	void SetPos(const Vector2& pos) { _bullet->GetTransform()->SetPosition(pos); }
	void Shoot(const Vector2& dir, const Vector2 startPos,float speed = 200.0f);


	bool IsAtcive() { return _isActive; }
	void SetActive(bool value) { _isActive = value; }

	const shared_ptr<CircleCollider>& GetCollider() { return _collider; }
	bool IsCollision(shared_ptr<DunMonster> monster);


private:
	bool _isActive = false;
	float _speed = 200.0f;
	Vector2 _direction = Vector2(0.0f, 0.0f);
	
	shared_ptr<CircleCollider> _collider;

	shared_ptr<Quad> _bullet;
};

