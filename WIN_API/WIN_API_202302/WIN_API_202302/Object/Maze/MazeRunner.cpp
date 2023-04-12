#include "framework.h"
#include "MazeRunner.h"

MazeRunner::MazeRunner(shared_ptr<Maze> maze)
	: _maze(maze), _pos(maze->Start())
{
	LeftHand();
}

MazeRunner::~MazeRunner()
{
}

void MazeRunner::Update()
{
	if (_pathIndex >= _path.size())
		return;

	_time += 0.3f;

	
	if (_time > 1.0f)
	{
		_time = 0.0f;
		_pos = _path[_pathIndex];

		_pathIndex++;
	}

	_maze.lock()->GetBlock((int)_pos.y, (int)_pos.x)->SetType(MazeBlock::BlockType::PLAYER);
	if (_pathIndex >= 2)
	{
		Vector2 oldpos;
		oldpos = _path[_pathIndex - 2];
		_maze.lock()->GetBlock((int)oldpos.y, (int)oldpos.x)->SetType(MazeBlock::BlockType::FOOTPRINT);
	}
}

void MazeRunner::LeftHand()
{
	Vector2 pos = _pos; // ù ���� ��ġ
	Vector2 endPos = _maze.lock()->End();
	_direction = Dir::DIR_UP;
	_path.push_back(pos);

	Vector2 frontPos[4] =
	{
		Vector2(0,-1),// UP
		Vector2(1,0), // RIGHT
		Vector2(0,1), // DOWN
		Vector2(-1,0) // LEFT
	};

	while (pos != endPos)
	{
		// ���� �ٶ󺸴� ���� �������� �������� �� �� �ִ��� Ȯ��.(�ݽð����)
		int newDir = (_direction - 1 + DIR_COUNT) % DIR_COUNT;
		Vector2 oldDirVector2 = frontPos[_direction]; //���� ����
		Vector2 newDirVector2 = frontPos[newDir];//���� ����

		// ���� �������� ������ �� �ִ��� Ȯ��
		Vector2 newGo = pos + newDirVector2;
		Vector2 oldGo = pos + oldDirVector2;
		if (CanGo(newGo.y, newGo.x))
		{
			_direction = static_cast<Dir>(newDir);
			pos += newDirVector2;
			_path.push_back(pos);
		}
		// ���� �ٶ󺸴� �������� ������ �� �ִ��� Ȯ��
		else if (CanGo(oldGo.y, oldGo.x))
		{
			pos += oldDirVector2;
			_path.push_back(pos);
		}

		// ������, ���� �� �����ִٸ� �ð� �������� ȸ��
		else
		{
			_direction = static_cast<Dir>((_direction + 1 + DIR_COUNT) % DIR_COUNT);
		}
	}
}

bool MazeRunner::CanGo(int y, int x)
{
	if (_maze.lock()->GetBlockType(y, x) == MazeBlock::BlockType::DISABLE ||
		_maze.lock()->GetBlockType(y, x) == MazeBlock::BlockType::NONE)
	{
		return false;
	}

	return true;
}


