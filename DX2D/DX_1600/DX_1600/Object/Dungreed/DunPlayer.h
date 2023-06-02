#pragma once
class DunBullet;
class DunMonster;

class DunPlayer
{
public:
	DunPlayer();
	virtual ~DunPlayer();

	virtual void Update() abstract;
	virtual void Render();

	void SetBowAngle();
	void Fire();
	void CheckAttack();

	void SetTarget(shared_ptr<DunMonster> target) { _target = target; }

	virtual void SetPosition(Vector2 pos) { _transform->SetPosition(pos); }
	virtual void Move(Vector2 movePos) { _transform->AddVector2(movePos); }
	virtual const Vector2& GetPos() { return _transform->GetPos(); }



protected:
	shared_ptr<Quad> _quad;
	shared_ptr<Transform> _transform;
	shared_ptr<Transform> _bowSlot;

	shared_ptr<Quad> _bow;
	shared_ptr<Transform> _bowTransform;
	shared_ptr<Transform> _muzzle;
	vector<shared_ptr<DunBullet>> _bullets;

	weak_ptr<DunMonster> _target;

	float _radian = -PI * 0.75f;
};

