#include "framework.h"
#include "MazeRunner.h"

MazeRunner::MazeRunner(shared_ptr<Maze> maze)
	: _maze(maze), _pos(maze->Start())
{
	//LeftHand();

	//DFS(_pos);

	//BFS(_pos);

	//Dijkstra();

	Astar();
}

MazeRunner::~MazeRunner()
{
}

void MazeRunner::Update()
{
	if (_pathIndex >= _path.size())
	{
		Vector2 endPos = _maze.lock()->End();
		_maze.lock()->CreateMazeByKruskal();
		_pos = _maze.lock()->Start();
		_pathIndex = 0;
		_path.clear();
		Astar();
		_maze.lock()->GetBlock(endPos.y, endPos.x)->SetType(MazeBlock::BlockType::END);
		return;
	}

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
			_maze.lock()->GetBlock(pos.y, pos.x)->SetType(MazeBlock::BlockType::VISITED);
			_path.push_back(pos);
		}
		// 현재 바라보는 방향으로 전진할 수 있는지 확인
		else if (CanGo(oldGo.y, oldGo.x))
		{
			pos += oldDirVector2;
			_maze.lock()->GetBlock(pos.y, pos.x)->SetType(MazeBlock::BlockType::VISITED);
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
	_visited = vector<vector<bool>>(_maze.lock()->GetY(), vector<bool>(_maze.lock()->GetX(), false));

	if (_visited[(int)here.y][(int)here.x] == true)
		return;

	Vector2 endPos = _maze.lock()->End();
	if (_visited[endPos.y][endPos.x])
		return;

	_visited[(int)here.y][(int)here.x] = true;
	_maze.lock()->GetBlock(here.y, here.x)->SetType(MazeBlock::BlockType::VISITED);
	_path.push_back(here);


	Vector2 frontPos[8] =
	{
		Vector2(0,-1),// Up
		Vector2(1,0), // Right
		Vector2(0,1), // Down
		Vector2(-1,0), // Left
		Vector2(1,-1), // RightUp
		Vector2(1,1), // RightDown
		Vector2(-1,-1), // LeftUp
		Vector2(-1,1) // LeftDown
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
	_discovered = vector<vector<bool>>(_maze.lock()->GetY(), vector<bool>(_maze.lock()->GetX(), false));
	_parent = vector<vector<Vector2>>(_maze.lock()->GetY(), vector<Vector2>(_maze.lock()->GetX(), { -1,-1 }));

	queue<Vector2> q;
	_parent[(int)start.y][(int)start.x] = start;
	_discovered[(int)start.y][(int)start.x] = true;
	q.push(start);

	Vector2 frontPos[4] =
	{
		Vector2(0,-1),// UP
		Vector2(1,0), // RIGHT
		Vector2(0,1), // DOWN
		Vector2(-1,0) // LEFT
	};

	while (!q.empty())
	{
		Vector2 here = q.front();
		q.pop();
		if (_discovered[endPos.y][endPos.x])
			break;
		for (int i = 0; i < 4; i++)
		{
			Vector2 there = here + frontPos[i];

			if (_discovered[there.y][there.x])
				continue;

			if (CanGo(there.y, there.x) == false)
				continue;

			q.push(there);
			_discovered[there.y][there.x] = true;
			_parent[there.y][there.x] = here;
			_maze.lock()->GetBlock(there.y, there.x)->SetType(MazeBlock::BlockType::VISITED);
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

void MazeRunner::Dijkstra()
{
	Vector2 frontPos[8] =
	{
		Vector2(0,-1),// Up
		Vector2(1,0), // Right
		Vector2(0,1), // Down
		Vector2(-1,0), // Left
		Vector2(1,-1), // RightUp
		Vector2(1,1), // RightDown
		Vector2(-1,-1), // LeftUp
		Vector2(-1,1) // LeftDown
	};

	int Dijkstra_Dis[8] = { 10,10,10,10,14,14,14,14 };


	Vector2 startPos = _maze.lock()->Start();
	Vector2 endPos = _maze.lock()->End();

	_parent = vector<vector<Vector2>>(_maze.lock()->GetY(), vector<Vector2>(_maze.lock()->GetX(), { -1,-1 }));
	_best = vector<vector<int>>(_maze.lock()->GetY(), vector<int>(_maze.lock()->GetX(),INT_MAX));

	priority_queue<Vertex_Dijkstra, vector<Vertex_Dijkstra>, greater<Vertex_Dijkstra>> pq;

	Vertex_Dijkstra startV = Vertex_Dijkstra(startPos, 0);
	_best[startV.vertexNumY][startV.vertexNumX] = startV.g;
	_parent[startV.vertexNumY][startV.vertexNumX] = startV.vertexPos;
	pq.push(startV);


	while (true)
	{
		if (pq.empty())
			break;

		int cost = pq.top().g;
		Vector2 here = pq.top().vertexPos;
		pq.pop();

		if (here == endPos)
			break;

		for (int i = 0; i < 8; i++)
		{
			Vector2 there = here + frontPos[i];

			if (here == there)
				continue;

			if (CanGo(there.y, there.x) == false)
				continue;

			int nextCost = _best[here.y][here.x] + Dijkstra_Dis[i];

			// 나중에 방문하려고 했는데 이미 좋은 길이 있었다.
			if (nextCost >= _best[there.y][there.x])
				continue;

			//방문
			Vertex_Dijkstra thereV = Vertex_Dijkstra(there, nextCost);
			pq.push(thereV);
			_best[there.y][there.x] = nextCost;
			_parent[there.y][there.x] = here;
			_maze.lock()->GetBlock(there.y, there.x)->SetType(MazeBlock::BlockType::VISITED);
		}
	}

	Vector2 targetNode = endPos;
	_path.push_back(endPos);
	while (true)
	{
		if (_parent[targetNode.y][targetNode.x] == targetNode)
			break;
		targetNode = _parent[targetNode.y][targetNode.x];
		_path.push_back(targetNode);
	}

	std::reverse(_path.begin(), _path.end());
}

void MazeRunner::Astar()
{
	Vector2 frontPos[8] =
	{
		Vector2(0,-1),// Up
		Vector2(1,0), // Right
		Vector2(0,1), // Down
		Vector2(-1,0), // Left
		Vector2(1,-1), // RightUp
		Vector2(1,1), // RightDown
		Vector2(-1,-1), // LeftUp
		Vector2(-1,1) // LeftDown
	};

	int Astar_Dis[8] = { 10,10,10,10,14,14,14,14 };

	Vector2 startPos = _maze.lock()->Start();
	Vector2 endPos = _maze.lock()->End();

	_parent = vector<vector<Vector2>>(_maze.lock()->GetY(), vector<Vector2>(_maze.lock()->GetX(), { -1,-1 }));
	_best = vector<vector<int>>(_maze.lock()->GetY(), vector<int>(_maze.lock()->GetX(), INT_MAX));

	Vertex v;
	v.pos = startPos;
	v.g = 0;
	v.h = startPos.MahattanDistance(endPos) * 10;
	v.f = v.g + v.h;

	priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
	pq.push(v);


	_best[v.pos.y][v.pos.x] = v.f;
	_parent[v.pos.y][v.pos.x] = v.pos;

	while (true)
	{
		if (pq.empty())
		{
			_maze.lock()->GetBlock(endPos.y, endPos.x)->SetType(MazeBlock::BlockType::END);
			break;
		}

		Vector2 here = pq.top().pos;
		int g = pq.top().g;
		int h = pq.top().h;
		int f = pq.top().f;
		int cost = f;

		pq.pop();

		if (here == endPos)
			break;

		for (int i = 0; i < 8; i++)
		{
			Vector2 there = here + frontPos[i];

			if (here == there)
				continue;

			if (CanGo(there.y, there.x) == false)
				continue;

			int nextG = g + Astar_Dis[i];
			int nextH = there.MahattanDistance(endPos) * 10;
			int nextCost = nextG + nextH;

			if (nextCost >= _best[there.y][there.x])
				continue;

			Vertex thereV;
			thereV.pos = there;
			thereV.g = nextG;
			thereV.h = nextH;
			thereV.f = nextCost;
			pq.push(thereV);
			_best[there.y][there.x] = nextCost;
			_parent[there.y][there.x] = here;
			_maze.lock()->GetBlock(there.y, there.x)->SetType(MazeBlock::BlockType::VISITED);
		}
	}

	Vector2 targetNode = endPos;
	_path.push_back(endPos);
	while (true)
	{
		if (_parent[targetNode.y][targetNode.x] == targetNode)
			break;
		targetNode = _parent[targetNode.y][targetNode.x];
		_path.push_back(targetNode);
	}

	std::reverse(_path.begin(), _path.end());

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


