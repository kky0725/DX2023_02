Texture2D map : register(t0);
SamplerState samp : register(s0);

cbuffer MosaicActionBuffer : register(b0)
{
	float2 startPos;
	float2 size;
	float2 imageSize;
	int	   isRight;
	int	   value;
}

struct PixelInput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
	float2 uv : UV;
};

float4 Mosaic(float2 uv)
{
	float x = floor(uv.x * value); // floor : 평탄화... 소수가 들어오면 소수점 뒤를 날린다.
	float y = floor(uv.y * value);

	float2 temp;
	temp.x = x / value;
	temp.y = y / value;

	return map.Sample(samp, temp);
}

float4 PS(PixelInput input) : SV_TARGET
{
	if (isRight == 0)
		input.uv.x = 1 - input.uv.x;
	//intput.uvx : 0~1;
	input.uv.x = (startPos.x / imageSize.x) + (size.x / imageSize.x) * input.uv.x;
	input.uv.y = (startPos.y / imageSize.y) + (size.y / imageSize.y) * input.uv.y;

	return Mosaic(input.uv);
}