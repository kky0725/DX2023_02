#pragma once
class ArkaPlayer
{
public:
	ArkaPlayer();
	~ArkaPlayer();

	void Move();
	void Shoot();
	void ReflectBall();
	void Dead();

	shared_ptr<ArkaBall> GetBall() { return _ball; }

	void Update();
	void Render(HDC hdc);


private:
	bool _isControlled = true;
	bool _canShoot = true;
	float _barWidth = 60;
	float _barHeight = 15;
	float _speed = 3.0f;

	int _life = 3;
	shared_ptr<Collider> _rect;
	shared_ptr<ArkaBall> _ball;

	
	HBRUSH _brush;

};

