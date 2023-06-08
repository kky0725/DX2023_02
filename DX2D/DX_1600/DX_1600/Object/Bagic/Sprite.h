#pragma once
class Sprite : public Quad
{
public:
	Sprite(wstring path, Vector2 size);
	Sprite(wstring path, Vector2 maxFrame, Vector2 size);
	virtual ~Sprite();

	void Update();
	virtual void Render() override;

	void SetCurFrmae(Vector2 frame);
	void SetCurFrmae(Action::Clip clip);

private:
	shared_ptr<ActionBuffer> _actionBuffer;

	shared_ptr<Vector2> _maxFrame;
};

