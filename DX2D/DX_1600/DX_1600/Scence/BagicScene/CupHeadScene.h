#pragma once
class Cup_Player;
class Cup_Boss;

class CupHeadScene : public Scene
{
public:
	CupHeadScene();
	virtual ~CupHeadScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void CheckAttack();

private:
	shared_ptr<Cup_Player> _player;
	shared_ptr<Cup_Boss> _boss;

	shared_ptr<Collider> _collider;
	shared_ptr<Quad> _track;
	shared_ptr<Transform> _transform;
};

