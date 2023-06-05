#include "framework.h"
#include "Sprite.h"

Sprite::Sprite(wstring path, Vector2 maxFrame, Vector2 size)
	: _maxFrame(maxFrame), Quad(path, size)
{
	_vs = ADD_VS(L"Shader/SpriteVS.hlsl");
	_ps = ADD_PS(L"Shader/SpritePS.hlsl");

	_frameBuffer = make_shared<FrameBuffer>();
	_frameBuffer->SetMaxFrame(_maxFrame);
	_frameBuffer->SetCurFrame(_curFrame);
}

Sprite::~Sprite()
{
}

void Sprite::Update()
{
	_frameBuffer->Update();
}

void Sprite::Render()
{
	_frameBuffer->SetPsBuffer(0);
	Quad::Render();
}

void Sprite::SetCurFrmae(Vector2 frame)
{
	_frameBuffer->SetCurFrame(frame);
}

void Sprite::SetCurFrmae(Action::Clip clip)
{
	Vector2 frame;
	frame.x = clip._startPos.x / clip._size.x;
	frame.y = clip._startPos.y / clip._size.y;
	_frameBuffer->SetCurFrame(frame);
}
