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

	void GetItem();


private:
	shared_ptr<Zelda_Player> _player;
	vector<shared_ptr<Zelda_Item>> _items;
};

