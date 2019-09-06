// BAEK_17135. 캐슬 디펜스

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, D, MAP[15][15], CMAP[15][15], V[15][15], CNT, KILL;
int dy[3] = { 0, -1, 0 };
int dx[3] = { -1, 0, 1 };
struct pos { int y, x, d; };
struct loc { int y, x; };

void bfs(int &cnt, int &kill, pos cur, vector<loc> &tmpv)
{
	queue<pos> q; q.push(cur);

	while (!q.empty())
	{
		bool toBreak = false;
		int cy = q.front().y, cx = q.front().x, cd = q.front().d; q.pop();
		for (int i = 0; i < 3; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];
			if (ny == N || ny < 0 || nx < 0 || nx > M - 1 || cd == D || V[ny][nx] == 1) continue;
			if (CMAP[ny][nx])
			{
				tmpv.push_back({ ny, nx });
				toBreak = true; break;
			}
			else q.push({ ny, nx, cd + 1 });
		}
		if (toBreak) break;
	}
	memset(V, 0, sizeof V);
	
}

int main()
{
	cin >> N >> M >> D;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> MAP[y][x];
			if (MAP[y][x]) CNT++;
		}
	}

	// MAP의 N행에 궁수가 있는 것.
	int ans = 0;
	vector<int> v(M, 1);
	for (int i = 0; i < 3; i++) v[i] = 0;
	do
	{
		int kill = 0, cnt = CNT; 
		memcpy(CMAP, MAP, sizeof MAP);
		int archarLoc[3] = { 0, }; // (N, 0~M-1)
		for (int i = 0, k = 0; i < M; i++)
			if (!v[i]) archarLoc[k++] = i;
		
		while (cnt > 0)
		{
			vector<loc> tmpv;
			for (int i = 0; i < 3; i++)
				bfs(cnt, kill, { N, archarLoc[i] }, tmpv);
			
			for (int i = 0; i < tmpv.size(); i++)
			{
				int y = tmpv[i].y, x = tmpv[i].x;
				if (CMAP[y][x]) cnt--, kill++, CMAP[y][x] = 0;
			}
			
			for (int y = N - 1; y >= 0; y--)
			{
				for (int x = 0; x < M; x++)
				{
					if (!CMAP[y][x]) continue;
					if (y == N - 1 && CMAP[y][x]) cnt--, CMAP[y][x] = 0;
					if (y < N - 1 && CMAP[y][x]) CMAP[y + 1][x] = 1, CMAP[y][x] = 0;
				}
			}
		}
		ans = ans < kill ? kill : ans;
	} while (next_permutation(v.begin(), v.end()));
	
	cout << ans << endl;

	return 0;
}