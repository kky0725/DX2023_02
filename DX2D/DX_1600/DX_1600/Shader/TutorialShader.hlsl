struct VertexInput
{
	float4 pos : POSITION;
	float4 color : COLOR;
};

struct PixelInput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
};

PixelInput VS(VertexInput input)// Symentic Name... SV -> SysytemValue
{
	PixelInput output;
	output.pos = input.pos;
	output.color = input.color;

	return output;
}

float4 PS(PixelInput input) : SV_TARGET
{
	return input.color;
}