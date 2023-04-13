#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

template <typename T>
class MyStack
{
public:
	void push(const T& value)
	{
		v.push_back(value);
	}

	void pop()
	{
		v.pop_back();
	}

	const T& top()
	{
		return v.back();
	}

	bool empty()
	{
		return v.size() == 0;
	}

private:
	vector<T> v;
};

int Stack()
{
	MyStack<int> s;
	stack<int> s1l;

	s.push(5);
	s.push(8);
	s.push(3);
	s.push(1);
	s.push(10);
	

	while (!s.empty())
	{
		int value = s.top();
		cout << value << endl;
		s.pop();
	}


	return 0;
}