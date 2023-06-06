#pragma once
class Link_Ani;

class ActionScene : public Scene
{
public:
	ActionScene();
	virtual ~ActionScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;


private:
	shared_ptr<Link_Ani> _link;
};

