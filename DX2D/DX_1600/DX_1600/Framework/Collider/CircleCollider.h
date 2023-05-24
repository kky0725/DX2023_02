#pragma once
class CircleCollider : public Collider
{
public:
	CircleCollider(float radius);
	virtual~CircleCollider();

	void Update();
	void Render();

	void CreateData();
	void CreateVertices();


	void SetRed() { _colorBuffer->SetColor(RED); _colorBuffer->Update(); }
	void SetGreen() { _colorBuffer->SetColor(GREEN); _colorBuffer->Update(); }

	void SetPosition(Vector2 pos) { _transform->SetPosition(pos); }
	Vector2 GetPos() { return _transform->GetPos(); }
	void SetScale(float value) { _transform->SetScale({ value, value }); }
	
	bool IsCollision(shared_ptr<CircleCollider> other);

	const shared_ptr<Transform> GetTransform() { return _transform; }
	void SetParent(shared_ptr<Transform> transform) { _transform->SetParent(transform); }

	float GetRadius() { return _radius; }
	float GetWorldRadius() { return _radius * _transform->GetWorldScale().x; }

private:
	float _radius;
};

