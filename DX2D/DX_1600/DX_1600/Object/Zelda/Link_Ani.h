#pragma once
class Link_Ani
{
public:
	Link_Ani();
	~Link_Ani();


	void Update() ;
	void Render() ;
	void PostRender();

	void CreateAction();
	void CreateDirAction(float w, float h, float nth, string name, shared_ptr<SRV> srv);
	void SelectDir();

	void EndEvent() { _isEnd = true; }

private:
	bool _isEnd = false;

	shared_ptr<Sprite> _sprite;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Transform> _transform;

	shared_ptr<Action>* _curAction;

};

