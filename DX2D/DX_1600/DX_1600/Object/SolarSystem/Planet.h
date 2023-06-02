#pragma once
class Planet
{
public:
	Planet(wstring srvfile, Vector2 scale, float rotation);
	~Planet();


	void Update();
	void Render();

	void SetPosition(Vector2 pos) { _transform->SetPosition(pos); }
	void SetParent(shared_ptr<Planet> planet) { _transform->SetParent(planet->GetRevolution()); }
	
	shared_ptr<Transform> GetTransform() { return _transform; }
	shared_ptr<Transform> GetRevolution() { return _revolution; }

	void SetRotation(float value) { _rotation = value; }
	void SetRevolution(float value) { _revolutionAngel = value; }

private:
	shared_ptr<Quad> GetQuad() { return _quad; }
	shared_ptr<Quad> _quad;
	shared_ptr<Transform> _transform;
	shared_ptr<Transform> _revolution;

	float _rotation = 0.0f;
	float _revolutionAngel = 0.0f;
};

