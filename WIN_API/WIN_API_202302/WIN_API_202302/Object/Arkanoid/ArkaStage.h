#pragma once
class ArkaStage
{
public:


	ArkaStage();
	~ArkaStage();

	void Update();
	void Render(HDC hdc);


private:
	vector<vector<shared_ptr<ArkaBlock>>> _blocks;
	UINT _poolCountX = 13;
	UINT _poolCountY = 4;

	shared_ptr<Collider> _frame;
	shared_ptr<Line> _deathzone;

	HBRUSH _backGround;
};

