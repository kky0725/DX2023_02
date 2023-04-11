#include "framework.h"
#include "Line.h"

Line::Line(Vector2 start, Vector2 end)
	: _start(start), _end(end)
{
	HPEN green = CreatePen(PS_SOLID, 3, GREEN);
	HPEN red = CreatePen(PS_SOLID, 3, RED);
	HPEN blue = CreatePen(PS_SOLID, 3, BLUE);
	HPEN black = CreatePen(PS_SOLID, 3, BLACK);
	_pens.push_back(green);
	_pens.push_back(red);
	_pens.push_back(blue);
	_pens.push_back(black);
}

Line::~Line()
{
	for (auto& pen : _pens)
		DeleteObject(pen);
}

void Line::Update()
{
}

void Line::Render(HDC hdc)
{
	//SelectObject(hdc, _pens[_curPenIndex]);

	MoveToEx(hdc, _start.x, _start.y, nullptr);
	LineTo(hdc, _end.x, _end.y);
}

ColResult_Line Line::IsCollision(shared_ptr<Line> other)
{
	ColResult_Line result;
	result.isCollision = false;
	result.contact = { 0.0f, 0.0f };

	Vector2 a = this->GetVector();
	Vector2 a1 = other->_start - this->_start;
	Vector2 a2 = other->_end - this->_start;

	Vector2 b = other->GetVector();
	Vector2 b1 = this->_start - other->_start;
	Vector2 b2 = this->_end - other->_start;

	if (a.IsBetween(a1, a2) && b.IsBetween(b1, b2))
	{
		result.isCollision = true;
		float aArea = abs(a.Cross(a1));
		float bArea = abs(a.Cross(a2));

		float ratio = aArea / (aArea + bArea);

		float length = b.Length() * ratio;
		Vector2 bNormal = b.NormalVector2();
		result.contact = other->_start + bNormal * length;
		
		return result;
	}

	result.contact = { -10000.0f, -10000.0f };
	return result;
}
