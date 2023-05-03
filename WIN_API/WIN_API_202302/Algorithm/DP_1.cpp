#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>

using namespace std;

// ENCHANT

// ��ȭ +1 ~ +3��

// 1 1 2 4 7 13 24
// N���� �ϰ� �ʹ�. �� �� ��ȭ�ϴ� ��� ������ ��� ����� ��
// 2�� 2����
// 1 1
// 2

// 3�� 4����
// 1 1 1
// 1 2
// 2 1
// 3

// 4�� 7����
// 1 1 1 1
// 1 2 1
// 1 1 2
// 2 1 1
// 2 2
// 3 1
// 1 3

// 5�� 13����
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

//6�� 24����
//111111 : 1��
//11112 : 5��
//1122 : 6��
//222 : 1��
//123 : 6��
//1113 : 4��
//33 : 1��

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