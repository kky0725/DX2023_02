#pragma once
class ArkaStage
{
public:


	ArkaStage();
	~ArkaStage();

	void Update();
	void Render(HDC hdc);

	vector<vector<shared_ptr<ArkaBlock>>> GetBlocks() { return _blocks; }

private:
	vector<vector<shared_ptr<ArkaBlock>>> _blocks;
	UINT _poolCountX = 13;
	UINT _poolCountY = 4;

	shared_ptr<Collider> _frame;
	HBRUSH _backGround;
};

