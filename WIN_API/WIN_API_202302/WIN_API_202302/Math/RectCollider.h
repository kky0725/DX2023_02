#pragma once
class RectCollider
{
public:
	RectCollider(Vector2 center, float width, float length);
	~RectCollider();

	void Update();
	void Render(HDC hdc);

	void MoveCenter(const Vector2& value);

	void SetCenter(const Vector2 value);
	const Vector2& GetCenter() { return _center; }

	void SetWidth(float width);
	const float& GetWidth() { return _width; }

	void SetLength(float length);
	const float& GetLength() { return _length; }

private:
	Vector2 _center = { 0.0f, 0.0f };
	float _width = 0.0f;
	float _length = 0.0f;
};


