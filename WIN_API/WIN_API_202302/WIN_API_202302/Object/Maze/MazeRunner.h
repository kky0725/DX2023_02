#pragma once
class MazeRunner
{
public:
	struct Vertex
	{
		Vertex(Vector2 pos, int g) : vertexPos(pos), g(g) { }

		bool operator<(const Vertex& other) const
		{
			return g < other.g;
		}

		bool operator>(const Vertex& other) const
		{
			return g > other.g;
		}

		Vector2 vertexPos;
		int g;
	};

	MazeRunner(shared_ptr<Maze> maze);
	~MazeRunner();

	void Update();

	void LeftHand();
	void DFS(Vector2 start);
	void BFS(Vector2 start);
	void Djikstra(Vector2 start);

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


};

