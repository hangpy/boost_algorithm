// BAEK_10816. 숫자 카드 2

#include <iostream>
#include <algorithm>
#define BASE 10000000

using namespace std;

int N, M, A[500000], B[500000];
int dp[20000001]; // -10,000,000 ~ 10,000,000

// 꼭 이거 안써도 됨.
//int bs(int l, int r, int target)
//{
//	if (l > r) return 0;
//	int m = (l + r) / 2;
//
//	if (A[m] == target) return dp[target + BASE];
//	else if (A[m] < target) bs(m+1, r, target);
//	else bs(l, m - 1, target);
//}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int n; cin >> n;
		if (dp[n + BASE]) dp[n + BASE]++;
		else dp[n + BASE] = 1, A[cnt++] = n;
	}
	sort(A, A + cnt);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int target; cin >> target;
		cout << dp[target + BASE] << " ";
	}
	return 0;
}

