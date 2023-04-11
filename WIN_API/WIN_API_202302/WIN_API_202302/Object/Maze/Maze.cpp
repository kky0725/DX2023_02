#include "framework.h"
#include "Maze.h"

Maze::Maze()
{
	_blocks.reserve(_poolCoutY);
	Vector2 offset = { 400, 150 };
	for (int y = 0; y < _poolCoutY; y++)
	{
		vector<shared_ptr<MazeBlock>> blocksX;
		blocksX.reserve(_poolCoutX);
		for (int x = 0; x < _poolCoutX; x++)
		{
			shared_ptr<MazeBlock> block = make_shared<MazeBlock>();
			block->SetType(MazeBlock::BlockType::DISABLE);
			Vector2 distance = { 17 * x,17 * y};
			block->SetPosition(offset + distance);
			blocksX.push_back(block);
		}
		_blocks.push_back(blocksX);
	}

	CreateMaze();
}

Maze::~Maze()
{
}

void Maze::Update()
{
	for (auto blocksX : _blocks)
	{
		for (auto block : blocksX)
			block->Update();
	}
}

void Maze::Render(HDC hdc)
{
	for (auto blocksX : _blocks)
	{
		for (auto block : blocksX)
			block->Render(hdc);
	}
}

// Maze for Programmers
void Maze::CreateMaze()
{
	for (int y = 0; y < _poolCoutY; y++)
	{
		for (int x = 0; x < _poolCoutX; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				_blocks[y][x]->SetType(MazeBlock::BlockType::DISABLE);
			else
				_blocks[y][x]->SetType(MazeBlock::BlockType::ABLE);
		}
	}

	//랜덤하게 오른쪽 또는 아래쪽으로 길을 뚫는 작업.
	for (int y = 0; y < _poolCoutY; y++)
	{
		for (int x = 0; x < _poolCoutX; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			if (x == _poolCoutX - 2 && y == _poolCoutY - 2)
				continue;

			// 랜덤으로 우측 혹은 아래로만 뚫었을 때 길이 안생기는 것 예외 처리
			if (y == _poolCoutY - 2)
			{
				_blocks[y][x + 1]->SetType(MazeBlock::BlockType::ABLE);
				continue;
			}

			if (x == _poolCoutX - 2)
			{
				_blocks[y+1][x]->SetType(MazeBlock::BlockType::ABLE);
				continue;
			}

			const int randValue = rand() % 2;
			if(randValue == 0)
				_blocks[y][x + 1]->SetType(MazeBlock::BlockType::ABLE);
			else
				_blocks[y + 1][x]->SetType(MazeBlock::BlockType::ABLE);
		}
	}
}
