// BAEK_1654. 랜선자르기

#include <iostream>

using namespace std;

int K, N, LANS[10000], MAX, ANS;

void bs(int s, int e)
{
	if (s > e) return;

	int m = s + (e - s) / 2;

	int sum = 0;
	for (int i = 0; i < K; i++) sum += (LANS[i] / m);

	if (sum >= N)
	{
		ANS = ANS < m ? m : ANS;
		bs(m + 1, e);
	}
	else bs(s, m - 1);
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




//long long a = 1, b = MAX;
//int ans = 0;
//while (a <= b)
//{
//	long long m = (a + b) / 2; int tsum = 0;
//	for (int i = 0; i < K; i++) tsum += LANS[i] / m;
//	if (tsum >= N) a = m + 1, ans = ans < m ? m : ans;
//	else b = m - 1;
//}