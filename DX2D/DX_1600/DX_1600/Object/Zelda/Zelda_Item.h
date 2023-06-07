#pragma once
class Zelda_Item
{
public:
	Zelda_Item(Vector2 pos);
	~Zelda_Item();

	void Update();
	void Render();
	
	shared_ptr<RectCollider> GetCollider() { return _collider; }
	void SetActive(bool value) { _isActive = value; }
	bool GetActive() const { return _isActive; }

private:
	shared_ptr<Sprite> _sprite;
	shared_ptr<Transform> _transform;
	shared_ptr<RectCollider> _collider;

	bool _isActive = true;
};

