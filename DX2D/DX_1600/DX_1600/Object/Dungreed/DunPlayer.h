#pragma once
class DunBullet;

class DunPlayer
{
public:
	DunPlayer();
	~DunPlayer();

	void Fire();

	void Update();
	void Render();

private:
	shared_ptr<Quad> _player;
	shared_ptr<Quad> _item;
	vector<shared_ptr<DunBullet>> _bullets;
	shared_ptr<DunBullet> _bullet;


	float _angle = 0.0f;
};

