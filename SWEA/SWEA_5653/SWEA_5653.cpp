#include <iostream>
#include <cstring>
#include <queue>
#define BASE 150

using namespace std;

int N, M, K;
struct CELL {
	int y, x;
	int restLife, toActive;
};
int MAP[50 + BASE*2][50 + BASE*2];
// 상하좌우
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main(int argc, char** argv)
{
	int T, cnt = 0;
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		cin >> N >> M >> K;

		queue<CELL> q[11];
		int cnt = 0;

		for (int y = BASE; y < BASE + N; y++)
		{
			for (int x = BASE; x < BASE + M; x++)
			{
				cin >> MAP[y][x];
				if (MAP[y][x]) 
				{
					q[MAP[y][x]].push({ y, x, MAP[y][x], MAP[y][x] });
					cnt++;
				}
			}
		}

		while (K > 0)
		{
			for (int vital = 10; vital >= 1; vital--)
			{
				queue<CELL> &tq = q[vital];
				int len = tq.size();
				for (int i = 0; i < len; i++)
				{
					// 초기상태 값
					CELL cell = tq.front(); tq.pop();
					int cy = cell.y, cx = cell.x, restLife = cell.restLife, toActive = cell.toActive;
					cnt--;

					// 비활성
					if (toActive > 0)
					{
						tq.push({ cy, cx, restLife, toActive - 1 }), cnt++;
					}
					// 활성 후 첫 번식
					else if (toActive == 0 && restLife == MAP[cy][cx])
					{
						for (int i = 0; i < 4; i++)
						{
							int ny = cy + dy[i], nx = cx + dx[i];
							if (MAP[ny][nx]) continue;
							MAP[ny][nx] = MAP[cy][cx];
							tq.push({ ny, nx, restLife, restLife }); cnt++;
						}
						if (restLife - 1 > 0)
							tq.push({ cy, cx, restLife - 1, 0 }), cnt++;
					}
					// 첫 번식 이후 활성상태
					else
					{
						if (restLife - 1 > 0)
							tq.push({ cy, cx, restLife - 1, 0 }), cnt++;
					}
				}
			}
			K--;
		}
		cout << "#" << t << " " << cnt << "\n";
		memset(MAP, 0, sizeof(MAP));
	}
	return 0;
}