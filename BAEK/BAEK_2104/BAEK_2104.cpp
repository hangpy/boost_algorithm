// BAEK_2104. 부분배열 고르기

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, A[100000], ANS;


ll dq(int l, int r)
{
	ll ans = 0;

	if (l == r) return A[l] * A[l];
	
	ll m = (l + r) / 2;

	ans = max(dq(l, m), dq(m + 1, r));

	ll MIN = A[m], s = m, e = m;
	ll sum = MIN;
	while (s > l || e < r)
	{
		int p = s > l ? min(A[s - 1], MIN) : -1;
		int q = e < r ? min(A[e + 1], MIN) : -1;
		if (q >= p)
		{
			e++;
			MIN = q;
			sum += A[e];
		}
		else
		{
			s--;
			MIN = p;
			sum += A[s];
		}
		ans = max(ans, MIN * sum);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	cout << dq(0, N - 1) << endl;

	return 0;
}
