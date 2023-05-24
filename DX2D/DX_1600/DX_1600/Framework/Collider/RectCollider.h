#pragma once
class RectCollider : public Collider
{
public:
	RectCollider(Vector2 size);
	virtual~RectCollider();

	void Update();
	void Render();

	void CreateData();
	void CreateVertices();

	void SetPosition(Vector2 pos) { _transform->SetPosition(pos); }

	void SetRed() { _colorBuffer->SetColor(RED); _colorBuffer->Update(); }
	void SetGreen() { _colorBuffer->SetColor(GREEN); _colorBuffer->Update(); }

	void SetScale(Vector2 scale) { _transform->SetScale(scale); }

	const shared_ptr<Transform> GetTransform() { return _transform; }
	void SetParent(shared_ptr<Transform> transform) { _transform->SetParent(transform); }

private:
	Vector2 _size;
};

