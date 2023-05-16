#include "framework.h"
#include "../Render/GlobalBuffer.h"
#include "Transform.h"

Transform::Transform()
{
	_matrixBuffer = make_shared<MatrixBuffer>();
}

Transform::~Transform()
{
}

void Transform::Update()
{
	_scaleM = XMMatrixScaling(_scale.x, _scale.y, 1);
	_rotateM = XMMatrixRotationZ(_angle);
	_translateM = XMMatrixTranslation(_pos.x, _pos.y, 0.0f);

	_str = _scaleM * _rotateM * _translateM;

	_matrixBuffer->SetData(_str);
	_matrixBuffer->Update();
}

void Transform::SetBuffer(UINT slot)
{
	_matrixBuffer->SetVSBuffer(slot);
}
