// BAEK_14500. 테트로미노

#include <iostream>
#include <algorithm>

using namespace std;

int N, M, MAP[500][500], V[500][500];

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int dfs(int cy, int cx, int depth)
{
	int result = 0;
	if (depth == 3) return result + MAP[cy][cx];
	else
	{
		V[cy][cx] = 1;

		if (depth == 1)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = i + 1; j < 4; j++)
				{
					int ny1 = cy + dy[i], nx1 = cx + dx[i];
					int ny2 = cy + dy[j], nx2 = cx + dx[j];
					if (V[ny1][nx1] == 0 && V[ny2][nx2] == 0)
					{
						if (ny1 < 0 || ny1 > N - 1 || nx1 < 0 || nx1 > M - 1) continue;
						if (ny2 < 0 || ny2 > N - 1 || nx2 < 0 || nx2 > M - 1) continue;
						result = max(result, MAP[cy][cx] + MAP[ny1][nx1] + MAP[ny2][nx2]);
					}
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];
			if (ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1) continue;
			if (V[ny][nx] == 1) continue;

			result = max(result, MAP[cy][cx] + dfs(ny, nx, depth + 1));
		}
		V[cy][cx] = 0;
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> MAP[y][x];


	int result = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			result = max(result, dfs(y, x, 0));


	cout << result << endl;

	return 0;
}
