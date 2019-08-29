// BAEK_12100. 2048(EASY)

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, MAP[20][20], CMAP[20][20], V[20][20];
struct info { int cnt, maxValue; };
// 상하좌우
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int ans = 0;

void move(int &y, int &x, int dir, bool &changed, int MAP[20][20])
{
	while (1)
	{
		int ny = y + dy[dir], nx = x + dx[dir];
		if (ny < 0 || ny > N-1 || nx < 0 || nx > N-1 || 
			(MAP[ny][nx] != 0 && MAP[ny][nx] != MAP[y][x])) 
			break;

		if (MAP[ny][nx] == 0)
		{
			swap(MAP[y][x], MAP[ny][nx]);
			y = ny, x = nx;
			//changed = true;
			continue;
		}

		if (MAP[ny][nx] == MAP[y][x])
		{
			if (V[ny][nx]) break;
			MAP[ny][nx] += MAP[y][x];
			V[ny][nx] = 1;
			MAP[y][x] = 0;
			ans = ans < MAP[ny][nx] ? MAP[ny][nx] : ans;
			changed = true;
			break;
		}
	}
}

bool incline(int dir, int MAP[20][20])
{
	memset(V, 0, sizeof V);
	bool changed = false;
	if (dir == 0) // 상
	{
		for (int x = 0; x < N; x++)
		{
			for (int y = 1; y < N; y++)
			{
				if (MAP[y][x] == 0) continue;
				int cy = y, cx = x;
				move(cy, cx, dir, changed, MAP);
			}
		}
	}
	else if (dir == 1) // 하
	{
		for (int x = 0; x < N; x++)
		{
			for (int y = N - 2; y >= 0; y--)
			{
				if (MAP[y][x] == 0) continue;
				int cy = y, cx = x;
				move(cy, cx, dir, changed, MAP);
			}
		}
	}
	else if (dir == 2) // 좌
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 1; x < N; x++)
			{
				if (MAP[y][x] == 0) continue;
				int cy = y, cx = x;
				move(cy, cx, dir, changed, MAP);
			}
		}
	}
	else // dir == 3 우
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = N - 2; x >= 0; x--)
			{
				if (MAP[y][x] == 0) continue;
				int cy = y, cx = x;
				move(cy, cx, dir, changed, MAP);
			}
		}
	}
	return changed;
}

void dfs(int depth)
{
	if (depth == 5) return;
	
	int BACKUP[20][20];
	memcpy(BACKUP, MAP, sizeof MAP);

	for (int i = 0; i < 4; i++)
	{
		if (incline(i, MAP)) dfs(depth + 1);
		memcpy(MAP, BACKUP, sizeof MAP);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> MAP[y][x];
			ans = ans < MAP[y][x] ? MAP[y][x] : ans;
		}
	}
	dfs(0);
	cout << ans << endl;

	return 0;
}
