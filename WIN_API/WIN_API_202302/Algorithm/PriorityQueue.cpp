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

class Priority_Queue
{
public:
	// 부모의 index가 n 일때 자식은 n*2+1, n*2+2

	void push(const int& value) {}

	void pop() { std::replace(container.begin(), container.end());
	};
	

	const int& top() { return 0; }

	unsigned int size() { return 0; }

	bool empty() { return false; }

private:
	vector<int> container;
};

int main()
{
	// priority_queue는 완전 이진트르로 구성되어 있다.
	// 완전 이진트리는 배열을 이용해서 구현할 수 있다.

	// 힙 이론
	// 
	
	priority_queue<int> pq;
	pq.push(10);
	pq.push(7);
	pq.push(20);
	pq.push(4);
	pq.push(11);

	for (int i = 0; i < 3; i++)
	{
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}