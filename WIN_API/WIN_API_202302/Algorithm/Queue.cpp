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

template <typename T, class _Container = deque<T>>
class MyQueue
{
public:
	void push(const T& value)
	{
		v.push_back(value);
	}

	void pop()
	{
		v.pop_front();
	}

	const T& front()
	{
		return v.front();
	}

	bool empty()
	{
		return v.size() == 0;
	}

private:
	_Container v;
};

int main()
{
	MyQueue<int> q;
	q.push(5);
	q.push(8);
	q.push(3);
	q.push(1);
	q.push(9);

	while (!q.empty())
	{
		int value = q.front();
		cout << value << endl;
		q.pop();
	}


	return 0;
}