#pragma once
class ArkaBar
{
public:
	ArkaBar();
	~ArkaBar();

	void Move();
	void Shoot();

	void Update();
	void Render(HDC hdc);


private:
	bool _isControlled = false;
	bool _canShoot = false;
	float _barWidth = 60;
	float _barHeight = 15;
	float _speed = 3.0f;

	int _life = 3;
	shared_ptr<Collider> _rect;
	
	HBRUSH _brush;

};

