#pragma once
class Line 
{
public:
	Line(Vector2 start, Vector2 end);
	virtual ~Line();

	void Update();
	void Render(HDC hdc);

	void SetGreen() { _curPenIndex = 0; }
	void SetRed() { _curPenIndex = 1; }
	void SetBlue() { _curPenIndex = 2; }
	void SetBlack() { _curPenIndex = 3; }

	Vector2 GetVector() { return _end - _start; }

	ColResult_Line IsCollision(shared_ptr<Line> other);

public:
	Vector2 _start;
	Vector2 _end;

	vector<HPEN> _pens;
	UINT _curPenIndex = 0;
};

