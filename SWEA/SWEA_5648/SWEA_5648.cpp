
#include <iostream>
#include <cstdio>
using namespace std;

int X[1000];
int Y[1000];
int D[1000];
int K[1000];
int MAP[4001][4001];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;	
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;
		for (int n = 0; n < N; n++)
		{
			int x, y;
			cin >> x >> y;
			X[n] = 2 * x; Y[n] = 2 * y;
			cin >> D[n] >> K[n];
			MAP[2*x + 2000][2*y + 2000] = K[n];
		}

		int ans = 0;
		while(true){
			// 이동
			int cnt(0);
			for (int n = 0; n < N; n++)
			{
				if (K[n] == 0) continue;
				cnt++;
				MAP[X[n] + 2000][Y[n] + 2000] -= K[n];
				X[n] += dx[D[n]];
				Y[n] += dy[D[n]];

				// 경계 넘으면 K[n]을 0으로 초기화
				if (X[n] < -2000 || X[n] > 2000 || Y[n] < -2000 || Y[n] > 2000)
				{
					K[n] = 0;
					continue;
				}
				MAP[X[n] + 2000][Y[n] + 2000] += K[n];
			}
			if (cnt == 0) break;

			// 계산
			for (int n = 0; n < N; n++)
			{
				if (K[n] == 0) continue;

				if (K[n] != MAP[X[n] + 2000][Y[n] + 2000])
				{
					ans += K[n];
					K[n] = 0;
					MAP[X[n] + 2000][Y[n] + 2000] = 0;
				}
			}
		}
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}
