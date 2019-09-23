// BAEK_17144. 미세먼지 안녕!

#include <iostream>
#include <cstring>
#define endl "\n"

using namespace std;

// M: row locating air machine, column : only 0
int MAP[50][50], R, C, T, TMP[50][50], M;
// 상 우 하 좌
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void diffuse()
{
	memset(TMP, 0, sizeof TMP);

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if (MAP[y][x] == 0 || MAP[y][x] == -1) continue;
			int airSize = MAP[y][x];
			int airAfter = MAP[y][x] / 5; int cnt = 0;
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i], nx = x + dx[i];
				if (ny < 0 || ny > R - 1 || nx < 0 || nx > C - 1 || MAP[ny][nx] == -1) continue;
				TMP[ny][nx] += airAfter;
				cnt++;
			}
			MAP[y][x] -= airAfter * cnt;
		}
	}
	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++)
			MAP[y][x] += TMP[y][x];
}

void wind()
{
	int up = M, down = M + 1;
	int ud[4] = { 1, 0, 3, 2 }, dd[4]= { 1, 2, 3, 0 };
	// up 먼저
	int y = M, x = 1, d = 0;
	int tmp1 = 0, tmp2 = 0;
	while (1)
	{
		if (y == M && x == 0) break;
		if (y == M && x == C - 1) d++;
		else if (y == 0 && x == C - 1) d++;
		else if (y == 0 && x == 0) d++;
		else;

		int ny = y + dy[ud[d]], nx = x + dx[ud[d]];
		tmp1 = MAP[y][x]; MAP[y][x] = tmp2; tmp2 = tmp1;
		y = ny, x = nx;
	}

	y = M+1, x = 1, d = 0;
	tmp1 = 0, tmp2 = 0;
	while (1)
	{
		if (y == M + 1 && x == 0) break;
		if (y == M+1 && x == C - 1) d++;
		else if (y == R-1 && x == C - 1) d++;
		else if (y == R-1 && x == 0) d++;
		else;

		int ny = y + dy[dd[d]], nx = x + dx[dd[d]];
		tmp1 = MAP[y][x]; MAP[y][x] = tmp2; tmp2 = tmp1;
		y = ny, x = nx;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> R >> C >> T;
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			cin >> MAP[y][x];
			if (MAP[y][x] == -1) if (M == 0) M = y;
		}
	}

	for (int t = 0; t < T; t++)
	{
		// 미세먼지 확산
		diffuse();
		wind();
	}

	int sum = 0;
	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++)
			sum += MAP[y][x];

	cout << sum + 2 << endl;

	return 0;
}
