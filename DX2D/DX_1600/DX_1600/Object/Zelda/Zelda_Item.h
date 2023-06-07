#pragma once
class Zelda_Item
{
public:
	Zelda_Item(Vector2 pos);
	~Zelda_Item();

	void Update();
	void Render();

private:
	shared_ptr<Sprite> _sprite;
	shared_ptr<Transform> _transform;
	shared_ptr<RectCollider> _collider;
};

