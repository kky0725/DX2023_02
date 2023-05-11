#pragma once
class VertexShader
{
public:
	VertexShader(wstring file);
	~VertexShader();
	
	void CreateBlob(wstring file);
	void CreateInputLayout();
	void CreateVertexShader();

	void Set();

private:
	ComPtr<ID3D11VertexShader> vertexShader; // �� ������ �����Ǵ� ����... World, View, Projection
	ComPtr<ID3D11InputLayout> inputLayout; // ��� ��� �о�� ����.. ������ ��ġ
	ComPtr<ID3DBlob> vertexBlob; // VertexShader ���� �� �ʿ��� ��

};

