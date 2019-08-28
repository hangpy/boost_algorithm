// BAEK_13460. 구슬탈출2

#include <iostream>
#include <queue>

using namespace std;

int N, M, ry, rx, by, bx, hy, hx;
// 실수한 부분 -> 문자열은 10문자를 받아오면 11만큼 선언해야한다.
char MAP[11][11], V[10][10][10][10];
struct state { int cnt, ry, rx, by, bx; };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void move(int &y, int &x, int dir)
{
	while (1)
	{
		y += dy[dir], x += dx[dir];
		if (MAP[y][x] == '#')
		{
			y -= dy[dir], x -= dx[dir];
			break;
		}
		if (MAP[y][x] == 'O') break;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	for (int y = 0; y < N; y++) 
	{
		cin >> MAP[y];
		for (int x = 0; x < M; x++)
		{
			if (MAP[y][x] == 'R') ry = y, rx = x;
			else if (MAP[y][x] == 'B') by = y, bx = x;
			else if (MAP[y][x] == 'O') hy = y, hx = x; 
			else;
		}
	}
	
	queue<state> q; q.push({ 0, ry, rx, by, bx });
	V[ry][rx][by][bx] = 1;

	int ans = -1;
	while (!q.empty())
	{
		state cur = q.front(); q.pop();

		if (cur.cnt > 10) break;
		if (cur.ry == hy && cur.rx == hx)
		{
			ans = cur.cnt;
			break;
		}
		
		for (int i = 0; i < 4; i++)
		{
			int cry = cur.ry, crx = cur.rx;
			int cby = cur.by, cbx = cur.bx;
			int ccnt = cur.cnt;

			move(cry, crx, i); move(cby, cbx, i);

			if (cby == hy && cbx == hx) continue;

			if (cry == cby && crx == cbx)
			{
				switch (i)
				{
				case 0:
					cur.ry < cur.by ? cby++ : cry++; break;
				case 1:
					cur.ry < cur.by ? cry-- : cby--; break;
				case 2:
					cur.rx < cur.bx ? cbx++ : crx++; break;
				case 3:
					cur.rx < cur.bx ? crx-- : cbx--; break;
				}
			}

			if (V[cry][crx][cby][cbx]) continue;

			q.push({ ccnt + 1, cry, crx, cby, cbx });
			V[cry][crx][cby][cbx] = 1;
		}
	}

	cout << ans << endl;

	return 0;
}
