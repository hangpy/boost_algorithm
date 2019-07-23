
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

struct BC { int y, x, c, p; };
struct pos { int y, x; };
int MA[100], MB[100], map[9][11][11], v[11][11];
BC BCS[9];
//				X, 위, 오, 아, 왼
int drow[5] = { 0, -1, 0, 1, 0 };
int dcol[5] = { 0, 0, 1, 0, -1 };

using namespace std;

void bfs(int bc, int y, int x, int c, int p)
{
	queue<pos> q;
	q.push({ y, x });
	map[bc][y][x] = 1;
	map[bc][y][x] = p;
	while (!q.empty())
	{
		pos cur = q.front();
		q.pop();
		int y = cur.y;
		int x = cur.x;
		map[bc][y][x] = p;

		for (int i = 1; i <= 5; i++)
		{
			int ny = y + drow[i];
			int nx = x + dcol[i];
			if (v[y][x] == c || ny < 1 || ny > 10 || nx < 1 || nx >10
				|| v[ny][nx] > 0) continue;
			q.push({ ny, nx });
			v[ny][nx] = v[y][x] + 1;
			
		}
	}
	memset(v, 0, sizeof(v));
}


int main(int argc, char** argv)
{
	int T;

	freopen("sample_input.txt", "r", stdin);
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		// 시간, BC개수
		int M, A;
		cin >> M >> A;
		for (int m = 0; m < M; m++) cin >> MA[m];
		for (int m = 0; m < M; m++) cin >> MB[m];
		for (int a = 1; a <= A; a++)
		{
			int x, y, c, p;
			cin >> x >> y >> c >> p;
			BCS[a] = { y, x, c, p };
			bfs(a, y, x, c, p);
		}

		


		int max_sum = 0;
		int a_y = 1, a_x = 1, b_y = 10, b_x = 10;

		for (int m = 0; m <= M; m++)
		{
			int tmp_sum = 0;
			for (int f_bc = 1; f_bc <= A; f_bc++)
			{
				for (int s_bc = 1; s_bc <= A; s_bc++)
				{
					int s = 0;
					if (f_bc == s_bc) s = max(map[f_bc][a_y][a_x], map[f_bc][b_y][b_x]);
					else s = map[f_bc][a_y][a_x] + map[s_bc][b_y][b_x];
					
					tmp_sum = max(tmp_sum, s);
				}
			}
			max_sum += tmp_sum;
			if (m == M) break;
			a_y += drow[MA[m]], a_x += dcol[MA[m]];
			b_y += drow[MB[m]], b_x += dcol[MB[m]];
		}
		cout << "#" << t << " " << max_sum << endl;
		memset(map, 0, sizeof(map));
	}
	return 0;
}

/*
1
20 3
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
4 4 1 100
7 10 3 40
6 3 2 70
*/

// validation for dfs -> success
		/*for (int a = 1; a <= A; a++)
		{
			for (int i = 1; i <= 10; i++)
			{
				for (int j = 1; j <= 10; j++)
				{
					cout << map[a][i][j] << " ";
				}
				cout << endl;
			}
			cout << "==============" << endl;
		}*/

		// input validation -> success
		/*cout << M << " " << A << endl;
		for (int m = 0; m < M; m++) cout << MA[m] << " ";
		cout << endl;
		for (int m = 0; m < M; m++) cout << MB[m] << " ";
		cout << endl;
		for (int a = 1; a <= A; a++)
		{
			BC tmp = BCS[a];
			cout << tmp.x << " " << tmp.y << " " << tmp.c << " " << tmp.p << endl;
		}*/