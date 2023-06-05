#pragma once
class Sprite : public Quad
{
public:
	Sprite(wstring path, Vector2 maxFrame, Vector2 size);
	virtual ~Sprite();

	void Update();
	virtual void Render() override;

	void SetCurFrmae(Vector2 frame);
	void SetCurFrmae(Action::Clip clip);

private:
	shared_ptr<FrameBuffer> _frameBuffer;

	Vector2 _maxFrame;
	Vector2 _curFrame;
};

