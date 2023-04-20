#pragma once
class MazeRunner
{
public:
	struct Vertex_Dijkstra
	{
		Vertex_Dijkstra(Vector2 pos, int g) : vertexPos(pos), g(g) { vertexNumX = pos.x; vertexNumY = pos.y; }

		bool operator<(const Vertex_Dijkstra& other) const
		{
			return g < other.g;
		}

		bool operator>(const Vertex_Dijkstra& other) const
		{
			return g > other.g;
		}

		Vector2 vertexPos;
		int vertexNumX;
		int vertexNumY;
		int g;
	};

	struct Vertex
	{
		Vertex() {}

		Vector2 pos;
		int g = 0;
		int h = 0;
		int f = 0;

		bool operator<(const Vertex& other) const
		{
			return f < other.f;
		}

		bool operator>(const Vertex& other) const
		{
			return f > other.f;
		}
	};

	MazeRunner(shared_ptr<Maze> maze);
	~MazeRunner();

	void Update();

	void LeftHand();
	void DFS(Vector2 start);
	void BFS(Vector2 start);
	void Dijkstra();
	void Astar();

	bool CanGo(int y, int x);

private:
	weak_ptr<Maze> _maze;

	Vector2 _pos;
	Dir _direction = Dir::DIR_UP;

	vector<Vector2> _path;
	int _pathIndex = 0;
	float _time = 0.0f;

	vector<vector<bool>> _visited;

	vector<vector<bool>> _discovered;
	vector<vector<Vector2>> _parent;
	vector<Vector2> _BFSdiscovered;

	vector<vector<int>> _best;
};

