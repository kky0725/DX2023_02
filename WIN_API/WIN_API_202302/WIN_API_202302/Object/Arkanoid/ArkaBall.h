#pragma once
class ArkaBall
{
public:
	ArkaBall();
	~ArkaBall();

	void Update();
	void Render(HDC hdc);

	

private:
	bool _isActive = true;
	float _speed = 5.0f;
	Vector2 _direction = Vector2(0.0f, -1.0f);

	shared_ptr<Collider> _ball;
};

