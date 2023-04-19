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


	void push(const int& value)
	{
		container.push_back(value);
		int index = container.size() - 1;
		int parentIndex;
		while (true)
		{
			if (index % 2 == 0)
				parentIndex = (index - 2) / 2;
			else
				parentIndex = (index - 1) / 2;

			if (parentIndex < 0 || container[index] <= container[parentIndex])
				break;
			else
			{
				swap(container[index], container[parentIndex]);
				index = parentIndex;
			}
		}
	}

	void pop()
	{ 
		if (container.size() < 1)
			return;

		container[0] = container[container.size() - 1];
		int index = 0;
		int leftIndex;
		int rightIndex;
		int lowIndex;
		int highIndex;
		container.resize(container.size() - 1);
		while (true)
		{
			leftIndex = index * 2 + 1;
			rightIndex = index * 2 + 2;

			if (rightIndex > container.size() - 1)
				break;
			if (rightIndex == container.size())
			{
				if (container[index] < container[leftIndex])
					swap(container[index], container[leftIndex]);
				break;
			}

			if (leftIndex <= rightIndex)
			{
				lowIndex = leftIndex;
				highIndex = rightIndex;
			}
			else
			{
				lowIndex = rightIndex;
				highIndex = leftIndex;
			}

			if (container[index] >= container[highIndex])
				break;
			else
			{
				swap(container[index], container[lowIndex]);
				index = lowIndex;
			}
		}
	}
	

	const int& top() { return container[0]; }

	unsigned int size() { return container.size();}

	bool empty() { return container.size() == 0; }

private:
	vector<int> container;
};

int main()
{
	// priority_queue는 완전 이진트르로 구성되어 있다.
	// 완전 이진트리는 배열을 이용해서 구현할 수 있다.

	// 힙 이론
	// 

	Priority_Queue pq;
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