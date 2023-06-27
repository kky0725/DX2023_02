#pragma once
class Cup_Block;

class MapToolScene : public Scene
{
public:
	MapToolScene();
	virtual ~MapToolScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void Save();
	void Load();

private:
	vector<shared_ptr<Cup_Block>> _blocks;

	shared_ptr<Button> _save;
	shared_ptr<Button> _load;

};

