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
	vector<Vertex> vertices; // ��Ƴ��� ������
	ComPtr<ID3D11Buffer> vertexBuffer; // �������� ��Ƴ��� ����

	UINT stride = 0;
	UINT offset = 0;
};

