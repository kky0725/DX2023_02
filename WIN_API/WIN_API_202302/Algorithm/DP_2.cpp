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

vector<int> cache = vector<int>(6, -1);
vector<int> seq = {0,5,1,2,3,1 };
vector<int> seq1 = {3,2,1,7,5,6 }; //LIS(0) = 3;
vector<int> seq2 = {3,5,1,2,4,1 }; //LIS(0) = 3
int minNum;

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

	if (seq[pos] <= seq[pos + 1])
		ref = LIS(pos+1) + 1;
	else
		ref = LIS(pos+1);
	

	return cache[pos];
}


int main()
{

	cout << LIS(0) << endl;
	

	return 0;
}