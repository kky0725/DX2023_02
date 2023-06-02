#pragma once
class Quad
{
public:
	Quad();
	Quad(wstring srvfile);
	Quad(wstring srvfile, Vector2 size);
	virtual ~Quad();

	virtual void Render();

	void CreateVertices();
	void CreateNoneImgVertices(Vector2 halfSize);

	const Vector2& const GetImageSize() { return _halfSize; }

protected:
	//Á¤Á¡(pos, color, uv) 6°³
	Vector2 _halfSize;

	// Mesh
	vector<Vertex_Texture> _vertices;
	vector<UINT> _indices;

	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;

	// Material
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;
	shared_ptr<SRV> _srv;
	shared_ptr<SampleState> _sampleState;
};

