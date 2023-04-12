#include "framework.h"
#include "ArkaBlock.h"

ArkaBlock::ArkaBlock()
{
	_rect = make_shared<RectCollider>(Vector2(0, 0), Vector2(ARKA_BLOCK_WIDTH, ARKA_BLOCK_HEIGHT));

	HBRUSH first = CreateSolidBrush(RED);
	HBRUSH second = CreateSolidBrush(YELLOW);
	HBRUSH third = CreateSolidBrush(GREEN);
	HBRUSH fourth = CreateSolidBrush(BLUE);

	_brushes.reserve(4);
	_brushes.push_back(first);
	_brushes.push_back(second);
	_brushes.push_back(third);
	_brushes.push_back(fourth);
}

ArkaBlock::~ArkaBlock()
{
	for (auto& brush : _brushes)
		DeleteObject(brush);
}

void ArkaBlock::Update()
{
	_rect->Update();
}

void ArkaBlock::Render(HDC hdc)
{
	SelectObject(hdc, _brushes[1]);
	_rect->Render(hdc);
}