#include "framework.h"
#include "ArkaStage.h"

ArkaStage::ArkaStage()
{
	_frame = make_shared<RectCollider>(Vector2(WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f - 15), Vector2(FRAME_WIDTH, FRAME_HEIGHT));

	_blocks.reserve(_poolCountY);
	Vector2 offset = { (WIN_WIDTH - FRAME_WIDTH + ARKA_BLOCK_WIDTH) * 0.5f, 100.0f };
	for (int y = 0; y < _poolCountY; y++)
	{
		vector<shared_ptr<ArkaBlock>> blocksX;
		blocksX.reserve(_poolCountX);
		for (int x = 0; x < _poolCountX; x++)
		{
			shared_ptr<ArkaBlock> block = make_shared<ArkaBlock>();
			Vector2 distance = { ARKA_BLOCK_WIDTH * x,ARKA_BLOCK_HEIGHT * y };
			block->SetPosition(offset + distance);
			blocksX.push_back(block);
		}
		_blocks.push_back(blocksX);
	}

	_backGround = CreateSolidBrush(GRAY);
}

ArkaStage::~ArkaStage()
{
	DeleteObject(_backGround);
}

void ArkaStage::Update()
{
	_frame->Update();
	for (auto blocksX : _blocks)
	{
		for (auto block : blocksX)
		{
			if(block->IsActive())
				block->Update();
		}
	}
	
}

void ArkaStage::Render(HDC hdc)
{
	SelectObject(hdc, _backGround);
	_frame->Render(hdc);
	for (auto blocksX : _blocks)
	{
		for (auto block : blocksX)
		{
			if (block->IsActive())
				block->Render(hdc);
		}
	}
}
