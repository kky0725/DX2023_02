#include "framework.h"
#include "MazeRunner.h"

MazeRunner::MazeRunner(shared_ptr<Maze> maze)
	: _maze(maze), _pos(maze->Start())
{
	 //LeftHand();
	//_visited = vector<vector<bool>>(maze->GetY(), vector<bool>(maze->GetX(), false));
	//DFS(_pos);
	_discovered = vector<vector<bool>>(maze->GetY(), vector<bool>(maze->GetX(), false));
	_parent = vector<vector<Vector2>>(maze->GetY(), vector<Vector2>(maze->GetX(), { -1,-1 }));
	BFS(_pos);
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
	Vector2 pos = _pos; // 첫 시작 위치
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
		// 현재 바라보는 방향 기준으로 왼쪽으로 갈 수 있는지 확인.(반시계방향)
		int newDir = (_direction - 1 + DIR_COUNT) % DIR_COUNT;
		Vector2 oldDirVector2 = frontPos[_direction]; //기존 방향
		Vector2 newDirVector2 = frontPos[newDir];//왼쪽 방향

		// 왼쪽 방향으로 전진할 수 있는지 확인
		Vector2 newGo = pos + newDirVector2;
		Vector2 oldGo = pos + oldDirVector2;
		if (CanGo(newGo.y, newGo.x))
		{
			_direction = static_cast<Dir>(newDir);
			pos += newDirVector2;
			_path.push_back(pos);
		}
		// 현재 바라보는 방향으로 전진할 수 있는지 확인
		else if (CanGo(oldGo.y, oldGo.x))
		{
			pos += oldDirVector2;
			_path.push_back(pos);
		}

		// 오른쪽, 앞이 다 막혀있다면 시계 방향으로 회전
		else
		{
			_direction = static_cast<Dir>((_direction + 1 + DIR_COUNT) % DIR_COUNT);
		}
	}

	stack<Vector2> s;
	for (int i = 0; i < _path.size() - 1; i++)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
			s.pop();
		else
			s.push(_path[i]);
	}

	s.push(_path.back());
	_path.clear();

	while (true)
	{
		if (s.empty())
			break;
		_path.push_back(s.top());
		s.pop();
	}

	std::reverse(_path.begin(), _path.end());
}

void MazeRunner::DFS(Vector2 here)
{
	if (_visited[(int)here.y][(int)here.x] == true)
		return;

	Vector2 endPos = _maze.lock()->End();
	if (_visited[endPos.y][endPos.x])
		return;

	_visited[(int)here.y][(int)here.x] = true;
	_path.push_back(here);


	Vector2 frontPos[4] =
	{
		Vector2(0,-1),// UP
		Vector2(1,0), // RIGHT
		Vector2(0,1), // DOWN
		Vector2(-1,0) // LEFT
	};

	for (int i = 0; i < 4; i++)
	{
		Vector2 there = here + frontPos[i];

		if (_visited[there.y][there.x])
			continue;

		if (CanGo(there.y, there.x) == false)
			continue;

		DFS(there);
	}

}

void MazeRunner::BFS(Vector2 start)
{
	Vector2 endPos = _maze.lock()->End();

	queue<Vector2> queue;
	_parent[(int)start.y][(int)start.x] = start;
	_discovered[(int)start.y][(int)start.x] = true;
	queue.push(start);

	Vector2 frontPos[4] =
	{
		Vector2(0,-1),// UP
		Vector2(1,0), // RIGHT
		Vector2(0,1), // DOWN
		Vector2(-1,0) // LEFT
	};

	while (!queue.empty())
	{
		Vector2 here = queue.front();
		queue.pop();
		if (_discovered[endPos.y][endPos.x])
			break;
		for (int i = 0; i < 4; i++)
		{
			Vector2 there = here + frontPos[i];

			if (_discovered[there.y][there.x])
				continue;

			if (CanGo(there.y, there.x) == false)
				continue;

			queue.push(there);
			_discovered[there.y][there.x] = true;
			_parent[there.y][there.x] = here;
		}
	}

	stack<Vector2> path;
	Vector2 targetNode = endPos;
	path.push(endPos);
	while (true)
	{
		if (_parent[targetNode.y][targetNode.x] == targetNode)
			break;
		targetNode = _parent[targetNode.y][targetNode.x];
		path.push(targetNode);
	}

	while(!path.empty())
	{
		_path.push_back(path.top());
		path.pop();
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


