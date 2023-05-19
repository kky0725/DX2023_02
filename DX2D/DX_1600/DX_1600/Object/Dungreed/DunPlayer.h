#pragma once
class DunBullet;

class DunPlayer
{
public:
	DunPlayer();
	~DunPlayer();

	void SetBowAngle();
	void Fire();

	void Update();
	void Render();

private:
	shared_ptr<Quad> _player;
	shared_ptr<Transform> _bowSlot;

	shared_ptr<Quad> _bow;
	shared_ptr<Transform> _muzzle;
	vector<shared_ptr<DunBullet>> _bullets;

	float _radian = -PI * 0.75f;
};

