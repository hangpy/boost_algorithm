// SWEA_2117. 홈 방범 서비스

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int T, N, M, MAP[21][21];
struct pos { int y, x; };

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M;
		// 집 위치 기억해두기
		vector<pos> homes;
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				cin >> MAP[y][x];
				if (MAP[y][x]) homes.push_back({ y,x });
			}
		}

		int max_home = 0;

		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				// 연산낭비를 막기위해 방범서비스 범위 구하기
				int max_k = max(
					max(abs(1 - y) + abs(1 - x), abs(1 - y) + abs(N - x)),
					max(abs(N - y) + abs(1 - x), abs(N - y) + abs(N - x))
				);

				// k는 해당 정점으로부터의 거리 => 계산할 때는 +1 해야함.
				for (int k = 0; k <= max_k; k++)
				{
					int cost = pow(k + 1, 2) + pow(k, 2);
					int benefit = 0;
					for (auto home : homes)
					{
						if (abs(y - home.y) + abs(x - home.x) <= k)
							benefit += M;
					}
					if (benefit >= cost)
						max_home = max(max_home, benefit / M);
				}
			}
		}

		// Asnwer
		cout << "#" << t << " " << max_home << "\n";
	}

	return 0;
}



// 다른사람의 개쩌는 풀이
/*
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);
	int t, hx[400], hy[400], idx, n, m, ans;
	char a[20][20];
	cin >> t;
	for (int tc = 1; tc <= t; tc++) 
	{
		ans = idx = 0;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) 
			{
				cin >> a[i][j];
				if (a[i][j] == '1') hx[idx] = i, hy[idx++] = j;
			}
		}
			
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < n; j++)
			{
				int c[41] = { 0, };

				for (int k = 0; k < idx; k++)
					c[abs(i - hx[k]) + abs(j - hy[k]) + 1]++;

				for (int k = 1; k < 41; k++)
				{
					c[k] += c[k - 1];
					if (c[k] * m - ((k - 1)*(k - 1) + k * k) >= 0)
						ans = c[k] > ans ? c[k] : ans;
				}
			}
		}
		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}
*/