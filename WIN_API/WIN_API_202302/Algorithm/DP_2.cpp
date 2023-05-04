#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>

using namespace std;

// LIS(Longest Increasing Sequence)
// 부분 증가 수열에서 제일 긴 수열 길이를 찾는다.
//  Seq : 1 2 9 5 8 10

// 부분수열 : 순서는 유지하되, 인접하지 않을 수 있다.
// 1 2 5(0)
// 1 2 9 8(0)
// 2 9 1(X)

// 부분 증가 수열 : 부분 수열이면서 점점 증가되는 순서로 유지되는 수열
// 1 2 5(0)
// 1 2 9 8(X)

vector<int> cache = vector<int>(20, 1);
//vector<int> seq = {0,5,1,2,3,1 };
//vector<int> seq = {3,2,1,7,5,6 }; //LIS(0) = 3
//vector<int> seq = {5,6,7,8,1,2,3 }; //LIS(0) = 4
vector<int> seq = {1,2,3,4,3,4,5,6 }; //LIS(0) = 4
//vector<int> seq = {12,13,6,11,11,11,7,11,8,10 }; //LIS(3) = 4, LIS(0) = 5

// LIS(5) = 1
// LIS(4) = 1 : LIS(4) or LIS(4) + 1;
// LIS(3) = 2
// LIS(2) = 3
// LIS(1) = 3
// LIS(0) = 4

int LIS(int pos)
{
	if (pos == seq.size() - 1)
		return 1;

	int& ref = cache[pos];

	for (int next = pos + 1; next < seq.size(); next++)
	{
		if (seq[pos] <= seq[next])
		{
			ref = max(ref, LIS(next) + 1);
		}
	}

	return ref;
}

int myLis(int pos)
{
	if (pos == seq.size() - 1)
		return 1;

	int& ref = cache[pos];

	int maxLis = 0;
	int index = pos + 1;

	for (int i = pos + 1; i < seq.size(); i++)
	{
		if (maxLis <= myLis(i))
		{
			if (seq[i] <= seq[index])
			{
				index = i;
			}

			maxLis = myLis(i);
		}
	}

	if (seq[pos] < seq[index] || (index - pos > maxLis))
	{
		ref = maxLis + 1;
	}
	else
		ref = maxLis;
}


int main()
{
	int lis = 0;
	int want = 0;
	for (int i = want; i < seq.size(); i++)
	{
		lis = max(lis, LIS(i));
	}

	cout << lis << endl;
	

	return 0;
}