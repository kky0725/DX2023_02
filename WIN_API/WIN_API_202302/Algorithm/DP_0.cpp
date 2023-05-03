#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>

using namespace std;

// DP : Dynamic Programing(���� ����)
// ��ǻ�� ������ Dynamic���� �ƹ��� ������ ����.
// => ���־
// ==> ���п��� ����ȭ ������� ���� �˰��� ������ �з�����.

// ĳ�� : 
int cache[100];

// �κ� ���� : 
// f(n - 1) + f(n - 2)

// ���� ���Ἲ : �ܺ��� ���������� ���ؼ� ���� �ٲ�� �ȵȴ�.

// �Ǻ���ġ ����
// f(0) = 1 , f(1) = 1
// f(n) = f(n - 1) + f(n - 2)

vector<vector<int>> vChache;

int Fibonacci(int n, int& count)
{
	//�������� : �ɰ����� �ʴ� �ּ�
	if (n == 0 || n == 1)
		return 1;

	if (n == 2)
		++count;
	
	// �޸����̼�, ĳ��
	if (cache[n] != -1)
		return cache[n];

	// ���ϱ�
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