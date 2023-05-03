#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>

using namespace std;

// ENCHANT

// 강화 +1 ~ +3강

// 1 1 2 4 7 13 24
// N강을 하고 싶다. 이 때 강화하는 대로 나오는 모든 경우의 수
// 2강 2가지
// 1 1
// 2

// 3강 4가지
// 1 1 1
// 1 2
// 2 1
// 3

// 4강 7가지
// 1 1 1 1
// 1 2 1
// 1 1 2
// 2 1 1
// 2 2
// 3 1
// 1 3

// 5강 13가지
// 1 1 1 1 1
// 1 1 1 2
// 1 1 2 1
// 1 2 1 1
// 2 1 1 1
// 2 2 1
// 2 1 2
// 1 2 2
// 3 1 1
// 1 3 1
// 1 1 3
// 2 3
// 3 2

//6강 24가지
//111111 : 1개
//11112 : 5개
//1122 : 6개
//222 : 1개
//123 : 6개
//1113 : 4개
//33 : 1개

int cache[101];

int Enchant(int N)
{
	if (N == 0 || N == 1)
		return 1;
	if (N == 2)
		return 2;

	if (cache[N] != -1)
		return cache[N];

	cache[N] = Enchant(N-1) + Enchant(N-2) + Enchant(N-3);

	return cache[N];
}


int main()
{
	for (int i = 0; i< 101; i++)
	{
		cache[i] = -1;
	}

	cout << Enchant(6) << endl;

	return 0;
}