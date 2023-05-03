#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>

using namespace std;

// DP : Dynamic Programing(동적 계산법)
// 컴퓨터 공학의 Dynamic과는 아무련 관련이 없다.
// => 멋있어서
// ==> 수학에서 최적화 기법으로 나온 알고리즘 디자인 패러다임.

// 캐싱 : 
int cache[100];

// 부분 문제 : 
// f(n - 1) + f(n - 2)

// 참조 무결성 : 외부의 전역변수에 의해서 값이 바뀌면 안된다.

// 피보나치 수열
// f(0) = 1 , f(1) = 1
// f(n) = f(n - 1) + f(n - 2)

vector<vector<int>> vChache;

int Fibonacci(int n, int& count)
{
	//기저사항 : 쪼개지지 않는 최소
	if (n == 0 || n == 1)
		return 1;

	if (n == 2)
		++count;
	
	// 메모리제이션, 캐싱
	if (cache[n] != -1)
		return cache[n];

	// 구하기
	cache[n] = Fibonacci(n - 1, count) + Fibonacci(n - 2, count);

	return cache[n];
}

int nCr(int n, int r)
{
	if (n == 1 || r == 0)
		return 1;


	if (vChache[n][r] != -1)
		return vChache[n][r];

	vChache[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);

	return vChache[n][r];
}

int main()
{
	//int count = 0;

	//for (int i = 0; i < 100; i++)
	//{
	//	chache[i] = -1;
	//}

	//__int64 start = GetTickCount64();
	//cout << Fibonacci(50, count) << endl;
	//cout << count << endl;
	//
	//__int64 end = GetTickCount64();

	//cout << end - start << "ms" << endl;

	vChache.resize(101, vector<int>(101, -1));
	cout << nCr(99, 5) << endl;


	return 0;
}