// BAEK_1039 교환

#include <iostream>
#include <cmath>

using namespace std;

int N, K, MAX = -1, LEN = 1;
// N: 1 ~ 1000000, k: 1 ~ 10
// v[N][k] k번째 자리바꿈 결과가 N인 상황이 있었는지
bool v[1000001][11]; 

// a < b ex) 1: 1의 자리, 3: 100의 자리
int swap_num(int num, int a, int b)
{
	int an = num / pow(10, a - 1);
	an %= 10;
	int bn = num / pow(10, b - 1);
	bn %= 10;
	num = num - (an * pow(10, a - 1) + bn * pow(10, b - 1));
	num = num + (an * pow(10, b - 1) + bn * pow(10, a - 1));
	return num;
}

void find_max(int num, int k)
{
	v[num][k] = 1;
	if (k == K+1)
	{
		MAX = MAX < num ? num : MAX;
		return;
	}
	int tmp_num = num;
	for (int i = 1; i <= LEN-1; i++)
	{
		for (int j = i + 1; j <= LEN; j++)
		{
			tmp_num = swap_num(num, i, j);
			// 앞이 0이거나, 해당 시점에서 방문 했었으면 무시
			if (tmp_num / pow(10, LEN-1) < 1 || v[tmp_num][k + 1] == 1) continue;
			find_max(tmp_num, k + 1);
		}
	}
}


int main()
{
	cin >> N >> K;
	int tmp_N = N;

	while ((tmp_N /= 10) > 0) LEN++;

	find_max(N, 1);

	cout << MAX << endl;


	return 0;
}
