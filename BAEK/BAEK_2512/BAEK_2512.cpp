// BAEK_2512. 예산

#include <iostream>

using namespace std;

long long money[10000], N, M, MAX, ANS;

void bs(int l, int r)
{
	if (l > r) return;

	long long m = (l + r) / 2;

	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (m < money[i]) sum += m;
		else sum += money[i];
	}
	if (sum <= M)
	{
		ANS = ANS < m ? m : ANS;
		bs(m + 1, r);
	}
	else bs(l, m - 1);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> money[i];
		MAX = MAX < money[i] ? money[i] : MAX;
	}
	cin >> M;

	bs(1, MAX);
	cout << ANS << endl;

	return 0;
}