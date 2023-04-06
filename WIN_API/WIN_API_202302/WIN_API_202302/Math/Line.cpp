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
	SelectObject(hdc, _pens[_curPenIndex]);

	MoveToEx(hdc, _start.x, _start.y, nullptr);
	LineTo(hdc, _end.x, _end.y);
}

float Line::Slope(shared_ptr<Line> line)
{
	return (line->_end.y - line->_start.y)/(line->_end.x - line->_start.x);
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
		//result.contact.y = Slope(other) * (result.contact.x - other->_start.x) + other->_start.y;//a(x-b)+c
		//result.contact.y = Slope(shared_from_this()) * (result.contact.x - shared_from_this()->_start.x) + shared_from_this()->_start.y;//d(x-e)+f
		//0 = ax-dx -ab +de + c-f
		//x = (-ab + de+c-f)(d-a)
		result.contact.x = (Slope(shared_from_this()) * shared_from_this()->_start.x + other->_start.y - shared_from_this()->_start.y - Slope(other) * other->_start.x) / (Slope(shared_from_this()) - Slope(other));
		result.contact.y = Slope(other) * (result.contact.x - other->_start.x) + other->_start.y;

		
		return result;
	}

	result.contact = { -10000.0f, -10000.0f };
	return result;
}
