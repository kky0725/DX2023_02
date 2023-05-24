#pragma once

class MatrixBuffer : public ConstantBuffer
{
public:
	// ��� ���۸� �̿��� �� �Ѱ��� ��Ģ
	// 16����Ʈ ����� ������ ���Ѿ� �Ѵ�. 24 x
	struct Data
	{
		XMMATRIX matirx = XMMatrixIdentity();//���� ���
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

class ColorBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT4 color;
	};

	ColorBuffer()
		: ConstantBuffer(&_data, sizeof(_data))
	{

	}
	virtual ~ColorBuffer() {}

	void SetColor(XMFLOAT4 value) { _data.color = value; }

private:
	Data _data;
};