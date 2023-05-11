#pragma once
class VertexBuffer
{
public:
	VertexBuffer();
	~VertexBuffer();

	void CreateVertices();
	void CreateVertexBuffer();

	void Set(int slot = 0);


private:
	vector<Vertex> vertices; // 담아놓을 정점들
	ComPtr<ID3D11Buffer> vertexBuffer; // 정점들을 담아놓는 버퍼

	UINT stride = 0;
	UINT offset = 0;
};

