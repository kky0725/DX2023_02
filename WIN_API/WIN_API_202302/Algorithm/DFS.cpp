#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// 이산수학의 그래프
// 그래프에 대한 조사
// 그래프의 기원
// 그래프를 쓰는 이유

vector<vector<bool>> adjacent2;
vector<bool> visited;
queue<int> visitedQ;

void CreateGraphByMatrix()
{
	adjacent2 = vector<vector<bool>>(7, vector<bool>(7, false));
	visited = vector<bool>(7, false);

	adjacent2[0][0] = true;
	adjacent2[0][1] = true;
	adjacent2[0][2] = true;
	adjacent2[0][4] = true;

	adjacent2[1][0] = true;
	adjacent2[1][1] = true;

	adjacent2[2][0] = true;
	adjacent2[2][2] = true;
	adjacent2[2][3] = true;
	adjacent2[2][5] = true;

	adjacent2[3][2] = true;
	adjacent2[3][3] = true;

	adjacent2[4][0] = true;
	adjacent2[4][4] = true;
	adjacent2[4][6] = true;

	adjacent2[5][2] = true;
	adjacent2[5][5] = true;

	adjacent2[6][4] = true;
	adjacent2[6][6] = true;
}

void DFS(int start)
{
	if (visited[start])
		return;

	visited[start] = true;
	cout << start << "를 방문 했습니다." << endl;

	for (int there = 0; there < adjacent2.size(); there++)
	{
		if (start == there)
			continue;
		
		if (!adjacent2[start][there])
			continue;

		if (visited[there])
			continue;

		DFS(there);
	}
}

int DfsAll()
{
	int count = 0;
	for (int start = 0; start < 7; start++)
	{
		if (!visited[start])
		{
			DFS(start);
			count++;
		}
	}
	return count;
}

void BFS(int start)
{
	if (visited[start])
		return;

	visitedQ.push(start);
	visited[start] = true;
	
	while (!visitedQ.empty())
	{
		int here = visitedQ.front();
		cout << here << "를 방문 했습니다." << endl;
		visitedQ.pop();
		for (int there = 0; there < adjacent2.size(); there++)
		{
			if (here == there)
				continue;

			if (!adjacent2[here][there])
				continue;

			if (visited[there])
				continue;

			visitedQ.push(there);
			visited[there] = true;
		}
	}
}

int main()
{
	CreateGraphByMatrix();
	//int count = DfsAll();
	BFS(0);

	return 0;
}