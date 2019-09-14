// BAEK_2850. 나무 자르기

#include <iostream>
#include <algorithm>

using namespace std;

int N, M, trees[1000000];
long long ANS;
int MAX;

void bs(int s, int e)
{
	int middle = (s + e) / 2;
	if (middle == s) return;
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		if(middle < trees[i])
		sum += (trees[i] - middle);
	}

	if (sum >= M)
	{
		ANS = ANS < middle ? middle : ANS;
		bs(middle, e);
	}
	else bs(s, middle);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> trees[i];
		if (trees[i] > MAX) MAX = trees[i];
	}
	bs(0, MAX);
	cout << ANS << endl;
	return 0;
}