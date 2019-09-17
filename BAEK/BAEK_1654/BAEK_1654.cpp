// BAEK_1654. 랜선자르기

#include <iostream>

using namespace std;

long long K, N, LANS[10000], MAX, ANS;

void bs(long long s, long long e)
{
	if (s == e)
	{
		int sum = 0;
		for (int i = 0; i < K; i++) sum += (LANS[i] / e);
		if (sum >= N)
		{
			ANS = ANS < e ? e : ANS;
			return;
		}
		return;
	}

	long long middle = (s + e) / 2;
	
	int sum = 0;
	for (int i = 0; i < K; i++) sum += (LANS[i] / middle);

	if (sum >= N)
	{
		ANS = ANS < middle ? middle : ANS;
		if (middle == s) bs(middle + 1, e);
		else bs(middle, e);
	}
	else bs(s, middle);
}

int main()
{
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> LANS[i];
		MAX = MAX < LANS[i] ? LANS[i] : MAX;
	}
	bs(1, MAX);
	cout << ANS << endl;

	return 0;
}
