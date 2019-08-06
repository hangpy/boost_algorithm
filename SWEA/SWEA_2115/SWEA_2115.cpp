// SWEA_2115. 벌꿀채취
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int map[10][10], dp[10][10], boxs[5];

int calc(vector<int>& v, int c, int idx, int sum, int val)
{
	if (sum > c) return 0;
	if (idx == v.size()) return val;
	
	return max(calc(v, c, idx + 1, sum + v[idx], val + pow(v[idx], 2)), calc(v, c, idx + 1, sum, val));
}

int get_max(int y, int x, int c, int n, int m)
{
	vector<int> v;
	for (int i = x; i < x + m; i++)
		v.push_back(map[y][i]);
	return calc(v, c, 0, 0, 0);
}

void make_dp(int n, int m, int c)
{
	memset(dp, 0, sizeof(dp));
	for (int row = 0; row < n; row++)
		for (int i = 0; i < n - m + 1; i++)
			dp[row][i] = get_max(row, i, c, n, m);
}

int dfs(int y, int x, int n, int m)
{
	int ans = 0;
	
	for (int i = x + m; i < n; i++)
		ans = max(ans, dp[y][x] + dp[y][i]);
	
	for (int row = y + 1; row < n; row++)
		for (int col = 0; col < n; col++)
			ans = max(ans, dp[y][x] + dp[row][col]);

	return ans;
}


int main()
{
	int T = 0;
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(map, 0, sizeof(map));

		int N, M, C;
		cin >> N >> M >> C;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> map[y][x];
		
		make_dp(N, M, C);

		int MAX = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N - M + 1; j++)
				MAX = max(MAX, dfs(i, j, N, M));


		cout << "#" << t << " " << MAX << "\n";
	}

	return 0;
}
