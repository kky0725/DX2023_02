#pragma once
class Collider
{
public:
	Collider();
	virtual~Collider();



protected:
	const shared_ptr<Transform> GetTransform() { return _transform; }
	vector<Vertex> _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;

	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<ColorBuffer> _colorBuffer;

	shared_ptr<Transform> _transform;
};

