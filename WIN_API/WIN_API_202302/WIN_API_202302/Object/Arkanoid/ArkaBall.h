#pragma once
class ArkaBall
{
public:
	ArkaBall();
	~ArkaBall();

	void Update();
	void Render(HDC hdc);

	

private:
	bool _isActive = false;
	float _speed = 10.0f;
	Vector2 _direction = Vector2(0.0f, 0.0f);

	shared_ptr<Collider> _ball;
};

