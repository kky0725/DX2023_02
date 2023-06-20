#pragma once
class Cup_Track
{
public:
	Cup_Track();
	Cup_Track(Vector2 value);
	~Cup_Track();

	void Update();
	void Render();
	void PostRender();

	const shared_ptr<Collider>& GetCollider() { return _collider; }
	const Vector2& GetTrackSize() { return _trackSize; }
	void SetPosition(Vector2 value) { _collider->SetPosition(value); }

private:
	shared_ptr<Collider> _collider;
	shared_ptr<Quad> _track;
	shared_ptr<Transform> _transform;

	Vector2 _trackSize;
};

