#pragma once
class Line : public Collider
{
public:
	Line(Vector2 start, Vector2 end) : _start(start), _end(end), Collider(Vector2 (0,0)) {}
	virtual ~Line() {}

	void Update();
	void Render(HDC hdc);

	virtual bool IsCollision(Vector2 pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) override;
	virtual bool IsCollision(shared_ptr<RectCollider> other) override;

public:
	Vector2 _start;
	Vector2 _end;

};

