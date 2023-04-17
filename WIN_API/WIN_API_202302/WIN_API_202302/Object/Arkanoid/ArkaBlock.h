#pragma once
class ArkaBlock
{
public:


	ArkaBlock();
	~ArkaBlock();

	void Update();
	void Render(HDC hdc);

	void SetPosition(Vector2 pos) { _rect->SetCenter(pos); }
	shared_ptr<Collider> GetCollider() { return _rect; }

	bool IsActive() { return _isActive; }
	void SetActive(bool value) { _isActive = value; }

private:
	bool _isActive = true;
	vector<HBRUSH> _brushes;
	shared_ptr<Collider> _rect;
};

