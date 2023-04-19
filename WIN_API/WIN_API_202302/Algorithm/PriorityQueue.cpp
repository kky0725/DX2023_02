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

template<typename T = int, typename Container = vector<T>, typename Pred = less<T>>
class Priority_Queue
{
public:
	// 부모의 index가 n 일때 자식은 n*2+1, n*2+2


	void push(const T& value)
	{
		container.push_back(value);
		int nowIndex = static_cast<int>(container.size() - 1);
		int parent;
		while (true)
		{
			if (nowIndex <= 0)
				return;

			Pred p;
			parent = (nowIndex - 1) / 2;
			if (!p(container[parent], container[nowIndex]))
				break;

			std::swap(container[nowIndex], container[parent]);
			nowIndex = parent;
		}
	}

	void pop()
	{ 
		if (container.empty())
			return;

		container[0] = container.back();
		container.pop_back();
		int nowIndex = 0;
		int leftChild;
		int rightChild;
		while (true)
		{
			leftChild = nowIndex * 2 + 1;
			rightChild = nowIndex * 2 + 2;

			if (leftChild >= (int)container.size())
				break;

			Pred p;
			int nextIndex = nowIndex;
			if(p(container[nextIndex], container[leftChild]))
				nextIndex = leftChild;

			if (rightChild < (int)container.size() && p(container[nextIndex], container[rightChild]))
				nextIndex = rightChild;

			if (nextIndex == nowIndex)
				break;

			std::swap(container[nowIndex], container[nextIndex]);
			nowIndex = nextIndex;
		}
	}
	

	const T& top() { return container[0]; }

	unsigned int size() { return container.size();}

	bool empty() { return container.empty(); }

private:
	Container container;
};

int main()
{
	// priority_queue는 완전 이진트르로 구성되어 있다.
	// 완전 이진트리는 배열을 이용해서 구현할 수 있다.

	// 힙 이론
	// 

	Priority_Queue<int, vector<int>, greater<int>> pq;
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