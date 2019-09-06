// BAEK_2468.cpp. 배열돌리기

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, MAP[100][100], SUNK[100][100];
struct pos { int y, x; };
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int bfs()
{
	int spaceNum = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (SUNK[y][x]) continue;
			spaceNum++;
			queue<pos> q;
			q.push({ y, x });
			SUNK[y][x] = 1;
			while (!q.empty())
			{
				int cy = q.front().y, cx = q.front().x; q.pop();
				for (int i = 0; i < 4; i++)
				{
					int ny = cy + dy[i], nx = cx + dx[i];
					if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1 || SUNK[ny][nx]) continue;
					SUNK[ny][nx] = 1;
					q.push({ ny, nx });
				}
			}
		}
	}
	return spaceNum;
}

int main()
{
	cin >> N;
	int maxHeight = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> MAP[y][x];
			maxHeight = maxHeight < MAP[y][x] ? MAP[y][x] : maxHeight;
		}
	}

	int ans = 0;
	for (int rain = 0; rain <= maxHeight - 1; rain++)
	{
		// make sunk to SUNK
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				if (MAP[y][x] <= rain) SUNK[y][x] = 1;

		int tmp = bfs();
		ans = ans < tmp ? tmp : ans;

		// init
		memset(SUNK, 0, sizeof SUNK);
	}

	cout << ans << endl;

	return 0;
}