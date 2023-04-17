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
vector<bool> discovered;
vector<int> parent;

void CreateGraphByMatrix()
{
	adjacent2 = vector<vector<bool>>(7, vector<bool>(7, false));
	discovered = vector<bool>(7, false);
	parent = vector<int>(7, -1);

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

void BFS(int start)
{
	queue<int> queue;
	parent[start] = start;
	discovered[start] = true;
	queue.push(start);

	while (!queue.empty())
	{
		int here = queue.front();
		cout << here << "를 방문 했습니다." << endl;
		queue.pop();
		for (int there = 0; there < adjacent2.size(); there++)
		{
			if (!adjacent2[here][there])
				continue;

			if (discovered[there])
				continue;

			queue.push(there);
			discovered[there] = true;
			parent[there] = here;
		}
	}
}

int main()
{
	CreateGraphByMatrix();
	BFS(0);

	int targetNode = 3;
	while (true)
	{
		if (parent[targetNode] == targetNode)
			break;
		cout << targetNode << "의 부모: " << parent[targetNode] << endl;
		targetNode = parent[targetNode];
	}

	return 0;
}