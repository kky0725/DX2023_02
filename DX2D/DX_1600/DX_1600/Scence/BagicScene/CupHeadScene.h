#pragma once
class Cup_Player;
class Cup_Boss;
class Cup_Track;

class CupHeadScene : public Scene
{
public:
	CupHeadScene();
	virtual ~CupHeadScene();

	virtual void Init() override;
	virtual void End() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;


	void CheckAttack();

	void Save();
	void Load();

private:
	shared_ptr<Cup_Player> _player;
	shared_ptr<Cup_Boss> _boss;
	vector<shared_ptr<Cup_Track>> _tracks;
};

