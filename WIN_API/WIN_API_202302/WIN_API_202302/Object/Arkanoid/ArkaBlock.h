#pragma once
class ArkaBlock
{
public:
	enum class FloorColor
	{
		NONE,
		FIRST,
		SECOND,
		THIRD,
		FOURTH,
	};

	ArkaBlock();
	~ArkaBlock();

	void Update();
	void Render(HDC hdc);

	void SetFloor(FloorColor floor) { _floor = floor; }
	FloorColor GetFloor() { return _floor; }
	void SetPosition(Vector2 pos) { _rect->SetCenter(pos); }
	shared_ptr<Collider> GetCollider() { return _rect; }

	bool IsActive() { return _isActive; }
	void SetActive(bool value) { _isActive = value; }

private:
	bool _isActive = true;
	vector<HBRUSH> _brushes;
	FloorColor _floor = FloorColor::NONE;
	shared_ptr<Collider> _rect;
};

