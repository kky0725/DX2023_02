#pragma once
class ArkaBall
{
public:
	ArkaBall();
	~ArkaBall();

	void Update();
	void Render(HDC hdc);

	shared_ptr<Collider> GetCollider() { return _circle; }
	void SetDir(Vector2 dir) { _direction.x = dir.x; _direction.y = dir.y; }
	Vector2 GetDir() { return _direction; }
	void ReflectX() { _direction.x *= -1; }
	void ReflectY() { _direction.y *= -1; }
	bool IsActive() { return _isActive; }
	void SetActive(bool value) { _isActive = value; }

private:
	bool _isActive = false;
	float _speed = 5.0f;
	Vector2 _direction = Vector2(0.0f, 0.0f);

	float _radius = 5;
	shared_ptr<Collider> _circle;
};

