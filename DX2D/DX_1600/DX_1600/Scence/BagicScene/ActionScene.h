#pragma once
class Link_Ani;
class Zelda_Player;
class Zelda_Item;

class ActionScene : public Scene
{
public:
	ActionScene();
	virtual ~ActionScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;


private:
	shared_ptr<Zelda_Player> _player;
	shared_ptr<Zelda_Item> _item;
};

