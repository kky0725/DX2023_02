#pragma once
class Transform
{
public:
	Transform();
	~Transform();

	void Update();
	void SetBuffer(UINT slot);//vertexShader에만 세팅

	void SetScale(Vector2 scale) { _scale = scale; }
	void SetAngel(float angle) { _angle = angle; }
	void SetPosition(Vector2 pos) { _pos = pos; }

	const Vector2& GetScale() { return _scale; }
	const float& GetAngle() { return _angle; }
	const Vector2& GetPos() { return _pos; }

private:
	shared_ptr<class MatrixBuffer> _matrixBuffer;

	Vector2 _scale = { 1.0f,1.0f };
	float _angle = 0.0f;
	Vector2 _pos = { 0.0f,0.0f };

	XMMATRIX _scaleM = XMMatrixIdentity();
	XMMATRIX _rotateM = XMMatrixIdentity();
	XMMATRIX _translateM = XMMatrixIdentity();

	XMMATRIX _str = XMMatrixIdentity();

};

