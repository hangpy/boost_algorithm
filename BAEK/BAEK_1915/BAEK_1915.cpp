// BAEK_1915. 가장 큰 정사각형

#include <iostream>
#include <algorithm>

using namespace std;

int N, M, dp[1001][1001];
char map[1001][1001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int n = 0; n < N; n++) cin >> map[n];
		

	int MAX = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (map[y][x] != '1') continue;
			else dp[y + 1][x + 1] = min(dp[y][x], min(dp[y + 1][x], dp[y][x + 1])) + 1;

			MAX = max(MAX, dp[y+1][x+1]);
		}
	}
	cout << MAX * MAX << "\n";
	return 0;
}