#pragma once
class RectCollider : public Collider
{
public:
	RectCollider(Vector2 center, Vector2 size);
	virtual ~RectCollider();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetSize(Vector2 size);
	const Vector2& GetSize() { return _size; }

	float Left() const		{return _center.x - _halfSize.x; }
	float Right() const		{return _center.x + _halfSize.x; }
	float Top() const		{return _center.y - _halfSize.y; }
	float Bottom() const	{return _center.y + _halfSize.y; }

	virtual bool IsCollision(Vector2 pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) override;
	virtual bool IsCollision(shared_ptr<RectCollider> other) override;

private:
	Vector2 _size = { 0.0f, 0.0f };
	Vector2 _halfSize = { 0.0f, 0.0f };
};


