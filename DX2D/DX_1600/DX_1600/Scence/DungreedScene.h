#pragma once
class DunPlayer;
class DunBullet;
class DunMonster;

class DungreedScene : public Scene
{
public:
	DungreedScene();
	virtual ~DungreedScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

private:
	shared_ptr<DunPlayer> _player;
	shared_ptr<Quad> _ground;
	shared_ptr<RectCollider> _groundCollider;
	shared_ptr<DunMonster> _monster;

};

