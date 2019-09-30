// BAEK_17143. 낚시왕

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

struct shark
{
	int s, d, z;
};
int R, C, M;
int dy[5] = {0, -1, 1, 0, 0 };
int dx[5] = {0, 0, 0, 1, -1 };
int chdir[5] = { 0, 2, 1, 4, 3 };
vector<shark> MAP[101][101];
vector<shark> TMP[101][101];

bool cmp(shark &t, shark &u)
{
	if (t.z > u.z) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		// row,col,speed,dir,size
		int r=0, c=0, s=0, d=0, z=0;

		cin >> r >> c >> s >> d >> z;
		MAP[r][c].push_back({ s, d, z });
	}

	int t = 1, ans = 0;
	while (t <= C)
	{

		// 낚기
		for (int y = 1; y <= R; y++)
		{
			if (MAP[y][t].size() > 0)
			{
				ans += MAP[y][t][0].z;
				MAP[y][t].clear();
				break;
			}
		}

		// 상어이동
		for (int y = 1; y <= R; y++)
		{
			for (int x = 1; x <= C; x++)
			{
				if (MAP[y][x].size() == 0) continue;

				shark nowShark = MAP[y][x][0];
				int s = nowShark.s;
				int d = nowShark.d;
				int z = nowShark.z;
				MAP[y][x].clear();

				int py = y;
				int px = x;

				if (d == 1 && py == 1) d = chdir[d];
				else if (d == 2 && py == R) d = chdir[d];
				else if (d == 3 && px == C) d = chdir[d];
				else if(d == 4 && px == 1) d = chdir[d];
				else;

				// 이동
				if (d == 1 || d == 2) s %= ((R - 1) * 2);
				if (d == 3 || d == 4) s %= ((C - 1) * 2);

				int ss = 0;
				while (ss < s)
				{
					int ny = py + dy[d], nx = px + dx[d];
					py = ny, px = nx;
					if ((d == 1 || d == 2) && (py == 1 || py == R)) d = chdir[d];
					if ((d == 3 || d == 4) && (px == 1 || px == C)) d = chdir[d];
					ss++;
				}
				// 이부분 지우면 런타임 에러 없어짐
				TMP[py][px].push_back({ s, d, z });
			}
		}
		
		// 잡아먹기
		for (int y = 1; y <= R; y++)
		{
			for (int x = 1; x <= C; x++)
			{
				if (TMP[y][x].size() == 0) continue;
				
				if(TMP[y][x].size() > 1) sort(TMP[y][x].begin(), TMP[y][x].end(), cmp);
				
				MAP[y][x].push_back(TMP[y][x][0]);
				TMP[y][x].clear();
			}
		}
		t++;
	}

	cout << ans << endl;

	return 0;
}