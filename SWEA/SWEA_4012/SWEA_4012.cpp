// SWEA 4012. 요리사

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int S[17][17], A[8], B[8], MIN;

void comb(int n, int k, int idx, int depth)
{
	if (depth == k)
	{
		// A가 결정되었으니 B가 자동적으로 결정
		for (int outer = 1, a=0, b=0; outer <= n; outer++)
		{
			if (outer == A[a]) a++;
			else B[b] = outer, b++;
		}

		// A, B가 결정된 순간. 순열로 A, B시너지 계산 후 차이 절대값.
		int sum_a = 0, sum_b = 0;
		for (int i = 0; i < k; i++)
		{
			for (int j = i + 1; j < k; j++)
			{
				sum_a += S[A[i]][A[j]];
				sum_b += S[B[i]][B[j]];
			}
		}
		int diff = abs(sum_a - sum_b);
		MIN = min(MIN, diff);
	}
	else if (idx > n) return;
	else
	{
		A[depth] = idx;
		comb(n, k, idx + 1, depth + 1);
		comb(n, k, idx + 1, depth);
	}
}


int main(int argc, char** argv)
{
	int T;

	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(S, 0, sizeof(S));
		MIN = 123456789;

		int N; cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				int power; cin >> power;
				if (i <= j) S[i][j] += power;
				else S[j][i] += power;
			}
		}
		comb(N, N / 2, 1, 0);
		cout << "#" << t << " " << MIN << endl;
	}
	return 0;
}