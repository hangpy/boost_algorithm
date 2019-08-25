// BAEK_13458. 시험감독

#include <iostream>

using namespace std;

int N, A[1000000], B, C;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> B >> C;

	long long min = 0;
	
	for (int i = 0; i < N; i++)
	{
		min++;
		A[i] -= B;
		if (A[i] > 0)
		{
			int a = A[i] / C;
			int b = A[i] % C;
			min += a;
			if (b != 0) min++;
		}
	}

	cout << min << endl;

	return 0;
}