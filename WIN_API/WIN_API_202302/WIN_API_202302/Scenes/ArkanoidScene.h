#pragma once
class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<ArkaPlayer> _player;
	shared_ptr<ArkaStage> _stage;
};

