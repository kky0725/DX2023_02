#pragma once

class MatrixBuffer : public ConstantBuffer
{
public:
	// 상수 버퍼를 이용할 때 한가지 규칙
	// 16바이트 배수를 무조건 지켜야 한다. 24 x
	struct Data
	{
		XMMATRIX matirx = XMMatrixIdentity();//단위 행렬
	};

	MatrixBuffer()
		: ConstantBuffer(&_data, sizeof(_data))
	{

	}

	virtual ~MatrixBuffer() {}

	void SetData(XMMATRIX value)
	{
		value = XMMatrixTranspose(value);
		_data.matirx = value;
	}

	Data _data;
};